/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:20:07 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 18:17:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "game.h"
#include "game_scenario.h"
#include "scenes.h"
#include "entity.h"
#include "physics.h"
#include <stdio.h>

/**
 * Loop update logic of the game
 * @param game_data Game data
 */
void ft_game_update(t_game_data *game_data)
{
	t_entity	*entity;
	t_entity	*tmp;

	ft_game_controls(game_data);  // Handle player movements
	
	// Handle enemy logic
	game_enemy_logic(game_data);

	// Compute future position
	entity = game_data->entities;
	while (entity)
	{
		entity->ft_update_physics(entity, game_data);
		entity = entity->next;
	}

	// Handle collisions between entities
	entity = game_data->entities;
	while (entity)
	{
		tmp = entity->next;
		if (entity->ft_handle_collisions)
			entity->ft_handle_collisions(entity, game_data);
		entity = tmp;
	}
	entity = game_data->entities
		;
	// Delete dead body
	while (entity)
	{
		t_entity	*tmp = entity->next;
		switch (entity->type)
		{
			case ENTITY_ENEMY_SHIP:
			{
				t_entity_enemy_ship	*e_ship = (t_entity_enemy_ship *)entity->data;
				if (e_ship->health <= 0)
				{
					entity->ft_unrender(entity, game_data);
					entity_delone(entity);
				}
				break;
			}
			case ENTITY_PLAYER_SHIP:
			{
				t_entity_player_ship *p_ship = (t_entity_player_ship *)entity->data;
				if (p_ship->health <= 0)
				{
					last_game_score = p_ship->score;
					state = STATE_GAME_OVER;
					loop = false;
				}
				break;
			}
			case ENTITY_PLAYER_LASER:
			{
				t_entity_player_laser *p_laser = (t_entity_player_laser *)entity->data;
				if (p_laser->perforation <= 0)
				{
					entity->ft_unrender(entity, game_data);
					entity_delone(entity);
				}
				break;
			}
			case ENTITY_ENEMY_LASER:
			{
				t_entity_enemy_laser *e_laser = (t_entity_enemy_laser *)entity->data;
				if (e_laser->perforation <= 0)
				{
					entity->ft_unrender(entity, game_data);
					entity_delone(entity);
				}
				break;
			}
			default:
				break;
		}
		entity = tmp;
	}
	// Delete lasers and ennemies out of bounds
	entity = game_data->entities;
	while (entity)
	{
		t_entity	*tmp = entity->next;
		switch (entity->type)
		{
			case ENTITY_PLAYER_LASER:
			case ENTITY_ENEMY_LASER:
				if (entity->y > SCENE_HEIGHT + 1 || entity->next_y < 0 || entity->next_y > SCENE_HEIGHT + 1 || entity->next_x < 0 || entity->next_x > SCENE_WIDTH)
				{
					entity->ft_unrender(entity, game_data);
					entity_delone(entity);
				}
				break;
			case ENTITY_ENEMY_SHIP:
				if (entity->y > SCENE_HEIGHT + 1 || entity->next_y > SCENE_HEIGHT + 1 || entity->next_x < 0 || entity->next_x > SCENE_WIDTH)
				{
					// TODO: Handle player score
					t_entity	*p_ship = entity_find_by_id(game_data->entities, 0);
					((t_entity_player_ship *)p_ship->data)->score--;
					entity->ft_unrender(entity, game_data);
					entity_delone(entity);
				}
				break;
		}
		entity = tmp;
	}
}

void ft_game_controls(t_game_data *game_data)
{
	t_entity *entity;
	t_entity_player_ship *player_ship;
	t_entity *laser;

	// Get player entity
	entity = entity_find_by_id(game_data->entities, 0);
	if (!entity)
		return ;
	// Prevent velocity from going below 0
	if (entity->velocity <= 0)
	{
		entity->acceleration = 0;
		entity->velocity = 0;
	}
	else
		entity->acceleration = -2;
	player_ship = (t_entity_player_ship *) entity->data;
	// Handle player movements
	switch (player_ship->input) {
		case PLAYER_INPUT_MOVE_UP:
			entity->angle = 3 * M_PI_2;
			entity->velocity = MIN(0.3, entity->velocity + 0.2);
			break;
		case PLAYER_INPUT_MOVE_DOWN:
			entity->angle = M_PI_2;
			entity->velocity = MIN(0.3, entity->velocity + 0.2);
			break;
		case PLAYER_INPUT_MOVE_LEFT:
			entity->angle = M_PI;
			entity->velocity = MIN(0.6, entity->velocity + 0.2);
			break;
		case PLAYER_INPUT_MOVE_RIGHT:
			entity->angle = 0;
			entity->velocity = MIN(0.6, entity->velocity + 0.2);
			break;
		case PLAYER_INPUT_FIRE:
			// Cooldown
			if (player_ship->cooldown > game_data->frame_time)
				break;
			laser = init_entity(ENTITY_PLAYER_LASER, game_data);
			if (!laser)
				return ;
			laser->y = entity->y - 1;
			laser->x = entity->x;
			laser->angle = 3 * M_PI_2;
			laser->velocity = 1;
			((t_entity_player_laser *) laser->data)->damage = PLAYER_LASER_DAMAGE(game_data->scenario);
			((t_entity_player_laser *) laser->data)->perforation = PLAYER_LASER_PERFORATION(game_data->scenario);
			((t_entity_player_laser *) laser->data)->player_id = entity->id;
			entity_add_back(game_data->entities, laser);
			player_ship->cooldown = game_data->frame_time + 300 * NS_PER_MS;
			break;
		default:
			break;
	}
	player_ship->input = PLAYER_INPUT_NONE;
}

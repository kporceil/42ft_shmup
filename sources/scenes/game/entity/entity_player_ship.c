/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_player_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:04:26 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:12:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>

#include "game.h"
#include "game_scenario.h"
#include "entity.h"
#include "physics.h"

void	*init_entity_player_ship(t_game_data *game_data)
{
	t_entity_player_ship	*entity;

	entity = malloc(sizeof(t_entity_player_ship));
	if (!entity)
		return (NULL);
	entity->type = PLAYER_KEYBOARD;
	entity->score = 0;
	entity->health = PLAYER_HP(game_data->scenario);
	entity->power_up = false;
	entity->icon = 'G';
	return ((void *)entity);
}

void	update_entity_player_ship_physics(t_entity *entity, t_game_data *game_data)
{
	// Update velocity and position
	entity->velocity = ft_accelerate(entity->velocity, entity->acceleration, game_data->delta_time);
	entity->next_y = entity->y;
	entity->next_x = entity->x;
	ft_move(&entity->next_y, &entity->next_x, entity->velocity, entity->angle, game_data->delta_time);
	// Constrain position to the scene
	if (entity->next_y < 0)
		entity->next_y = 0;
	if (entity->next_y > SCENE_HEIGHT)
		entity->next_y = SCENE_HEIGHT;
	if (entity->next_x < 0)
		entity->next_x = 0;
	if (entity->next_x > SCENE_WIDTH)
		entity->next_x = SCENE_WIDTH;
}

void	handle_entity_player_ship_collisions(t_entity *entity, t_game_data *game_data)
{
	t_entity				*entity2;
	t_entity_player_ship	*p_ship = (t_entity_player_ship *) entity->data;

	entity2 = game_data->entities;
	while (entity2)
	{
		switch (entity2->type)
		{
			case ENTITY_ENEMY_LASER:
				if (ft_entities_collide(entity, entity2, 0.5))
				{
					t_entity_enemy_laser *e_laser = (t_entity_enemy_laser *) entity2->data;
					p_ship->health -= e_laser->damage;
					e_laser->perforation--;
				}
				break;
			case ENTITY_ENEMY_SHIP:
				if (ft_entities_collide(entity, entity2, 0.8))
				{
					p_ship->health -= 100;
				}
				break;
			default:
				break;
		}
		entity2 = entity2->next;
	}
}

void	render_entity_player_ship(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x || game_data->resized)
	{
		entity->y = entity->next_y;
		entity->x = entity->next_x;
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ((t_entity_player_ship *) entity->data)->icon);
	}
	mvprintw(getmaxy(stdscr) - 2, 1, "                      ");
	mvprintw(getmaxy(stdscr) - 2, 1, "Health : %d", ((t_entity_player_ship *)entity->data)->health);
}

void	unrender_entity_player_ship(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x)
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ' ');
}

void	del_entity_player_ship(t_entity_player_ship *data)
{
	free(data);
}

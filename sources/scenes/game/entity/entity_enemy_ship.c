/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:22:16 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:27:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>

#include "game.h"
#include "game_scenario.h"
#include "entity.h"
#include "physics.h"

void	*init_entity_enemy_ship(t_game_data *game_data)
{
	t_entity_enemy_ship	*entity;

	entity = malloc(sizeof(t_entity_enemy_ship));
	if (!entity)
		return (NULL);
	entity->health = 100;
	entity->cooldown = 0;
	entity->icon = 'M';
	return ((void *)entity);
}

void	update_entity_enemy_ship_physics(t_entity *entity, t_game_data *game_data)
{
	// Update velocity and position
	entity->velocity = ft_accelerate(entity->velocity, entity->acceleration, game_data->delta_time);
	entity->next_y = entity->y;
	entity->next_x = entity->x;
	ft_move(&entity->next_y, &entity->next_x, entity->velocity, entity->angle, game_data->delta_time);
}

void	handle_entity_enemy_ship_collisions(t_entity *entity, t_game_data *game_data)
{
	t_entity	*entity2;
	t_entity_enemy_ship		*e_ship = (t_entity_enemy_ship *)entity->data;

	entity2 = game_data->entities;
	while (entity2)
	{
		switch (entity2->type)
		{
			case ENTITY_PLAYER_LASER:
				if (ft_entities_collide(entity, entity2, 0.8))
				{
					t_entity_player_laser	*p_laser = (t_entity_player_laser *)entity2->data;
					e_ship->health -= p_laser->damage;
					p_laser->perforation--;
					t_entity *p_ship = entity_find_by_id(game_data->entities, p_laser->player_id);
					if (p_ship && e_ship->health > 0)
						((t_entity_player_ship *)p_ship->data)->score += SCORE_REWARD(game_data->scenario);
					else if (p_ship)
						((t_entity_player_ship *)p_ship->data)->score += (SCORE_REWARD(game_data->scenario) * 2);
				}
			case ENTITY_PLAYER_SHIP:
				if (ft_entities_collide(entity, entity2, 0.8))
				{
					e_ship->health -= 100;
				}
				break;
			default:
				break;
		}
		entity2 = entity2->next;
	}
}

void	render_entity_enemy_ship(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x || game_data->resized)
	{
		entity->y = entity->next_y;
		entity->x = entity->next_x;
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ((t_entity_enemy_ship *) entity->data)->icon);
	}
}

void	unrender_entity_enemy_ship(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x)
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ' ');
}

void	del_entity_enemy_ship(t_entity_enemy_ship *entity)
{
	free(entity);
}

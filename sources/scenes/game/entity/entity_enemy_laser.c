/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_laser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:19:17 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:22:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>

#include "game.h"
#include "game_scenario.h"
#include "entity.h"
#include "physics.h"

void	*init_entity_enemy_laser(t_game_data *game_data)
{
	t_entity_enemy_laser	*entity;

	entity = malloc(sizeof(t_entity_enemy_laser));
	if (!entity)
		return (NULL);
	entity->perforation = 1;
	entity->damage = 50;
	entity->color = COLOR_SET_RED;
	entity->icon = '|';
	return ((void *)entity);
}

void	update_entity_enemy_laser_physics(t_entity *entity, t_game_data *game_data)
{
	// Update velocity and position
	entity->velocity = ft_accelerate(entity->velocity, entity->acceleration, game_data->delta_time);
	entity->next_y = entity->y;
	entity->next_x = entity->x;
	ft_move(&entity->next_y, &entity->next_x, entity->velocity, entity->angle, game_data->delta_time);
}

void	handle_entity_enemy_laser_collisions(t_entity *entity, t_game_data *game_data)
{
	t_entity	*entity2;

	entity2 = game_data->entities;
	while (entity && entity2)
	{
		switch (entity2->type)
		{
			case ENTITY_PLAYER_SHIP:
				if (ft_entities_collide(entity, entity2))
				{
					((t_entity_player_ship *)entity2->data)->health -= ((t_entity_enemy_laser *)entity->data)->damage;
					entity_delone(entity);
					entity = NULL;
				}
				break;
			default:
				break;
		}
		entity2 = entity2->next;
	}
}

void	render_entity_enemy_laser(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x || game_data->resized)
	{
		entity->y = entity->next_y;
		entity->x = entity->next_x;
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ((t_entity_enemy_laser *) entity->data)->icon);
	}
}

void	unrender_entity_enemy_laser(t_entity *entity, t_game_data *game_data)
{
	if (entity->next_y != entity->y || entity->next_x != entity->x)
		mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ' ');
}

void	del_entity_enemy_laser(t_entity_enemy_laser *entity)
{
	free(entity);
}

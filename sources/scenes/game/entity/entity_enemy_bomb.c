/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_bomb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:16:12 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:19:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>

#include "game.h"
#include "game_scenario.h"
#include "entity.h"
#include "physics.h"
#include "render.h"

void	*init_entity_enemy_bomb(t_game_data *game_data)
{
	t_entity_enemy_bomb	*entity;

	entity = malloc(sizeof(t_entity_enemy_bomb));
	if (!entity)
		return (NULL);
	entity->damage = 500;
	entity->radius = 5;
	entity->health = 1;
	entity->icon = 'B';
	entity->color = RED_ON_MAGENTA;
	return ((void *)entity);
}

void	update_entity_enemy_bomb_physics(t_entity *entity, t_game_data *game_data)
{
	// Update velocity and position
	entity->velocity = ft_accelerate(entity->velocity, entity->acceleration, game_data->delta_time);
	entity->next_y = entity->y;
	entity->next_x = entity->x;
	ft_move(&entity->next_y, &entity->next_x, entity->velocity, entity->angle, game_data->delta_time);
}

void	render_entity_enemy_bomb(t_entity *entity, t_game_data *game_data)
{
	entity->y = entity->next_y;
	entity->x = entity->next_x;
	attron(COLOR_PAIR(((t_entity_enemy_bomb *) entity->data)->color));
	mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ((t_entity_enemy_bomb *) entity->data)->icon);
	attroff(COLOR_PAIR(((t_entity_enemy_bomb *) entity->data)->color));
}

void	unrender_entity_enemy_bomb(t_entity *entity, t_game_data *game_data)
{
	mvaddch(game_data->scene_y_origin + entity->y, game_data->scene_x_origin + entity->x, ' ');
}

void	del_entity_enemy_bomb(t_entity_enemy_bomb *entity)
{
	free(entity);
}

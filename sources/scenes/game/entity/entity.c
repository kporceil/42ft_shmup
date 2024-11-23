/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:30:22 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 22:34:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "game.h"
#include <stdlib.h>
#include <math.h>

unsigned int	last_entity_id = 0;

t_entity	*init_entity(t_entity_type type)
{
	t_entity	*entity = NULL;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->type = type;
	entity->data = init_entity_data(type);
	if (!entity->data)
	{
		free(entity);
		return (NULL);
	}
	entity->id = last_entity_id++;
	entity->y = 0;
	entity->x = 0;
	entity->prev_y = 0;
	entity->prev_x = 0;
	entity->velocity = 0;
	entity->angle = M_PI;
	entity->ft_update_physics = NULL;
	entity->ft_render = NULL;
	entity->prev = NULL;
	entity->next = NULL;
	return (entity);
}

int	entity_add_back(t_entity *current)
{
	while (current->next)
		current = current->next;
	current->next = init_entity(current->type);
	if (!current->next)
		return (-1);
	current->next->prev = current;
	return (0);
}

int	entity_add_front(t_entity *current)
{
	while (current->prev)
		current = current->prev;
	current->prev = init_entity(current->type);
	if (!current->prev)
		return (-1);
	current->prev->next = current;
	return (0);
}

int	entity_delone(t_entity *current)
{
	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current->data);
	free(current);
	return (0);
}

int	entity_clear(t_entity *current)
{
	while (current->prev)
		current = current->prev;
	while (current->next)
	{
		current = current->next;
		entity_delone(current->prev);
	}
	entity_delone(current);
	return (0);
}

void	*init_entity_data(t_entity_type type)
{

	switch (type)
	{
		case ENTITY_PLAYER_SHIP:
			return ((void *)init_entity_player_ship());
		case ENTITY_PLAYER_LASER:
			return ((void *)init_entity_player_laser());
		case ENTITY_ENEMY_LASER:
			return ((void *)init_entity_enemy_laser());
		case ENTITY_ENEMY_BOMB:
			return ((void *)init_entity_enemy_bomb());
		case ENTITY_ENEMY_SHIP:
			return ((void *)init_entity_enemy_ship());
	}
	return (NULL);
}

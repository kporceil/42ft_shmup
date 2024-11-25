/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:30:22 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:58:28 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "entity.h"
#include "game.h"

// last_entity_id is the last id given to an entity (incremented each time)
unsigned int	last_entity_id = 0;

/**
 * Initializes an entity with the given type.
 *
 * @param type The type of the entity to create.
 * @return The created entity, or NULL if an error occurred.
 */
t_entity	*init_entity(t_entity_type type, t_game_data *game_data)
{
	t_entity	*entity = NULL;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	// Base information
	entity->data = init_entity_data(type, game_data);
	if (!entity->data)
	{
		free(entity);
		return (NULL);
	}
	entity->id = last_entity_id++;
	entity->type = type;
	// Position and movement
	entity->y = 0;
	entity->x = 0;
	entity->next_y = 0;
	entity->next_x = 0;
	entity->velocity = 0;
	entity->acceleration = 0;
	entity->angle = M_PI_2;
	// Common functions
	switch (type)
	{
		case ENTITY_PLAYER_SHIP:
			entity->ft_update_physics = &update_entity_player_ship_physics;
			entity->ft_handle_collisions = &handle_entity_player_ship_collisions;
			entity->ft_render = &render_entity_player_ship;
			entity->ft_unrender = &unrender_entity_player_ship;
			break;
		case ENTITY_PLAYER_LASER:
			entity->ft_update_physics = &update_entity_player_laser_physics;
			entity->ft_handle_collisions = &handle_entity_player_laser_collisions;
			entity->ft_render = &render_entity_player_laser;
			entity->ft_unrender = &unrender_entity_player_laser;
			break;
		case ENTITY_ENEMY_SHIP:
			entity->ft_update_physics = &update_entity_enemy_ship_physics;
			entity->ft_handle_collisions = &handle_entity_enemy_ship_collisions;
			entity->ft_render = &render_entity_enemy_ship;
			entity->ft_unrender = &unrender_entity_enemy_ship;
			break;
		case ENTITY_ENEMY_LASER:
			entity->ft_update_physics = &update_entity_enemy_laser_physics;
			entity->ft_handle_collisions = &handle_entity_enemy_laser_collisions;
			entity->ft_render = &render_entity_enemy_laser;
			entity->ft_unrender = &unrender_entity_enemy_laser;
			break;
		case ENTITY_ENEMY_BOMB:
			entity->ft_update_physics = &update_entity_enemy_bomb_physics;
			//entity->ft_handle_collisions = &handle_entity_enemy_bomb_collisions;
			entity->ft_render = &render_entity_enemy_bomb;
			entity->ft_unrender = &unrender_entity_enemy_bomb;
			break;
	}
	// Double linked list
	entity->prev = NULL;
	entity->next = NULL;
	return (entity);
}

/**
 * Add the entity to the back of the linked list.
 *
 * @param node The node from which to start.
 * @param new The entity to add.
 */
void	entity_add_back(t_entity *node, t_entity *new)
{
	while (node->next)
		node = node->next;
	node->next = new;
	new->prev = node;
}

/**
 * Add the entity to the front of the linked list.
 *
 * @param node The node from which to start.
 * @param new The entity to add.
 */
void	entity_add_front(t_entity *node, t_entity *new)
{
	while (node->prev)
		node = node->prev;
	node->prev = new;
	new->next = node;
}

/**
 * Delete the entity from the linked list.
 *
 * @param current The current entity.
 * @return 0 if the entity was deleted, -1 if an error occurred.
 */
int	entity_delone(t_entity *current)
{
	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	del_entity_data(current);
	free(current);
	return (0);
}



/**
 * Clear the linked list of entities. Can start from any entity.
 *
 * @param node The node from which to start.
 * @return 0 if the entities were cleared, -1 if an error occurred.
 */
int	entity_clear(t_entity *node)
{
	t_entity	*tmp;

	while (node && node->prev)
		node = node->prev;
	while (node)
	{
		tmp = node->next;
		entity_delone(node);
		node = tmp;
	}
	return (0);
}

/**
 * Find the entity with the given id.
 *
 * @param node The node from which to start.
 * @param id The id of the entity to find.
 * @return The entity with the given id, or NULL if not found.
 */
t_entity	*entity_find_by_id(t_entity *node, int id)
{
	while (node)
	{
		if (node->id == id)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * Find the entity with the given type.
 *
 * @param node The node from which to start.
 * @param type The type of the entity to find.
 * @return The entity with the given type, or NULL if not found.
 */
t_entity	*entity_find_by_type(t_entity *node, t_entity_type type)
{
	while (node)
	{
		if (node->type == type)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * Count entities with the given type.
 *
 * @param node The node from which to start.
 * @param type The type of the entities to count.
 * @return The number of entities with the given type.
 */
int	entity_count_by_type(t_entity *node, t_entity_type type)
{
	int	count = 0;

	while (node)
	{
		if (node->type == type)
			count++;
		node = node->next;
	}
	return (count);
}

/**
 * Initialize the data of the entity with the given type.
 *
 * @param type The type of the entity to create.
 * @return The created entity data, or NULL if an error occurred.
 */
void	*init_entity_data(t_entity_type type, t_game_data *game_data)
{
	switch (type)
	{
		case ENTITY_PLAYER_SHIP:
			return ((void *)init_entity_player_ship(game_data));
		case ENTITY_PLAYER_LASER:
			return ((void *)init_entity_player_laser(game_data));
		case ENTITY_ENEMY_SHIP:
			return ((void *)init_entity_enemy_ship(game_data));
		case ENTITY_ENEMY_LASER:
			return ((void *)init_entity_enemy_laser(game_data));
		case ENTITY_ENEMY_BOMB:
			return ((void *)init_entity_enemy_bomb(game_data));
	}
	return (NULL);
}

/**
 * Delete the data of the entity with the given type.
 *
 * @param entity The entity to delete.
 */
void	del_entity_data(t_entity *entity)
{
	switch (entity->type)
	{
		case ENTITY_PLAYER_SHIP:
			del_entity_player_ship((t_entity_player_ship *) entity->data);
			break;
		case ENTITY_PLAYER_LASER:
			del_entity_player_laser((t_entity_player_laser *) entity->data);
			break;
		case ENTITY_ENEMY_SHIP:
			del_entity_enemy_ship((t_entity_enemy_ship *) entity->data);
			break;
		case ENTITY_ENEMY_LASER:
			del_entity_enemy_laser((t_entity_enemy_laser *) entity->data);
			break;
		case ENTITY_ENEMY_BOMB:
			del_entity_enemy_bomb((t_entity_enemy_bomb *) entity->data);
			break;
	}
}

/**
 * Reset the id counter.
 */
void	entity_reset_id_counter(void)
{
	last_entity_id = 0;
}

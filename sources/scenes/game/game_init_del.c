/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 07:40:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 07:40:22 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "entity.h"
#include "game_scenario.h"

/**
 * Initializes the game data.
 *
 * @return The game data.
 */
t_game_data	*ft_game_init(t_game_scenario scenario)
{
	t_game_data	*game_data;

	game_data = malloc(sizeof(t_game_data));
	if (!game_data)
		return (NULL);
	game_data->scenario = scenario;
	// Initialize entities with main player entity
	game_data->entities = init_entity(ENTITY_PLAYER_SHIP, game_data);
	game_data->entities->y = SCENE_HEIGHT - 10;
	game_data->entities->x = SCENE_WIDTH / 2;
	// Screen values
	game_data->resized = true;
	// Other
	game_data->paused = false;
	return (game_data);
}

/**
 * Cleans up everything initialized by ft_game_init.
 *
 * @param game_data The game data to delete.
 */
void	ft_game_del(t_game_data *game_data)
{
	entity_clear(game_data->entities);
	free(game_data);
}

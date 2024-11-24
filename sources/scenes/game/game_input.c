/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 05:32:18 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "game.h"
#include "entity.h"

/**
 * Handle inputs for the game scene.
 *
 * @param game_data Game data.
 */
void	ft_game_input(t_game_data *game_data)
{
	int	key = getch();
	switch (key)
	{
		// Movement keys
		case KEY_UP:
			((t_entity_player_ship *) entity_find_by_id(game_data->entities, 0)->data)->input = PLAYER_INPUT_MOVE_UP;
			break;
		case KEY_DOWN:
			((t_entity_player_ship *) entity_find_by_id(game_data->entities, 0)->data)->input = PLAYER_INPUT_MOVE_DOWN;
			break;
		case KEY_LEFT:
			((t_entity_player_ship *) entity_find_by_id(game_data->entities, 0)->data)->input = PLAYER_INPUT_MOVE_LEFT;
			break;
		case KEY_RIGHT:
			((t_entity_player_ship *) entity_find_by_id(game_data->entities, 0)->data)->input = PLAYER_INPUT_MOVE_RIGHT;
			break;
		// Shoot keys
		case 32:
		case KEY_ENTER:
		case 10:
			((t_entity_player_ship *) entity_find_by_id(game_data->entities, 0)->data)->input = PLAYER_INPUT_FIRE;
			break;
		// On resize
		case KEY_RESIZE:
			ft_game_scene_size(game_data);
			game_data->resized = true;
			break;
		case 27:
			game_data->paused = true;
			break;
		default:
			break;
	}
}

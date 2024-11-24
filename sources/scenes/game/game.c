/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 18:17:06 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ncurses.h>

#include "game.h"
#include "entity.h"
#include "scenes.h"

/**
 * Main menu scene.
 *
 * @return The error code.
 */
int	ft_game(t_game_scenario scenario)
{
	t_game_data	*game_data;

	// Init game data
	game_data = ft_game_init(scenario);
	if (!game_data)
		return (-1);
	
	// Init game screen
	clear();
	ft_game_scene_size(game_data);

	entity_reset_id_counter();  // Reset entity ID counter
	loop = true;  // Main loop flag
	while (loop)
	{
		// Start frame time
		clock_gettime(CLOCK_MONOTONIC, &game_data->frame_start);
		game_data->frame_time = (double) (game_data->frame_start.tv_sec * NS_PER_SECOND + game_data->frame_start.tv_nsec);

		ft_game_input(game_data);  // Handle input
	
		// TODO: Make a pause screen asking to resize the terminal
		if (!game_data->available_screen_space)
		{
			state = STATE_EXIT;
			break;
		}
		
		ft_game_update(game_data);  // Main game logic
		ft_game_render(game_data);  // Render the game
		
		// Loop end
		game_data->resized = false;

		// Timing logic
		clock_gettime(CLOCK_MONOTONIC, &game_data->frame_end);  // End frame time
		game_data->delta_time_ns = (game_data->frame_end.tv_sec - game_data->frame_start.tv_sec) * NS_PER_SECOND + (game_data->frame_end.tv_nsec - game_data->frame_start.tv_nsec);  // Calculate frame time in nanoseconds
		game_data->delta_time = (double) game_data->delta_time_ns / TARGET_FRAME_TIME_NS;  // Calculate delta time (ratio of frame time to target frame time)
		if (game_data->delta_time < 1.0)
		{
			struct timespec sleep_time = {0, TARGET_FRAME_TIME_NS - game_data->delta_time_ns};  // Calculate time to sleep
			nanosleep(&sleep_time, NULL);  // Sleep until next frame
			game_data->delta_time = 1.0;  // Reset delta time to 1.0 after sleeping
		}
		// Can't keep up trigger
#ifdef DEBUG
		if (game_data->delta_time > 1.0)
		{
			mvprintw(1, 0, "[WARN] Can't keep up! Delta time: %f", game_data->delta_time);
		}
		mvprintw(0, 0, "FPS: %f - Frame time: %f ms", 1.0 / (game_data->delta_time * TARGET_FRAME_TIME_NS / NS_PER_SECOND), game_data->delta_time_ns / 1000000.0);
#endif
	}
	ft_game_del(game_data);  // Free game data
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:19:39 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "game.h"

int	ft_game(void)
{
	t_game_data	*game_data;

	// Init game data
	game_data = ft_game_init();
	if (!game_data)
		return (1);

	loop = true;  // Main loop flag
	while (loop)
	{
		clock_gettime(CLOCK_MONOTONIC, &game_data->frame_start);  // Start frame time

		//ft_game_input(game_data);  // Handle input
		//ft_game_update(game_data);  // Update the game physics
		//ft_game_render(game_data);  // Render the game
		
		// Timing logic
		clock_gettime(CLOCK_MONOTONIC, &game_data->frame_end);  // End frame time
		game_data->delta_time_ns = (game_data->frame_end.tv_sec - game_data->frame_start.tv_sec) * NS_PER_SECOND + (game_data->frame_end.tv_nsec - game_data->frame_start.tv_nsec);  // Calculate frame time in nanoseconds
		game_data->delta_time = (double) game_data->delta_time_ns / TARGET_FRAME_TIME_NS;  // Calculate delta time (ratio of frame time to target frame time)
		if (game_data->delta_time < 1.0)
		{
			struct timespec sleep_time = {0, TARGET_FRAME_TIME_NS - game_data->delta_time_ns};  // Calculate time to sleep
			nanosleep(&sleep_time, NULL);  // Sleep until next frame
		}
		// Can't keep up trigger
		if (game_data->delta_time > 1.0)
		{
			// TODO: Should log this in debug mode
		}
	}
	ft_game_del(game_data);
	return (0);
}

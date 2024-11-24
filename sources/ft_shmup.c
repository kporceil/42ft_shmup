/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:21:45 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:12:14 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "scenes.h"
#include "game_scenario.h"
#include "render.h"

// Global variables
t_game_state	state = STATE_MAIN_MENU;  // Current game state
t_game_scenario	scenario = GAME_SCENARIO_EASY;  // Current game scenario
int				last_game_score = 0;  // Last game score
bool			loop = true;  // Main loop flag of any scene

/**
 * Entry point of the shmup game.
 *
 * @return The error code.
 */
int	ft_shmup(void)
{
	int					err_code = 0;

	// Init components
	ft_init_ncurses();

	// Manage current game state
	while (state != STATE_EXIT && err_code == 0)
	{
		switch (state)
		{
			case STATE_MAIN_MENU:
				err_code = ft_main_menu();
				break;
			case STATE_GAME_MODE_MENU:
				err_code = ft_game_mode_menu();
				break;
			case STATE_SETTINGS:
				//err_code = ft_settings();
				break;
			case STATE_GAME:
				err_code = ft_game(scenario);
				break;
			case STATE_GAME_OVER:
				err_code = ft_game_over();
				break;
			case STATE_EXIT:
				break;
		}
	}

	// Gracefully exit
	ft_del_ncurses();
	return (err_code);
}

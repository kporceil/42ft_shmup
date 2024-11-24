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
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "game.h"
#include "game_scenario.h"
#include "render.h"
#include "ui_button.h"

void	ft_easy_trigger();
void	ft_medium_trigger();
void	ft_hard_trigger();
void	ft_doomsday_trigger();
void	ft_ww3_trigger();
void	ft_multiplayer_trigger();
void	ft_back_trigger();

/**
 * Game mode menu scene.
 *
 * @return The error code.
 */
int	ft_game_mode_menu()
{
	// Fetch screen size
	int	max_y;
	int	max_x;
	getmaxyx(stdscr, max_y, max_x); // Define screen size

	// Init buttons
	t_ui_button **buttons = malloc(sizeof(t_ui_button *) * 8);
	if (!buttons)
		return (-1);
	buttons[0] = ft_new_btn(0, 0, "Easy", ft_easy_trigger, true);
	if (!buttons[0])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[1] = ft_new_btn(0, 0, "Medium", ft_medium_trigger, true);
	if (!buttons[1])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[2] = ft_new_btn(0, 0, "Hard", ft_hard_trigger, true);
	if (!buttons[2])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[3] = ft_new_btn(0, 0, "Doomsday", ft_doomsday_trigger, true);
	if (!buttons[3])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[4] = ft_new_btn(0, 0, "WW3", ft_ww3_trigger, true);
	if (!buttons[4])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[5] = ft_new_btn(0, 0, "Multiplayer [disabled]", ft_multiplayer_trigger, true);
	if (!buttons[5])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[6] = ft_new_btn(0, 0, "Back", ft_back_trigger, true);
	if (!buttons[6])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[7] = NULL;
	// Highlight order
	buttons[0]->prev_highlight = buttons[6];
	buttons[0]->next_highlight = buttons[1];
	buttons[1]->prev_highlight = buttons[0];
	buttons[1]->next_highlight = buttons[2];
	buttons[2]->prev_highlight = buttons[1];
	buttons[2]->next_highlight = buttons[3];
	buttons[3]->prev_highlight = buttons[2];
	buttons[3]->next_highlight = buttons[4];
	buttons[4]->prev_highlight = buttons[3];
	buttons[4]->next_highlight = buttons[6];
	buttons[5]->prev_highlight = buttons[4];
	buttons[5]->next_highlight = buttons[6];
	buttons[6]->prev_highlight = buttons[4];
	buttons[6]->next_highlight = buttons[0];
	buttons[0]->prev_highlight = buttons[6];

	// Define current_highlight as the New game button
	t_ui_button	*current_highlight = buttons[0];

	bool	first_render = true;
	bool	should_render;
	loop = true;  // Main loop flag
	while (loop)
	{
		// Handle input
		ft_game_mode_menu_input(&should_render, &current_highlight, &max_y, &max_x);

		// Render if necessary or if first_render
		if (should_render || first_render)
		{
			// Ensure proper position, back is top left and first line is easy medium hard and second line is doomsday ww3 multiplayer
			ft_move_btn(buttons[0], (max_y - ft_height_btn(buttons[0]) - 10) / 2, (max_x - ft_width_btn(buttons[0]) - 40) / 2);
			ft_move_btn(buttons[1], (max_y - ft_height_btn(buttons[1]) - 10) / 2, (max_x - ft_width_btn(buttons[1])) / 2);
			ft_move_btn(buttons[2], (max_y - ft_height_btn(buttons[2]) - 10) / 2, (max_x - ft_width_btn(buttons[2]) + 40) / 2);
			ft_move_btn(buttons[3], (max_y - ft_height_btn(buttons[3]) + 20) / 2, (max_x - ft_width_btn(buttons[3]) - 80) / 2);
			ft_move_btn(buttons[4], (max_y - ft_height_btn(buttons[4]) + 20) / 2, (max_x - ft_width_btn(buttons[4])) / 2);
			ft_move_btn(buttons[5], (max_y - ft_height_btn(buttons[5]) + 20) / 2, (max_x - ft_width_btn(buttons[5]) + 80) / 2);
			ft_move_btn(buttons[6], ft_height_btn(buttons[6]) / 2, ft_width_btn(buttons[6]) / 2);
			ui_render((const t_ui_button **) buttons, current_highlight);
		}
		first_render = false;
	}

	// Free UI
	ft_free_btn_list(buttons);
	return (0);
}

void ft_easy_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_EASY;
	state = STATE_GAME;
}

void ft_medium_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_MEDIUM;
	state = STATE_GAME;
}

void ft_hard_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_HARD;
	state = STATE_GAME;
}

void ft_doomsday_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_DOOMSDAY;
	state = STATE_GAME;
}

void ft_ww3_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_WW3;
	state = STATE_GAME;
}

void ft_multiplayer_trigger()
{
	loop = false;
	scenario = GAME_SCENARIO_MULTIPLAYER;
	state = STATE_GAME;
}

void	ft_back_trigger()
{
	loop = false;
	state = STATE_MAIN_MENU;
}

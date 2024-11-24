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
#include "ui_button.h"

void	ft_new_game_trigger();
void	ft_settings_trigger();
void	ft_exit_trigger();

/**
 * Main menu scene.
 *
 * @return The error code.
 */
int	ft_main_menu()
{
	// Fetch screen size
	int	max_y;
	int	max_x;
	getmaxyx(stdscr, max_y, max_x); // Define screen size

	// Init buttons
	t_ui_button **buttons = malloc(sizeof(t_ui_button *) * 4);
	if (!buttons)
		return (-1);
	buttons[0] = ft_new_btn(0, 0, "New game", ft_new_game_trigger, true);
	if (!buttons[0])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[1] = ft_new_btn(0, 0, "Settings [disabled]", ft_settings_trigger, true);
	if (!buttons[1])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[2] = ft_new_btn(0, 0, "Exit", ft_exit_trigger, true);
	if (!buttons[2])
	{
		ft_free_btn_list(buttons);
		return (-1);
	}
	buttons[3] = NULL;
	// Highlight order
	buttons[0]->next_highlight = buttons[2];
	buttons[1]->next_highlight = buttons[2];
	buttons[2]->prev_highlight = buttons[0];
	buttons[1]->prev_highlight = buttons[0];

	// Define current_highlight as the New game button
	t_ui_button	*current_highlight = buttons[0];

	bool	first_render = true;
	bool	should_render;
	loop = true;  // Main loop flag
	while (loop)
	{
		// Handle input
		ft_main_menu_input(&should_render, &current_highlight, &max_y, &max_x);

		// Render if necessary or if first_render
		if (should_render || first_render)
		{
			// Ensure proper position
			ft_move_btn(buttons[0], (max_y - ft_height_btn(buttons[0]) - 8) / 2, (max_x - ft_width_btn(buttons[0])) / 2);
			ft_move_btn(buttons[1], (max_y - ft_height_btn(buttons[1])) / 2, (max_x - ft_width_btn(buttons[1])) / 2);
			ft_move_btn(buttons[2], (max_y - ft_height_btn(buttons[2]) + 8) / 2, (max_x - ft_width_btn(buttons[2])) / 2);
			ui_render((const t_ui_button **) buttons, current_highlight);
		}
		first_render = false;
	}

	// Free UI
	ft_free_btn_list(buttons);
	return (0);
}

void	ft_new_game_trigger()
{
	loop = false;
	state = STATE_GAME_MODE_MENU;
}

void	ft_settings_trigger()
{
	loop = false;
	state = STATE_SETTINGS;
}

void	ft_exit_trigger()
{
	loop = false;
	state = STATE_EXIT;
}

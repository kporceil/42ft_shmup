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
	getmaxyx(stdscr, max_y, max_x);

	// Init buttons
	t_ui_button *buttons[] = {
		ft_new_btn(0, 0, "New game", ft_new_game_trigger, true),
		ft_new_btn(0, 0, "Settings", ft_settings_trigger, true),
		ft_new_btn(0, 0, "Exit", ft_exit_trigger, true),
		NULL
	};
	//TODO: Malloc safe the buttons
	buttons[0]->next_highlight = buttons[1];
	buttons[1]->next_highlight = buttons[2];
	buttons[2]->prev_highlight = buttons[1];
	buttons[1]->prev_highlight = buttons[0];

	// Define current_highlight as the New game button
	t_ui_button	*current_highlight = buttons[0];

	bool	first_render = true;
	bool	should_render;
	loop = true;  // Main loop flag
	while (loop)
	{
		// Handle input
		ft_main_menu_input(&should_render, &current_highlight);

		// Render if necessary or if first_render
		if (should_render || first_render)
		{
			// Ensure proper position
			ft_move_btn(buttons[0], (max_y - ft_height_btn(buttons[0]) - 8) / 2, (max_x - ft_width_btn(buttons[0])) / 2);
			ft_move_btn(buttons[1], (max_y - ft_height_btn(buttons[1])) / 2, (max_x - ft_width_btn(buttons[1])) / 2);
			ft_move_btn(buttons[2], (max_y - ft_height_btn(buttons[2]) + 8) / 2, (max_x - ft_width_btn(buttons[2])) / 2);
			ft_main_menu_render((const t_ui_button **) buttons, current_highlight);
		}
		first_render = false;
	}

	// Free buttons
	for (int i = 0; buttons[i]; i++)
		free(buttons[i]);
	return (0);
}

void	ft_new_game_trigger()
{
	loop = false;
	state = STATE_GAME;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 04:00:01 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "ui_button.h"

bool	loop;

void	ft_new_game_trigger();
void	ft_exit_trigger();

int	ft_main_menu()
{
	// Fetch screen size
	int	max_y;
	int	max_x;
	getmaxyx(stdscr, max_y, max_x);

	// Init buttons
	t_ui_button	*start_btn = ft_new_btn(0, 0, "New game", ft_new_game_trigger, true);
	t_ui_button	*exit_btn = ft_new_btn(0, 0, "Exit", ft_exit_trigger, true);
	start_btn->next_highlight = exit_btn;
	exit_btn->prev_highlight = start_btn;
	
	t_ui_button	*current_highlight = start_btn;

	init_pair(1, COLOR_WHITE, COLOR_BLACK);  // Normal color pair
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // Reversed color pair

	bool	first_render = true;
	bool	should_render;
	loop = true;
	while (loop)
	{
		// Handle inputs
		int	key = getch();
		should_render = true;
		switch (key)
		{
			// Highlight
			case KEY_UP:
				if (current_highlight->prev_highlight)
					current_highlight = current_highlight->prev_highlight;
				break;
			case KEY_DOWN:
				if (current_highlight->next_highlight)
					current_highlight = current_highlight->next_highlight;
				break;
			// Enter keys
			case KEY_ENTER:
			case 10:
				ft_trigger_btn(current_highlight);
				break;
			// On resize
			case KEY_RESIZE:
				break;
			default:
				should_render = false;
		}

		if (should_render || first_render)
		{
			clear();
			getmaxyx(stdscr, max_y, max_x);
			
			ft_move_btn(start_btn, (max_y - ft_height_btn(start_btn) - 3) / 2, (max_x - ft_width_btn(start_btn)) / 2);
			ft_move_btn(exit_btn, (max_y - ft_height_btn(exit_btn) + 8) / 2, (max_x - ft_width_btn(exit_btn)) / 2);
			ft_render_btn(start_btn, current_highlight);
			ft_render_btn(exit_btn, current_highlight);

			refresh();
		}
		first_render = false;
	}

	ft_del_btn(start_btn);
	ft_del_btn(exit_btn);
	return (0);
}

void	ft_new_game_trigger()
{
	loop = false;
	state = STATE_GAME;
}

void	ft_exit_trigger()
{
	loop = false;
	state = STATE_EXIT;
}

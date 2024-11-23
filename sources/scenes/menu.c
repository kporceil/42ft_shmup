/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 02:18:23 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "ui_button.h"

int	ft_menu(void)
{
	initscr();  // Put console in cursor mode
	cbreak();  // No buffer
	noecho();  // Don't echo key inputs
	start_color();  // Init colors
	nodelay(stdscr, TRUE);  // Make getch non blocking
	
	curs_set(false);  // Hide cursor
	keypad(stdscr, TRUE);  // Handle cursor and special keys

	clear();  // Clear screen
	
	// Fetch screen size
	int	max_y;
	int	max_x;
	getmaxyx(stdscr, max_y, max_x);

	// Init buttons
	t_ui_button	*start_btn = ft_new_btn(0, 0, "New game", NULL, true);
	t_ui_button	*exit_btn = ft_new_btn(0, 0, "Exit", NULL, true);
	start_btn->next_highlight = exit_btn;
	exit_btn->prev_highlight = start_btn;
	
	t_ui_button	*current_highlight = start_btn;

	init_pair(1, COLOR_WHITE, COLOR_BLACK);  // Normal color pair
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // Reversed color pair

	bool	loop = true;
	bool	first_render = true;
	bool	should_render;
	while (loop)
	{
		// Handle inputs
		int	key = getch();
		should_render = true;
		switch (key)
		{
			case KEY_UP:
				if (current_highlight->prev_highlight)
					current_highlight = current_highlight->prev_highlight;
				break;
			case KEY_DOWN:
				if (current_highlight->next_highlight)
					current_highlight = current_highlight->next_highlight;
				break;
			case 10:
				if (current_highlight == exit_btn)
					loop = false;
				if (current_highlight->trigger)
					current_highlight->trigger();
				break;
			default:
				should_render = false;
		}

		if (should_render || first_render)
		{
			clear();
			getmaxyx(stdscr, max_y, max_x);
			
			ft_move_btn(start_btn, (max_y - ft_height_btn(start_btn) - 2) / 2, (max_x - ft_width_btn(start_btn)) / 2);
			ft_move_btn(exit_btn, (max_y - ft_height_btn(exit_btn) + 2) / 2, (max_x - ft_width_btn(exit_btn)) / 2);
			ft_render_btn(start_btn, current_highlight);
			ft_render_btn(exit_btn, current_highlight);

			refresh();
		}
		first_render = false;
	}

	clear();
	refresh();
	
	ft_del_btn(start_btn);
	ft_del_btn(exit_btn);

	endwin();  // Ends console cursor mode
	return (0);
}

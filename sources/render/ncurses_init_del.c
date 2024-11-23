/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_init_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:08:49 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 03:30:31 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <ncurses.h>

/**
 * This function initializes everything necessary for ncurses to render on screen
 */
void	ft_init_ncurses()
{
	initscr();  // Put console in cursor mode
	cbreak();  // No buffer
	noecho();  // Don't echo key inputs
	start_color();  // Init colors
	nodelay(stdscr, true);  // Make getch non blocking

	curs_set(false);  // Hide cursor
	keypad(stdscr, true);  // Handle cursor and special keys

	init_pair(1, COLOR_WHITE, COLOR_BLACK);  // Normal color pair
	init_pair(2, COLOR_BLACK, COLOR_WHITE);  // Reversed color pair

	clear();  // Clear screen
}

void	ft_del_ncurses()
{
	clear();
	refresh();
	endwin();  // Ends console cursor mode
}

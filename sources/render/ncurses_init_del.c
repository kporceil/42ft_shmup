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
#include <locale.h>

#include "render.h"

/**
 * This function initializes everything necessary for ncurses to render on screen.
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

	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);  // Normal color pair
	init_pair(BLACK_ON_WHITE, COLOR_BLACK, COLOR_WHITE);  // Reversed color pair
	
	// Additional color pairs
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(RED_ON_MAGENTA, COLOR_RED, COLOR_MAGENTA);

	set_escdelay(1);  // Set escape delay to 1ms

	clear();  // Clear screen
}

/**
 * This function cleans up everything initialized by ft_init_ncurses.
 */
void	ft_del_ncurses()
{
	clear();
	refresh();
	endwin();  // Ends console cursor mode
	
}

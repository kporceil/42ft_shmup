/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:16:12 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "ui_button.h"

/**
 * Handle inputs for main_menu scene.
 *
 * @param should_render		Update by reference the variable that indicates a need for a refresh.
 * @param current_highlight	Update by reference the currently highlighted button.
 */
void	ft_game_mode_menu_input(bool *should_render, t_ui_button **current_highlight, int *y, int *x)
{
	int	key = getch();
	*should_render = true;
	switch (key)
	{
		// Highlight
		case KEY_LEFT:
			if ((*current_highlight)->prev_highlight)
				*current_highlight = (*current_highlight)->prev_highlight;
			break;
		case KEY_RIGHT:
			if ((*current_highlight)->next_highlight)
				*current_highlight = (*current_highlight)->next_highlight;
			break;
		// Enter keys
		case KEY_ENTER:
		case 10:
			ft_trigger_btn(*current_highlight);
			break;
		// On resize
		case KEY_RESIZE:
			getmaxyx(stdscr, *y, *x);
			break;
		default:
			*should_render = false;
	}
}

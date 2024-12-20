/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:52:55 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 03:33:02 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "ui_button.h"

/**
 * Renders the extras of a UI button, including the border and the padding.
 * Uses ACS_* constants from ncurses, same result as the default window technique.
 *
 * @param btn The button to render.
 */
void	ft_render_btn_extras(const t_ui_button *btn)
{
	int	ch;  // Char to print
	int	height = ft_height_btn(btn);
	int	width = ft_width_btn(btn);

	// Go over each character occupied by the button hitbox
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ch = ' ';  // Defaults to space

			// Handle borders
			if (btn->has_borders) {
				// Top row
				if (i == 0)
				{
					if (j == 0) {
						ch = ACS_ULCORNER;
					} else if (j == width - 1) {
						ch = ACS_URCORNER;
					} else {
						ch = ACS_HLINE;
					}
				}
				// Bottom row
				else if (i == height - 1)
				{
					if (j == 0) {
						ch = ACS_LLCORNER;
					} else if (j == width - 1) {
						ch = ACS_LRCORNER;
					} else {
						ch = ACS_HLINE;
					}
				}
				// Middle rows
				else
				{
					if (j == 0 || j == width - 1) {
						ch = ACS_VLINE;
					}
				}
			}
			// Add corresponding char
			mvaddch(btn->y + i - btn->y_padding - btn->has_borders, btn->x + j - btn->x_padding - btn->has_borders, ch);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:28:24 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "ui_button.h"

//TODO: Make this UI rendering function global for all scenes

/**
 * Renders UI elements on the screen.
 *
 * @param btns Array of buttons to render.
 */
void	ft_main_menu_render(const t_ui_button **btns, const t_ui_button *current_highlight)
{
	clear();  // Clear screen

	// Render labels
	//TODO: Implement labels

	// Render buttons
	for (int i = 0; btns[i]; i++)
		ft_render_btn(btns[i], current_highlight);
	
	refresh();  // Dump screen to terminal
}

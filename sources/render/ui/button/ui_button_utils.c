/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:40:36 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 01:49:06 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "ui_button.h"

void	ft_render_btn(t_ui_button *btn, t_ui_button *highlight)
{
	if (btn == highlight)
		attron(COLOR_PAIR(2));
	mvprintw(btn->y, btn->x, "%s", btn->content);
	if (btn == highlight)
		attroff(COLOR_PAIR(2));
}

void	ft_move_btn(t_ui_button *btn, int y, int x)
{
	btn->y = y;
	btn->x = x;
}

int	ft_height_btn(t_ui_button *btn)
{
	return (1);
}

int	ft_width_btn(t_ui_button *btn)
{
	return (strlen(btn->content));
}

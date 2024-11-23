/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:40:36 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 03:34:13 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "ui_button.h"

void	ft_render_btn(const t_ui_button *btn, const t_ui_button *highlight)
{
	if (btn == highlight)
		attron(COLOR_PAIR(2));
	ft_render_btn_extras(btn);  // Render extras (border and padding)
	mvprintw(btn->y, btn->x, "%s", btn->content);
	if (btn == highlight)
		attroff(COLOR_PAIR(2));
}

void	ft_trigger_btn(const t_ui_button *btn)
{
	if (btn->trigger && !btn->disabled)
		btn->trigger();
}

void	ft_move_btn(t_ui_button *btn, int y, int x)
{
	btn->y = y;
	btn->x = x;
}

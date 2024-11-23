/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:40:36 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 03:13:46 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ui_button.h"

/**
 * Creates a new UI button.
 *
 * @param y The y position of the button.
 * @param x The x position of the button.
 * @param content The content of the button.
 * @param trigger The function to call when the button is clicked.
 * @param mouse_clickable Whether the button is clickable with the mouse.
 * @return The new button.
 */
t_ui_button	*ft_new_btn(int y, int x, char *content, void (*trigger)(void), bool mouse_clickable)
{
	t_ui_button	*btn;

	// Malloc
	btn = malloc(sizeof(t_ui_button));
	if (!btn)
		return (NULL);
	// Given values
	btn->y = y;
	btn->x = x;
	btn->content = strdup(content);
	if (!btn->content)
	{
		ft_del_btn(btn);
		return (NULL);
	}
	btn->trigger = trigger;
	btn->mouse_clickable = mouse_clickable;
	// Default values
	btn->prev_highlight = NULL;
	btn->next_highlight = NULL;
	btn->has_borders = true;
	btn->y_padding = 0;
	btn->x_padding = 1;
	btn->disabled = false;
	return (btn);
}

/**
 * Deletes a UI button.
 *
 * @param btn The button to delete.
 */
void	ft_del_btn(t_ui_button *btn)
{
	if (btn->content)
		free(btn->content);
	free(btn);
}

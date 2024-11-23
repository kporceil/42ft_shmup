/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:40:36 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 01:49:25 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ui_button.h"

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
	btn->disabled = false;
	return (btn);
}

void	ft_del_btn(t_ui_button *btn)
{
	if (btn->content)
		free(btn->content);
	free(btn);
}

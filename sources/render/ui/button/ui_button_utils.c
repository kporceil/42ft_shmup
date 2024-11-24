/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:40:36 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 02:51:23 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "ui_button.h"

/**
 * Returns the height of a UI button considering the borders and padding.
 *
 * @param btn The button.
 * @return The height.
 */
int	ft_height_btn(const t_ui_button *btn)
{
	return (1 + (btn->has_borders ? 2 : 0) + btn->y_padding * 2);
}

/**
 * Returns the width of a UI button considering the borders and padding.
 *
 * @param btn The button.
 * @return The width.
 */
int	ft_width_btn(const t_ui_button *btn)
{
	return (strlen(btn->content) + (btn->has_borders ? 2 : 0) + btn->x_padding * 2);
}

void	ft_free_btn_list(t_ui_button **btn_list)
{
	if (!btn_list)
		return ;
	for (int i = 0; btn_list[i]; i++)
		ft_del_btn(btn_list[i]);
	free(btn_list);
}

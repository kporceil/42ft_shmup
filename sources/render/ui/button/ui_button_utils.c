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

#include <string.h>

#include "ui_button.h"

int	ft_height_btn(const t_ui_button *btn)
{
	return (1 + (btn->has_borders ? 2 : 0) + btn->y_padding * 2);
}

int	ft_width_btn(const t_ui_button *btn)
{
	return (strlen(btn->content) + (btn->has_borders ? 2 : 0) + btn->x_padding * 2);
}

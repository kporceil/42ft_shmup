/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:21:45 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 02:25:14 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scenes.h"
#include "render.h"

int	ft_shmup(void)
{
	int	err_code = 0;

	ft_init_ncurses();

	// Entry point
	err_code = ft_menu();

	ft_del_ncurses();
	return (err_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:21:45 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:12:14 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "scenes.h"
#include "render.h"

t_game_state	state = STATE_MAIN_MENU;
bool			loop = true;

int	ft_shmup(void)
{
	int				err_code = 0;

	// Init components
	ft_init_ncurses();

	// Manage current game state
	while (state != STATE_EXIT)
	{
		switch (state)
		{
			case STATE_MAIN_MENU:
				err_code = ft_main_menu();
				break;
		}
	}

	// Gracefully exit
	ft_del_ncurses();
	return (err_code);
}

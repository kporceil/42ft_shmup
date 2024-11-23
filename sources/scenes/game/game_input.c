/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 07:34:55 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "scenes.h"
#include "game.h"

/**
 * Handle inputs for the game scene.
 *
 * @param game_data Game data.
 */
void	ft_game_input(t_game_data *game_data)
{
	int	key = getch();
	switch (key)
	{
		// Movement keys
		case KEY_UP:
			break;
		case KEY_DOWN:
			break;
		case KEY_LEFT:
			break;
		case KEY_RIGHT:
			break;
		// Enter keys
		case KEY_ENTER:
		case 10:
			break;
		// On resize
		case KEY_RESIZE:
			break;
		default:
			break;
	}
}

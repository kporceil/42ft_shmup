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

#include "game.h"

/**
 * Render the game screen.
 * 
 * @param game_data Game data.
 */
void	ft_game_render(t_game_data *game_data)
{
	clear();  // Clear screen

	refresh();  // Dump screen to terminal
}

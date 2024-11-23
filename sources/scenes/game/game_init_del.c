/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 07:40:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 07:40:22 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"

/**
 * Initializes the game data.
 *
 * @return The game data.
 */
t_game_data	*ft_game_init(void)
{
	t_game_data	*game_data;

	game_data = malloc(sizeof(t_game_data));
	if (!game_data)
		return (NULL);
	// TODO: Initialize game_data
	return (game_data);
}

/**
 * Cleans up everything initialized by ft_game_init.
 *
 * @param game_data The game data to delete.
 */
void	ft_game_del(t_game_data *game_data)
{
	// TODO: Free game_data
	free(game_data);
}

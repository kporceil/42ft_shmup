/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:09:22 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/24 18:19:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#include "game.h"
#include "entity.h"
#include "scenes.h"
#include "render.h"

void	game_over(t_game_data *game_data)
{
	//entity_clear(game_data->entities);
	//free(game_data);
	clear();
	t_entity *player = entity_find_by_id(game_data->entities, 0);
	if (player)
	{
		int	score = ((t_entity_player_ship *)player->data)->score;
		mvprintw((getmaxy(stdscr) / 2) + 1, (getmaxx(stdscr) - 12) / 2, "Score : %d", score);
	}
	mvprintw(getmaxy(stdscr) / 2, (getmaxx(stdscr) - strlen("Game over !")) / 2, "Game over !");
	refresh();
	while (getch() != 10)
		;
	ft_del_ncurses();
	exit(0);
}

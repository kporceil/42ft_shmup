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

int	ft_game_over()
{
	clear();
	mvprintw(getmaxy(stdscr) / 2, (getmaxx(stdscr) - strlen("Game over !")) / 2, "Game over !");
	mvprintw((getmaxy(stdscr) / 2) + 1, (getmaxx(stdscr) - 12) / 2, "Score : %d", last_game_score);
	mvprintw(getmaxy(stdscr) / 2 + 5, (getmaxx(stdscr) - strlen("Press <space> to return to menu")) / 2, "Press <space> to return to menu");
	refresh();
	while (getch() != 32)
		;
	state = STATE_MAIN_MENU;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:16:06 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 04:46:14 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <ncurses.h>

#include "game.h"
#include "entity.h"

/**
 * Render the game screen.
 * 
 * @param game_data Game data.
 */
void	ft_game_render(t_game_data *game_data)
{
	t_entity *entity;

	//ft_game_render_scene_background(game_data);  // Render background
	if (game_data->resized) {
		clear();
		ft_game_render_scene_borders(game_data);  // Render scene borders
	}
	// Unrender entities
	entity = game_data->entities;
	if (!game_data->resized)  // No need to unrender if the screen was resized (everything was cleared)
	{
		while (entity)
		{
			entity->ft_unrender(entity, game_data);
			entity = entity->next;
		}
	}

	// Render entities
	entity = game_data->entities;
	while (entity)
	{
		entity->ft_render(entity, game_data);
		entity = entity->next;
	}
	refresh();  // Dump screen to terminal
}

/**
 * Render the vertically moving background.
 *
 * @param game_data Game data.
 */
void	ft_game_render_scene_background(t_game_data *game_data)
{
	
	return ;
}

/**
 * Render the game scene borders with double pipes.
 *
 * @param game_data Game data.
 */
void	ft_game_render_scene_borders(t_game_data *game_data)
{
	int i;

	// Draw top and bottom border
	for (i = 0; i <= SCENE_WIDTH; i++)
	{
		mvaddch(game_data->scene_y_origin - 1, game_data->scene_x_origin + i, ACS_HLINE);
		mvaddch(game_data->scene_y_origin + SCENE_HEIGHT + 1, game_data->scene_x_origin + i, ACS_HLINE);
	}

	// Draw left and right
	for (i = 0; i <= SCENE_HEIGHT; i++)
	{
		mvaddch(game_data->scene_y_origin + i, game_data->scene_x_origin - 1, ACS_VLINE);
		mvaddch(game_data->scene_y_origin + i, game_data->scene_x_origin + SCENE_WIDTH + 1, ACS_VLINE);
	}

	// Draw corners
	mvaddch(game_data->scene_y_origin - 1, game_data->scene_x_origin - 1, ACS_ULCORNER);
	mvaddch(game_data->scene_y_origin - 1, game_data->scene_x_origin + SCENE_WIDTH + 1, ACS_URCORNER);
	mvaddch(game_data->scene_y_origin + SCENE_HEIGHT + 1, game_data->scene_x_origin - 1, ACS_LLCORNER);
	mvaddch(game_data->scene_y_origin + SCENE_HEIGHT + 1, game_data->scene_x_origin + SCENE_WIDTH + 1, ACS_LRCORNER);
}

/**
 * Calculates the game scene size. If the screen is too small, available_screen_space is set to false.
 *
 * @param game_data Game data.
 */
void	ft_game_scene_size(t_game_data *game_data)
{
	getmaxyx(stdscr, game_data->screen_height, game_data->screen_width);

	// + 2 for the borders
	if ((game_data->screen_height < SCENE_HEIGHT + SCENE_UI_HEIGHT + SCENE_VERTICAL_PADDING + 2) || (game_data->screen_width < SCENE_WIDTH + SCENE_HORIZONTAL_PADDING + 2))
	{
		game_data->available_screen_space = false;
		return ;
	}
	// Calculate scene origins (top-left corner)
	game_data->scene_y_origin = (game_data->screen_height - SCENE_HEIGHT - SCENE_UI_HEIGHT - SCENE_VERTICAL_PADDING - 1) / 2;
	game_data->scene_x_origin = (game_data->screen_width - SCENE_WIDTH - SCENE_HORIZONTAL_PADDING - 1) / 2;
	game_data->available_screen_space = true;
}

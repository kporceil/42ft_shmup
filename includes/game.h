/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:19:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 18:14:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// INCLUDES
# include <stdbool.h>
# include <time.h>

# include "game_scenario.h"

// PROTOTYPES (circular includes fix)
typedef struct s_entity t_entity;

// BASE RENDER VALUES
# define SCENE_HEIGHT 40
# define SCENE_WIDTH 150
# define SCENE_UI_HEIGHT 3
# define SCENE_VERTICAL_PADDING 2
# define SCENE_HORIZONTAL_PADDING 4
# define TARGET_FPS 60

// TIMING SYSTEM
# define NS_PER_SECOND 1000000000
# define NS_PER_MS 1000000
# define TARGET_FRAME_TIME_NS (NS_PER_SECOND / TARGET_FPS)

// BACKGROUND
typedef struct	s_star
{
	float		x;
	float		y;
}				t_star;

typedef struct	s_background_layer
{
	t_star		*stars;
	int			star_count;
	float		star_speed;
	char		star_char;
	int			star_color;
}				t_background_layer;

// GAME DATA
typedef struct	s_game_data
{
	// SCENARIO VALUES
	t_game_scenario		scenario;
	// ENTITIES
	t_entity			*entities;
	t_background_layer	background_layers[3];
	// SCREEN STATE
	bool				resized;
	bool				available_screen_space;
	int					screen_height;
	int					screen_width;
	int					scene_y_origin;
	int					scene_x_origin;
	// TIMING SYSTEM
	double				frame_since_begin;
	double				frame_time;
	struct timespec		frame_start;
	struct timespec		frame_end;
	double				delta_time;
	double				delta_time_ns;
	// OTHER
	bool				paused;
}				t_game_data;

// GAME
void	ft_game_input(t_game_data *game_data);
void	ft_game_update(t_game_data *game_data);
void	ft_game_controls(t_game_data *game_data);

// GAME ENNEMY
void	game_enemy_logic(t_game_data *game_data);
void	game_add_enemy(t_game_data *game_data);

// GAME DATA
t_game_data	*ft_game_init(t_game_scenario scenario);
void		ft_game_del(t_game_data *game);

#endif

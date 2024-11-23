/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:19:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 23:28:16 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "entities.h"
# include <time.h>

// BASE RENDER VALUES
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define TARGET_FPS 30

// TIMING SYSTEM
# define NS_PER_SECOND 1000000000
# define TARGET_FRAME_TIME_NS (NS_PER_SECOND / TARGET_FPS)

typedef enum	e_player_input
{
	PLAYER_INPUT_NONE,
	PLAYER_INPUT_MOVE_UP,
	PLAYER_INPUT_MOVE_DOWN,
	PLAYER_INPUT_MOVE_LEFT,
	PLAYER_INPUT_MOVE_RIGHT,
	PLAYER_INPUT_FIRE,
}				t_player_input;

// GAME STATE
typedef struct	s_game_data
{
	t_entity		*entities;
	// TIMING SYSTEM
	struct timespec	frame_start;
	struct timespec	frame_end;
	double			delta_time;
	double			delta_time_ns;
}				t_game_data;

// GAME
int	ft_game(void);
void	ft_game_update(t_game_data *game);

// GAME DATA
t_game_data	*ft_game_init(void);
void		ft_game_del(t_game_data *game);

#endif

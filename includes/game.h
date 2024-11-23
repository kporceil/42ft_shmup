/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:19:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 06:19:39 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <time.h>

// BASE RENDER VALUES
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define TARGET_FPS 30

// TIMING SYSTEM
# define NS_PER_SECOND 1000000000
# define TARGET_FRAME_TIME_NS (NS_PER_SECOND / TARGET_FPS)

// ENTITY
typedef enum	e_entity_type
{
	ENTITY_PLAYER_SHIP,
	ENTITY_PLAYER_LASER,
	ENTITY_ENEMY_LASER,
	ENTITY_ENEMY_BOMB,
	ENTITY_ENEMY_SHIP,
}				t_entity_type;

typedef struct	s_entity
{
	// Base information
	int				id;
	int				type;
	void			*data;
	// Position and movement
	float			y;
	float			x;
	float			prev_y;
	float			prev_x;
	float			velocity;
	float			angle;
	// Double linked list
	struct s_entity	*prev;
	struct s_entity	*next;
}				t_entity;

// PLAYER
typedef enum	e_player_type
{
	PLAYER_KEYBOARD,
	PLAYER_KEYBOARD_SECONDARY,
	PLAYER_REMOTE,
}				t_player_type;

typedef enum	e_player_input
{
	PLAYER_INPUT_NONE,
	PLAYER_INPUT_MOVE_UP,
	PLAYER_INPUT_MOVE_DOWN,
	PLAYER_INPUT_MOVE_LEFT,
	PLAYER_INPUT_MOVE_RIGHT,
	PLAYER_INPUT_FIRE,
}				t_player_input;

typedef struct	s_player
{
	// Base information
	int				id;
	t_player_type	type;
	// Game information
	int				score;
	int				lives;
	int				health;
	int				ammo;
	t_entity		*ship;
}				t_player;

// GAME STATE
typedef struct	s_game_data
{
	t_entity		*entities;
	t_player		**players;
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

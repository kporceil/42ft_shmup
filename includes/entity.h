/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:05:19 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/24 21:06:32 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

// INCLUDES
# include <stdbool.h>

# include "game.h"

// COLORS SETS
# define COLOR_SET_BLUE 10;
# define COLOR_SET_RED 20;

// ENTITY
typedef enum	e_entity_type
{
	ENTITY_PLAYER_SHIP,
	ENTITY_PLAYER_LASER,
	ENTITY_ENEMY_SHIP,
	ENTITY_ENEMY_LASER,
	ENTITY_ENEMY_BOMB,
}				t_entity_type;

// PLAYER
typedef enum	e_player_type
{
	PLAYER_KEYBOARD,
	PLAYER_KEYBOARD_SECONDARY,
	PLAYER_REMOTE,
}				t_player_type;

// GLOBAL ENTITY
typedef struct	s_entity
{
	// Base information
	int				id;
	t_entity_type	type;
	void			*data;
	// Position and movement
	float			y;
	float			x;
	float			next_y;
	float			next_x;
	float			velocity;
	float			acceleration;
	float			angle;
	// Common function
	void	(*ft_update_physics)(struct s_entity *, t_game_data *);
	void	(*ft_handle_collisions)(struct s_entity *, t_game_data *);
	void	(*ft_render)(struct s_entity *, t_game_data *);
	void	(*ft_unrender)(struct s_entity *, t_game_data *);
	// Double linked list
	struct s_entity	*prev;
	struct s_entity	*next;
}				t_entity;

// PLAYER INPUT
typedef enum	e_player_input
{
	PLAYER_INPUT_NONE,
	PLAYER_INPUT_MOVE_UP,
	PLAYER_INPUT_MOVE_DOWN,
	PLAYER_INPUT_MOVE_LEFT,
	PLAYER_INPUT_MOVE_RIGHT,
	PLAYER_INPUT_FIRE,
}				t_player_input;

// ENTITIES TYPES
typedef struct	s_entity_player_ship
{	
	// Base information
	t_player_type	type;
	// Movement
	t_player_input	input;
	// Game information
	int				score;
	int				health;
	double			cooldown;
	bool			power_up;
	int				color;
	unsigned char	icon;
}				t_entity_player_ship;

typedef struct	s_entity_player_laser
{
	int				player_id;
	int				perforation;
	int				damage;
	int				color;
	unsigned char	icon;
}				t_entity_player_laser;

typedef struct	s_entity_enemy_ship
{
	int				health;
	double			cooldown;
	int				color;
	unsigned char	icon;
}				t_entity_enemy_ship;

typedef struct	s_entity_enemy_laser
{
	int				perforation;
	int				damage;
	int				color;
	unsigned char	icon;
}				t_entity_enemy_laser;

typedef struct	s_entity_enemy_bomb
{
	int				damage;
	int				radius;
	int				health;
	int				color;
	unsigned char	icon;
}				t_entity_enemy_bomb;

// ENTITY MEMORY
t_entity	*init_entity(t_entity_type type, t_game_data *game_data);
int			entity_delone(t_entity *current);
void		entity_reset_id_counter(void);

// ENTITY LIST UTILS
void		entity_add_back(t_entity *node, t_entity *new);
void		entity_add_front(t_entity *node, t_entity *new);
int			entity_clear(t_entity *node);
t_entity	*entity_find_by_id(t_entity *node, int id);
t_entity	*entity_find_by_type(t_entity *node, t_entity_type type);
int			entity_count_by_type(t_entity *node, t_entity_type type);

// ENTITY RENDER
void		render_entity_player_ship(t_entity *entity, t_game_data *game_data);
void		unrender_entity_player_ship(t_entity *entity, t_game_data *game_data);
void		render_entity_player_laser(t_entity *entity, t_game_data *game_data);
void		unrender_entity_player_laser(t_entity *entity, t_game_data *game_data);
void		render_entity_enemy_ship(t_entity *entity, t_game_data *game_data);
void		unrender_entity_enemy_ship(t_entity *entity, t_game_data *game_data);
void		render_entity_enemy_laser(t_entity *entity, t_game_data *game_data);
void		unrender_entity_enemy_laser(t_entity *entity, t_game_data *game_data);
void		render_entity_enemy_bomb(t_entity *entity, t_game_data *game_data);
void		unrender_entity_enemy_bomb(t_entity *entity, t_game_data *game_data);

// ENTITY PHYSICS
void		update_entity_player_ship_physics(t_entity *entity, t_game_data *game_data);
void		handle_entity_player_ship_collisions(t_entity *entity, t_game_data *game_data);
void		update_entity_player_laser_physics(t_entity *entity, t_game_data *game_data);
void		handle_entity_player_laser_collisions(t_entity *entity, t_game_data *game_data);
void		update_entity_enemy_ship_physics(t_entity *entity, t_game_data *game_data);
void		handle_entity_enemy_ship_collisions(t_entity *entity, t_game_data *game_data);
void		update_entity_enemy_laser_physics(t_entity *entity, t_game_data *game_data);
void		handle_entity_enemy_laser_collisions(t_entity *entity, t_game_data *game_data);
void		update_entity_enemy_bomb_physics(t_entity *entity, t_game_data *game_data);
void		handle_entity_enemy_bomb_collisions(t_entity *entity, t_game_data *game_data);

// ENTITY DATA INIT
void		*init_entity_data(t_entity_type type, t_game_data *game_data);
void		*init_entity_player_ship(t_game_data *game_data);
void		*init_entity_player_laser(t_game_data *game_data);
void		*init_entity_enemy_ship(t_game_data *game_data);
void		*init_entity_enemy_laser(t_game_data *game_data);
void		*init_entity_enemy_bomb(t_game_data *game_data);

// ENTITY DATA DELETE
void		del_entity_data(t_entity *entity);
void		del_entity_player_ship(t_entity_player_ship *data);
void		del_entity_player_laser(t_entity_player_laser *data);
void		del_entity_enemy_ship(t_entity_enemy_ship *data);
void		del_entity_enemy_laser(t_entity_enemy_laser *data);
void		del_entity_enemy_bomb(t_entity_enemy_bomb *data);

#endif

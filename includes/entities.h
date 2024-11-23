/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:05:19 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:29:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include <stdbool.h>

# define COLOR_SET_BLUE 10;
# define COLOR_SET_RED 20;
// ENTITY
typedef enum	e_entity_type
{
	ENTITY_PLAYER_SHIP,
	ENTITY_PLAYER_LASER,
	ENTITY_ENEMY_LASER,
	ENTITY_ENEMY_BOMB,
	ENTITY_ENEMY_SHIP,
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
	float			prev_y;
	float			prev_x;
	float			velocity;
	float			angle;
	// Common function for entity
	void	(*ft_update_physics)(struct s_entity *);
	void	(*ft_render)(struct s_entity *);
	// Double linked list
	struct s_entity	*prev;
	struct s_entity	*next;
}				t_entity;

// ENTITIES TYPES
typedef struct	s_entity_player_ship
{	
	// Base information
	t_player_type	type;
	// Game information
	int				score;
	int				health;
	bool			power_up;
	unsigned char	icon;
}				t_entity_player_ship;

typedef struct	s_entity_player_laser
{
	int				perforation;
	int				damage;
	int				color;
	unsigned char	icon;
}				t_entity_player_laser;

typedef struct	s_entity_enemy_laser
{
	int				damage;
	int				color;
	unsigned char	icon;
}				t_entity_enemy_laser;

typedef struct	s_entity_enemy_bomb
{
	int				damage;
	int				radius;
	int				health;
	unsigned char	icon;
}				t_entity_enemy_bomb;

typedef struct	s_entity_enemy_ship
{
	int				health;
	unsigned char	icon;
}				t_entity_enemy_ship;

t_entity	*init_entity(t_entity_type type);
int			entity_add_back(t_entity *current);
int			entity_add_front(t_entity *current);
int			entity_delone(t_entity *current);
int			entity_clear(t_entity *current);
void		*init_entity_data(t_entity_type type);

// Init Type entities
void	*init_entity_player_ship(void);
void	*init_entity_player_laser(void);
void	*init_entity_enemy_laser(void);
void	*init_entity_enemy_bomb(void);
void	*init_entity_enemy_ship(void);

#endif

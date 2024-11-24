/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_scenario.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:40:56 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 21:09:59 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SCENARIO_H
# define GAME_SCENARIO_H

# include "render.h"

// GAME SCENARIO
typedef enum	e_game_scenario
{
	GAME_SCENARIO_EASY,
	GAME_SCENARIO_MEDIUM,
	GAME_SCENARIO_HARD,
	GAME_SCENARIO_WW3,
	GAME_SCENARIO_DOOMSDAY,
	GAME_SCENARIO_MULTIPLAYER,
}				t_game_scenario;

// MACROS FOR ENEMY CONTEXT
# define MAX_ENEMY(scenario) (scenario == GAME_SCENARIO_EASY ? 10 : \
								scenario == GAME_SCENARIO_MEDIUM ? 20 : \
								scenario == GAME_SCENARIO_HARD ? 30 : \
								scenario == GAME_SCENARIO_WW3 ? 50 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 100 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 20 : 0)

// MACROS FOR MOVEMENTS
# define ENEMY_VELOCITY(scenario) (scenario == GAME_SCENARIO_EASY ? 0.03 : \
								scenario == GAME_SCENARIO_MEDIUM ? 0.08 : \
								scenario == GAME_SCENARIO_HARD ? 0.15 : \
								scenario == GAME_SCENARIO_WW3 ? 0.2 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 0.05 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 0.08 : 0)

// MACROS FOR DAMAGE AND PERFORATION
# define PLAYER_LASER_DAMAGE(scenario) (scenario == GAME_SCENARIO_EASY ? 100 : \
								scenario == GAME_SCENARIO_MEDIUM ? 100 : \
								scenario == GAME_SCENARIO_HARD ? 80 : \
								scenario == GAME_SCENARIO_WW3 ? 100 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 200 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 100 : 0)

# define PLAYER_LASER_PERFORATION(scenario) (scenario == GAME_SCENARIO_EASY ? 1 : \
								scenario == GAME_SCENARIO_MEDIUM ? 1 : \
								scenario == GAME_SCENARIO_HARD ? 1 : \
								scenario == GAME_SCENARIO_WW3 ? 2 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 3 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 1 : 1)

# define ENEMY_LASER_DAMAGE(scenario) (scenario == GAME_SCENARIO_EASY ? 100 : \
								scenario == GAME_SCENARIO_MEDIUM ? 200 : \
								scenario == GAME_SCENARIO_HARD ? 300 : \
								scenario == GAME_SCENARIO_WW3 ? 500 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 1000 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 200 : 0)

// MACROS FOR HP
# define PLAYER_HP(scenario) (scenario == GAME_SCENARIO_EASY ? 1000 : \
								scenario == GAME_SCENARIO_MEDIUM ? 800 : \
								scenario == GAME_SCENARIO_HARD ? 600 : \
								scenario == GAME_SCENARIO_WW3 ? 3000 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 10000 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 1000 : 0)

# define ENNEMY_HP(scenario) (scenario == GAME_SCENARIO_EASY ? 100 : \
								scenario == GAME_SCENARIO_MEDIUM ? 200 : \
								scenario == GAME_SCENARIO_HARD ? 300 : \
								scenario == GAME_SCENARIO_WW3 ? 500 : \
								scenario == GAME_SCENARIO_DOOMSDAY ? 100 : \
								scenario == GAME_SCENARIO_MULTIPLAYER ? 200 : 0)

// BACKGROUND LAYERS
# define BACKGROUND_LAYER_COUNT(layer) (layer == 0 ? 30 : \
								layer == 1 ? 20 : \
								layer == 2 ? 3 : 0)

# define BACKGROUND_LAYER_SPEED(layer) (layer == 0 ? 0.005 : \
								layer == 1 ? 0.01 : \
								layer == 2 ? 0.3 : 0)

# define BACKGROUND_LAYER_CHAR(layer) (layer == 0 ? '.' : \
								layer == 1 ? '\'' : \
								layer == 2 ? '#' : 0)

# define BACKGROUND_LAYER_COLOR(layer) (layer == 0 ? BLUE : \
								layer == 1 ? MAGENTA : \
								layer == 2 ? YELLOW : 0)

#endif

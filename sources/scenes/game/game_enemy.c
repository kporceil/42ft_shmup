/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:29:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/24 07:29:22 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "game.h"
#include "game_scenario.h"
#include "entity.h"

/**
 * Handle the enemy logic.
 *
 * @param game_data The game data.
 */
void game_enemy_logic(t_game_data *game_data)
{
	// Add enemies if needed
	int enemy_count = entity_count_by_type(game_data->entities, ENTITY_ENEMY_SHIP);
	if (enemy_count < MAX_ENEMY(game_data->scenario))
		game_add_enemy(game_data);

	// Make enemies shoot
	t_entity			*enemy = game_data->entities;
	t_entity_enemy_ship *enemy_ship;
	while (enemy)
	{
		if (enemy->type == ENTITY_ENEMY_SHIP)
		{
			enemy_ship = (t_entity_enemy_ship *) enemy->data;
			if (rand() % 100 < 2 && enemy_ship->cooldown <= game_data->frame_time)
			{
				t_entity *laser = init_entity(ENTITY_ENEMY_LASER, game_data);
				if (laser)
				{
					laser->y = enemy->y + 1;
					laser->x = enemy->x;
					laser->angle = M_PI_2;
					laser->velocity = 0.5;
					((t_entity_enemy_laser *) laser->data)->damage = ENEMY_LASER_DAMAGE(game_data->scenario);
					entity_add_back(game_data->entities, laser);
					enemy_ship->cooldown = game_data->frame_time + 1 * NS_PER_SECOND;
				}
			}
		}
		enemy = enemy->next;
	}
}

/**
 * Add an enemy to the game.
 *
 * @param game_data The game data.
 */
void game_add_enemy(t_game_data *game_data)
{
	t_entity *enemy;

	enemy = init_entity(ENTITY_ENEMY_SHIP, game_data);
	if (!enemy)
		return;
	enemy->y = 0;
	enemy->x = rand() % SCENE_WIDTH;
	enemy->velocity = ENEMY_VELOCITY(game_data->scenario) + ((rand() % 400) - 200) / 10000.0;  // random -0.02 to 0.02
	enemy->angle = M_PI_2 + ((rand() % 800) - 400) / 1000.0;  // random -0.4 to 0.4
	entity_add_back(game_data->entities, enemy);
}

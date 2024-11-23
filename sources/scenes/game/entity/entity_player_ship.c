/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_player_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:04:26 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:12:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include <stdlib.h>

void	*init_entity_player_ship(void)
{
	t_entity_player_ship	*entity;

	entity = malloc(sizeof(t_entity_player_ship));
	if (!entity)
		return (NULL);
	entity->type = PLAYER_KEYBOARD;
	entity->score = 0;
	entity->health = 1000;
	entity->power_up = false;
	entity->icon = 'G';
	return ((void *)entity);
}

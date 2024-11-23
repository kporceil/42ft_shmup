/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:22:16 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:27:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include <stdlib.h>

void	*init_entity_enemy_ship(void)
{
	t_entity_enemy_ship	*entity;

	entity = malloc(sizeof(t_entity_enemy_ship));
	if (!entity)
		return (NULL);
	entity->health = 100;
	entity->icon = 'M';
	return ((void *)entity);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_laser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:19:17 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:22:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include <stdlib.h>

void	*init_entity_enemy_laser(void)
{
	t_entity_enemy_laser	*entity;

	entity = malloc(sizeof(t_entity_enemy_laser));
	if (!entity)
		return (NULL);
	entity->damage = 50;
	entity->color = COLOR_SET_RED;
	entity->icon = '|';
	return ((void *)entity);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_enemy_bomb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:16:12 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:19:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include <stdlib.h>

void	*init_entity_enemy_bomb(void)
{
	t_entity_enemy_bomb	*entity;

	entity = malloc(sizeof(t_entity_enemy_bomb));
	if (!entity)
		return (NULL);
	entity->damage = 500;
	entity->radius = 5;
	entity->health = 1;
	entity->icon = 'B';
	return ((void *)entity);
}

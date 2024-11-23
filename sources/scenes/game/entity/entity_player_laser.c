/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_player_laser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:09:16 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/23 23:26:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include <stdlib.h>

void	*init_entity_player_laser(void)
{
	t_entity_player_laser	*entity;

	entity = malloc(sizeof(t_entity_player_laser));
	if (!entity)
		return (NULL);
	entity->perforation = 0;
	entity->damage = 100;
	entity->color = COLOR_SET_BLUE;
	entity->icon = '|';
	return ((void *)entity);
}

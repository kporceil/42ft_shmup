/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:01:48 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 20:52:57 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "game.h"
#include "physics.h"

float	ft_accelerate(float velocity, float acceleration, float delta_time)
{
	return (MIN(MAX(velocity, MIN_SPEED), MAX_SPEED) + MIN(MAX(acceleration, MIN_ACCELERATION), MAX_ACCELERATION) * delta_time / 100);
}

void	ft_move(float *y, float *x, float velocity, float angle, float delta_time)
{
	if (velocity == 0)
		return ;
	*y += velocity * sinf(angle) * delta_time;
	*x += velocity * cosf(angle) * delta_time;
}

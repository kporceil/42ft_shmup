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

float	ft_accelerate(float velocity, float acceleration, float delta_time)
{
	return (velocity + acceleration * delta_time);
}

void	ft_move(float *y, float *x, float velocity, float angle, float delta_time)
{
	*y += velocity * sinf(angle) * delta_time;
	*x += velocity * cosf(angle) * delta_time;
}

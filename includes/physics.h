/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:19:21 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 06:20:45 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

# define MIN_SPEED 0f
# define MAX_SPEED 10f

# define MIN_ACCELERATION 0f
# define MAX_ACCELERATION 10f

// MOVEMENT
float	ft_accelerate(float velocity, float acceleration, float delta_time);
void	ft_move(float *x, float *y, float velocity, float angle, float delta_time);

// COLLISION
bool	ft_ranges_overlap(float min1, float max1, float min2, float max2);
bool	ft_rectangles_intersect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
bool	ft_segments_intersect(float y1, float x1, float y2, float x2);

#endif

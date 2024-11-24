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

# include "entity.h"

# define MIN_SPEED 0.0
# define MAX_SPEED 5.0

# define MIN_ACCELERATION -10.0
# define MAX_ACCELERATION 10.0

// MACROS
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

// MOVEMENT
float	ft_accelerate(float velocity, float acceleration, float delta_time);
void	ft_move(float *y, float *x, float velocity, float angle, float delta_time);

// COLLISION
bool	ft_ranges_overlap(float min1, float max1, float min2, float max2);
bool	ft_rectangles_intersect(float y1, float x1, float h1, float w1, float y2, float x2, float h2, float w2);
bool	ft_segments_intersect(float a_y1, float a_x1, float a_y2, float a_x2, float b_y1, float b_x1, float b_y2, float b_x2);
bool	ft_entities_collide(t_entity *entity1, t_entity *entity2, float radius);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:01:46 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 21:43:22 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "entity.h"

/**
 * Check if two ranges overlap (max can't be less than min).
 *
 * @param min1 The minimum value of the first range.
 * @param max1 The maximum value of the first range.
 * @param min2 The minimum value of the second range.
 * @param max2 The maximum value of the second range.
 * @return true if the ranges overlap, false otherwise.
 */
bool	ft_ranges_overlap(float min1, float max1, float min2, float max2)
{
	return ((min1 <= max2) && (min2 <= max1));
}

/**
 * Check if two segments intersect (segments A and B).
 *
 * @param a_y1 The y-coordinate of the first point of the first segment.
 * @param a_x1 The x-coordinate of the first point of the first segment.
 * @param a_y2 The y-coordinate of the second point of the first segment.
 * @param a_x2 The x-coordinate of the second point of the first segment.
 * @param b_y1 The y-coordinate of the first point of the second segment.
 * @param b_x1 The x-coordinate of the first point of the second segment.
 * @param b_y2 The y-coordinate of the second point of the second segment.
 * @param b_x2 The x-coordinate of the second point of the second segment.
 * @return true if the segments intersect, false otherwise.
 */
bool	ft_segments_intersect(float a_y1, float a_x1, float a_y2, float a_x2, float b_y1, float b_x1, float b_y2, float b_x2)
{
	float	det, gamma, lambda;

	// Calculate the determinant
	det = (a_x2 - a_x1) * (b_y2 - b_y1) - (b_x2 - b_x1) * (a_y2 - a_y1);
	if (det == 0)  // If determinant is 0, segments are colinear
		return (false);
	// Calculate the parameters of the intersection point
	lambda = ((b_y2 - b_y1) * (b_x2 - a_x1) + (b_x1 - b_x2) * (b_y2 - a_y1)) / det;  // Point of intersection along segment A (ratio)
	gamma = ((a_y1 - a_y2) * (b_x2 - a_x1) + (a_x2 - a_x1) * (b_y2 - a_y1)) / det;  // Point of intersection along segment B (ratio)
	return (0.0f < lambda && lambda < 1.0f && 0.0f < gamma && gamma < 1.0f);  // Return true if the intersection point is within both segments (0<p<1)
}

/**
 * Check if two entities collide with each other.
 *
 * @param entity1 The first entity.
 * @param entity2 The second entity.
 * @return true if the entities collide, false otherwise.
 */
bool	ft_entities_collide(t_entity *entity1, t_entity *entity2)
{
	//TODO: Not implemented for element with a size > 1
	if (ft_segments_intersect(entity1->y, entity1->x, entity1->next_y, entity1->next_x, entity2->y, entity2->x, entity2->next_y, entity2->next_x))
		return (true);
	return (false);
}

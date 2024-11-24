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
#include <math.h>

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
 * Check if a segment intersects a circle.
 *
 * @param a_y1 The y-coordinate of the first point of the segment.
 * @param a_x1 The x-coordinate of the first point of the segment.
 * @param a_y2 The y-coordinate of the second point of the segment.
 * @param a_x2 The x-coordinate of the second point of the segment.
 * @param c_y The y-coordinate of the center of the circle.
 * @param c_x The x-coordinate of the center of the circle.
 * @param radius The radius of the circle.
 * @return true if the segment intersects the circle, false otherwise.
 */
bool	ft_segment_circle_intersect(float a_y1, float a_x1, float a_y2, float a_x2, float c_y, float c_x, float radius) {
    // Vector from point 1 to point 2
    float dx = a_x2 - a_x1;
    float dy = a_y2 - a_y1;

    // Vector from point 1 to the circle center
    float fx = a_x1 - c_x;
    float fy = a_y1 - c_y;

    float a = dx * dx + dy * dy;  // Dot product of the segment
    float b = 2 * (fx * dx + fy * dy);  // Dot product of the segment and the vector
    float c = (fx * fx + fy * fy) - radius * radius;  // Dot product of the vector

    float discriminant = b * b - 4 * a * c;  // Discriminant of the quadratic equation

    if (discriminant < 0) {
        // No intersection
        return false;
    } else {
        // Check if the intersection points are within the segment
        discriminant = sqrt(discriminant);
        float t1 = (-b - discriminant) / (2 * a);
        float t2 = (-b + discriminant) / (2 * a);

        if ((t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1)) {
            return true;
        }
    }
    return false;
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
	return (0.0f <= lambda && lambda <= 1.0f && 0.0f <= gamma && gamma <= 1.0f);  // Return true if the intersection point is within both segments (0<p<1)
}

/**
 * Check if two entities collide with each other.
 *
 * @param entity1 The first entity.
 * @param entity2 The second entity.
 * @return true if the entities collide, false otherwise.
 */
bool	ft_entities_collide(t_entity *entity1, t_entity *entity2, float radius)
{
	if (ft_segment_circle_intersect(entity1->y, entity1->x, entity1->next_y, entity1->next_x, entity2->y, entity2->x, radius))
		return (true);
	if (ft_segment_circle_intersect(entity2->y, entity2->x, entity2->next_y, entity2->next_x, entity1->next_y, entity1->next_x, radius))
		return (true);
	return (false);
}

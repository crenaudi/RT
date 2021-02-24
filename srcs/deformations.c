/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deformations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float	apply_operations(t_object *obj, t_intersect_data *dist_array)
{
	if (obj->deformation != DEFNONE && obj->type != NONE)
		return (operation_caller(obj->deformation, dist_array[0].dist,
				dist_array[1].dist,
				obj->def_data.k));
	else
		return (0.0f);
}

float	op_uni(float d1, float d2, float private)
{
	(void)private;
	return (min(d1, d2));
}

float	op_sub(float d1, float d2, float private)
{
	(void)private;
	return (max(-d1, d2));
}

float	op_inter(float d1, float d2, float private)
{
	(void)private;
	return (max(d1, d2));
}

float	op_s_uni(float d1, float d2, float k)
{
	float h;

	h = clamp(0.5 + (0.5 * (d2 - d1)) / k, 0.0, 1.0);
	return (lerp(d2, d1, h) - k * h * (1.0 - h));
}

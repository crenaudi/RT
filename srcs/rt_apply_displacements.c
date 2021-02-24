/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_apply_displacements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float	displacement_caller(t_e_disp disp, t_object *obj, t_vec3f p)
{
	static float (*const disp_arr[__DISP_TOTAL])(t_object *, t_vec3f, float) = {
		[DISP_SIN] = &displace_sin,
		[DISP_TWIST] = &displace_twist,
		[DISP_BEND] = &displace_bend,
		[DISP_PERLIN] = &displace_perlin,
	};

	return (disp_arr[disp](obj, p, obj->disp_data[disp]));
}

void	apply_displacements(t_object *obj, t_intersect_data *array, t_vec3f p)
{
	int i;

	i = 0;
	while (obj[i].type != NONE)
	{
		if (obj[i].disp != DISP_NONE)
		{
			array[i].dist = displacement_caller(obj[i].disp,
								&obj[i],
								p);
		}
		i++;
	}
}

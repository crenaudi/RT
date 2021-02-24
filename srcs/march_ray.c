/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/rt_materials.h"
#include <stdbool.h>

int					*operation_bullshit(t_object *obj, t_intersect_data *array,
						t_vec3f rd)
{
	static int	op_indexes[100];
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (obj[i].type != NONE)
	{
		if (obj[i].deformation != DEFNONE &&
			obj[i + 1].type != NONE &&
			obj[i + 2].type != NONE)
		{
			get_idata_op(&obj[i], rd, &array[i], 0);
			op_indexes[y] = i;
			y++;
		}
		i++;
	}
	op_indexes[y] = -1;
	return (&op_indexes[0]);
}

void				trim_op(int *op_i, t_intersect_data *d_arr, int size)
{
	int y;
	int pos;

	y = 0;
	while (op_i[y] != -1)
		y++;
	while (--y != -1)
	{
		pos = op_i[y] + 1;
		while (pos < (size - 1))
		{
			d_arr[pos] = d_arr[pos + 1];
			pos++;
		}
		pos = op_i[y] + 1;
		while (pos < (size - 1))
		{
			d_arr[pos] = d_arr[pos + 1];
			pos++;
		}
	}
}

t_intersect_data	get_dist(t_object *obj, t_vec3f rd)
{
	int					i;
	int					*op_idx;
	t_intersect_data	min;
	t_intersect_data	array[100];

	i = -1;
	while (obj[++i].type != NONE)
		get_idata_obj(&obj[i], rd, &array[i]);
	op_idx = operation_bullshit(obj, array, rd);
	if (op_idx[0] != -1)
	{
		trim_op(&op_idx[0], &array[0], i);
	}
	min = get_min_intersect_obj(array, i);
	return (min);
}

void				swap_dist(t_intersect_data *src, t_intersect_data *dest)
{
	float	tmp_dist;

	tmp_dist = src->dist;
	src = dest;
	src->dist = tmp_dist;
}

t_intersect_data	ray_march(t_ray ray, t_object *obj)
{
	t_intersect_data	dist_travelled;
	t_intersect_data	dist_to_scene;
	t_vec3f				final_ray_pos;
	size_t				steps;
	float				tmp_dist;

	dist_travelled.dist = 0.0f;
	steps = 0.0f;
	while (steps < MAX_STEPS)
	{
		final_ray_pos = vec3f_add_vec(vec3f_mul_k(ray.direction,
					dist_travelled.dist), ray.origin);
		dist_to_scene = get_dist(obj, final_ray_pos);
		tmp_dist = dist_travelled.dist;
		dist_travelled = dist_to_scene;
		dist_travelled.dist = tmp_dist;
		dist_travelled.dist += dist_to_scene.dist;
		if (check_limits(dist_travelled.dist, dist_to_scene.dist))
			break ;
		steps++;
	}
	dist_travelled.intersect_pos = final_ray_pos;
	dist_travelled.normal = get_normal(dist_travelled.intersect_pos, obj);
	return (dist_travelled);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/rt_materials.h"

t_intersect_data	get_min_intersect_obj(t_intersect_data *array, size_t size)
{
	size_t				i;
	t_intersect_data	min_obj;

	i = 1;
	min_obj = array[0];
	while (i < size)
	{
		if (array[i].dist < min_obj.dist)
			min_obj = array[i];
		i++;
	}
	return (min_obj);
}

float				get_array_min(float *array, size_t size)
{
	size_t	i;
	float	min;

	i = 1;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		i++;
	}
	return (min);
}

float				get_array_min_index(float *array, size_t size)
{
	size_t	i;
	int		other_i_lol;
	float	min;

	i = 1;
	other_i_lol = i;
	min = 0;
	if (array)
		min = array[0];
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			other_i_lol = i;
		}
		i++;
	}
	return (other_i_lol);
}

void				get_idata_obj(t_object *obj, t_vec3f rd,
							t_intersect_data *idata)
{
	sdf_arg_setup_caller(&rd, obj);
	*idata = (t_intersect_data){
		.dist = obj->disp == DISP_NONE ? sdf_caller(obj->type, rd, *obj) :
						displacement_caller(obj->disp, obj, rd),
			.id = obj->id,
			.type = obj->type,
			.color = obj->col,
			.material = obj->material,
			.shininess = obj->shininess,
			.dir = rd,
	};
}

float				get_idata_op(t_object *obj, t_vec3f rd,
							t_intersect_data *idata, float depth)
{
	*idata = (t_intersect_data){
	.dist = operation_caller(obj->deformation,
		(idata + 1)->dist,
		(idata + 2)->dist,
		obj->def_data.k),
		.id = obj->id,
		.type = obj->type,
		.color = obj->col,
		.material = (obj + 2)->material,
		.dir = rd};
	return (depth);
}

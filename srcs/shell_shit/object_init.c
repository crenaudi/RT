/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:29:37 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:56:12 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../includes/rt.h"

void	init_torus(t_object *obj, t_op_utils *data)
{
	char *found_r1;
	char *found_r2;

	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	found_r1 = ft_strstr(data->obj_data.attributs, "r1:");
	if (!data->obj_data.attributs || !found_r1)
	{
		obj->data.torus.r.x = 1;
		message(BUILTIN_CREATE, INIT_TORUS_NO_R1, obj->id, false);
	}
	else
		obj->data.torus.r.x = atof(found_r1 + 3);
	found_r2 = ft_strstr(data->obj_data.attributs, "r2:");
	if (!data->obj_data.attributs || !found_r2)
	{
		obj->data.torus.r.y = 1;
		message(BUILTIN_CREATE, INIT_TORUS_NO_R2, obj->id, false);
	}
	else
		obj->data.torus.r.y = atof(found_r2 + 3);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void	init_octa(t_object *obj, t_op_utils *data)
{
	char *found_s;

	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	found_s = ft_strstr(data->obj_data.attributs, "s:");
	if (!data->obj_data.attributs || !found_s)
	{
		obj->data.octa.s = 1;
		message(BUILTIN_CREATE, INIT_OCTA_NO_S, obj->id, false);
	}
	else
		obj->data.octa.s = atof(found_s + 2);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void	init_custom(t_object *obj, t_op_utils *data)
{
	obj->id = data->id;
	obj->pos = (t_vec3f){0, 0, 0};
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
	obj->material = MATERIAL_SOLID_COLOR;
}

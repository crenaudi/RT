/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:29:37 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:56:12 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../includes/rt.h"

void	get_var_obj(t_object *obj, t_op_utils *data, char *orientation)
{
	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	obj->data.plane.orientation = get_vec(orientation, "x:", "y:", "z:");
}

void	init_cone(t_object *obj, t_op_utils *data)
{
	t_vec3f	tmp;

	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	tmp = get_vec(data->obj_data.attributs, "x:", "y:", "z:");
	if (!data->obj_data.attributs || (check_if_null(tmp)))
	{
		obj->data.cone.c = ((t_vec2f){sqrt(3) * 0.5, cos(0.5)});
		message(BUILTIN_CREATE, INIT_CONE_NO_C, obj->id, false);
	}
	else
		obj->data.cone.c = vec2f_normalize((t_vec2f){sin(tmp.x), cos(tmp.y)});
	obj->col = get_vec(data->obj_data.color, "r:", "g:", "b:");
}

void	init_sphere(t_object *obj, t_op_utils *data)
{
	char *found_r;

	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	found_r = ft_strstr(data->obj_data.attributs, "r:");
	if (!data->obj_data.attributs || !found_r)
	{
		obj->data.sphere.rad = 1;
		message(BUILTIN_CREATE, INIT_SPHERE_NO_RAD, obj->id, false);
	}
	else
		obj->data.sphere.rad = atof(found_r + 2);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void	init_cube(t_object *obj, t_op_utils *data)
{
	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	obj->data.cube.b = get_vec(data->obj_data.attributs, "x:", "y:", "z:");
	if (!data->obj_data.attributs || (check_if_null(obj->data.cube.b)))
	{
		obj->data.cube.b = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CUBE_NO_B, obj->id, false);
	}
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void	init_ellipsoid(t_object *obj, t_op_utils *data)
{
	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	obj->data.ellipsoid.r = get_vec(data->obj_data.attributs, "x:", "y:", "z:");
	if (!data->obj_data.attributs || (check_if_null(obj->data.cube.b)))
	{
		obj->data.ellipsoid.r = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CUBE_NO_B, obj->id, false);
	}
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

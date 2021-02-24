/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_functions_suite.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:27:35 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 18:07:52 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../includes/rt.h"

void		init_plane(t_object *obj, t_op_utils *data)
{
	char *orientation;
	char *found_h;

	orientation = get_substring(data->obj_data.attributs, "o{", "}");
	if (!(data->obj_data.attributs) || !orientation)
		orientation = ft_strdup("x:0 y:1 z:0");
	get_var_obj(obj, data, orientation);
	found_h = ft_strstr(data->obj_data.attributs, "h:");
	if (!data->obj_data.attributs || !found_h)
	{
		obj->data.plane.h = 1;
		message(BUILTIN_CREATE, INIT_PLANE_NO_H, obj->id, false);
	}
	else
		obj->data.plane.h = atof(found_h + 2);
	if (obj->data.plane.orientation.x == 0 && obj->data.plane.orientation.y == 0
		&& obj->data.plane.orientation.z == 0)
	{
		obj->data.plane.orientation = (t_vec3f){0, 1, 0};
		message(BUILTIN_CREATE, INIT_PLANE_NO_O, obj->id, false);
	}
	obj->deformation = ft_bin_search_str((char**)ret_operation_names_array(),
		data->obj_data.obj_operation, __DEFORMATION_TOTAL);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
	free(orientation);
}

static void	init_capsule_suite(t_object *obj, t_op_utils *data)
{
	char *found_r;

	found_r = ft_strstr(data->obj_data.attributs, "r:");
	if (!data->obj_data.attributs || !found_r)
	{
		obj->data.capsule.r = 1;
		message(BUILTIN_CREATE, INIT_CAPSULE_NO_R, obj->id, false);
	}
	else
		obj->data.capsule.r = atof(found_r + 2);
	obj->deformation = ft_bin_search_str((char**)ret_operation_names_array(),
		data->obj_data.obj_operation, __DEFORMATION_TOTAL);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void		init_capsule(t_object *obj, t_op_utils *data)
{
	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	obj->data.capsule.a = get_vec(data->obj_data.attributs, "x1:", "y1:",
		"z1:");
	if (!data->obj_data.attributs || check_if_null(obj->data.capsule.a))
	{
		obj->data.capsule.a = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CAPSULE_NO_A, obj->id, false);
	}
	obj->data.capsule.b = get_vec(data->obj_data.attributs, "x2:", "y2:",
		"z2:");
	if (!data->obj_data.attributs || check_if_null(obj->data.capsule.b))
	{
		obj->data.capsule.b = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CAPSULE_NO_B, obj->id, false);
	}
	init_capsule_suite(obj, data);
}

static void	init_cylinder_suite(t_object *obj, t_op_utils *data)
{
	char *found_r;
	char *found_h;

	found_r = ft_strstr(data->obj_data.attributs, "r:");
	if (!data->obj_data.attributs || !found_r)
	{
		obj->data.cylinder.r = 1;
		message(BUILTIN_CREATE, INIT_CYL_NO_R, obj->id, false);
	}
	else
		obj->data.cylinder.r = atof(found_r + 2);
	found_h = ft_strstr(data->obj_data.attributs, "h:");
	if (!data->obj_data.attributs || !found_h)
	{
		obj->data.cylinder.heigth = 2;
		message(BUILTIN_CREATE, INIT_CYL_NO_H, obj->id, false);
	}
	else
		obj->data.cylinder.heigth = atof(found_h + 2);
	obj->deformation = ft_bin_search_str((char**)ret_operation_names_array(),
		data->obj_data.obj_operation, __DEFORMATION_TOTAL);
	obj->col = get_color(data->obj_data.color, "r:", "g:", "b:");
}

void		init_cylinder(t_object *obj, t_op_utils *data)
{
	obj->id = data->id;
	obj->pos = get_vec(data->obj_data.pos, "x:", "y:", "z:");
	obj->material = get_material(data->obj_data.material);
	if (obj->pos.x == 0 && obj->pos.y == 0 && obj->pos.z == 0)
		set_default_pos_obj(obj);
	obj->data.cylinder.a = get_vec(data->obj_data.attributs, "x1:", "y1:",
		"z1:");
	if (!data->obj_data.attributs || check_if_null(obj->data.cylinder.a))
	{
		obj->data.cylinder.a = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CYL_NO_A, obj->id, false);
	}
	obj->data.cylinder.b = get_vec(data->obj_data.attributs, "x2:", "y2:",
		"z2:");
	if (!data->obj_data.attributs || check_if_null(obj->data.cylinder.b))
	{
		obj->data.cylinder.b = (t_vec3f){1, 1, 1};
		message(BUILTIN_CREATE, INIT_CYL_NO_B, obj->id, false);
	}
	init_cylinder_suite(obj, data);
}

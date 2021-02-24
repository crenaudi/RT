/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_objet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:33:54 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 18:52:01 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void			builtin_caller_names_array_print_attr(int fn, t_object *obj)
{
	static void	(*g_objects_names_array_print_attr[__SDF_TOTAL])(t_object *) = {
		[SDF_SPHERE] = &print_attr_sphere,
		[SDF_TORUS] = &print_attr_torus,
		[SDF_CUBE] = &print_attr_cube,
		[SDF_OCTA] = &print_attr_octa,
		[SDF_PLANE] = &print_attr_plane,
		[SDF_CAPSULE] = &print_attr_capsule,
		[SDF_ELLI] = &print_attr_ellipsoid,
		[SDF_CYLINDER] = &print_attr_cylinder};

	g_objects_names_array_print_attr[fn](obj);
}

void			builtin_caller_names_array(int fn, t_object *obj,
	t_op_utils *data)
{
	static void	(*objects_names_array[__SDF_TOTAL])(t_object *, t_op_utils *) =
	{[SDF_SPHERE] = &init_sphere,
		[SDF_TORUS] = &init_torus,
		[SDF_CUBE] = &init_cube,
		[SDF_OCTA] = &init_octa,
		[SDF_PLANE] = &init_plane,
		[SDF_CAPSULE] = &init_capsule,
		[SDF_CYLINDER] = &init_cylinder,
		[SDF_CONE] = &init_cone,
		[SDF_ELLI] = &init_ellipsoid,
		[SDF_CUSTOM] = &init_custom};

	objects_names_array[fn](obj, data);
}

static void		clear_op_utils(t_op_utils *private)
{
	ft_putstr(">>>>>>>>>>");
	if (private->operation != NULL)
		free(private->operation);
	if (private->str1 != NULL)
		free(private->str1);
	if (private->str2 != NULL)
		free(private->str2);
	if (private->obj_data.obj_operation != NULL)
		free(private->obj_data.obj_operation);
	if (private->obj_data.pos != NULL)
		free(private->obj_data.pos);
	if (private->obj_data.color != NULL)
		free(private->obj_data.color);
	if (private->obj_data.attributs != NULL)
		free(private->obj_data.attributs);
	if (private->obj_data.material != NULL)
		free(private->obj_data.material);
	ft_putstr("<<<<<<<<<< ");
}

void			get_object_data(t_object *obj, t_op_utils *private)
{
	int		def;

	obj->type = private->obj_data.type;
	if (!private->operation)
		def = -1;
	else
		def = ft_bin_search_str(
			(char**)ret_operation_names_array(),
			private->operation,
			__DEFORMATION_TOTAL);
	if (def < 0)
		obj->deformation = DEFNONE;
	else
		obj->deformation = def;
	ft_putstr("found op: ");
	ft_putendl(ret_operation_names_array()[obj->deformation]);
	obj->pos = (t_vec3f){
		atof(private->obj_data.pos),
		atof(private->obj_data.pos),
		atof(private->obj_data.pos)};
	obj->shininess = clamp(atof(private->obj_data.shininess), 100, 0);
	builtin_caller_names_array(private->obj_data.type, obj, private);
	clear_op_utils(private);
}

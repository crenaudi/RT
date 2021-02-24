/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:49:50 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 16:53:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../includes/rt_object.h"

void	set_default_disp(t_object *obj)
{
	obj->disp = DISP_NONE;
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_DISP, obj->id, false);
}

void	set_material_col_utils(t_op_utils *obj)
{
	if (obj->obj_data.material != NULL)
		free(obj->obj_data.material);
	obj->obj_data.material = ft_strdup("mat{MATERAL_SOLID_COLOR}");
	ft_putstr(obj->id);
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_MAT, obj->id, false);
}

void	set_default_op_obj(t_object *obj)
{
	obj->deformation = DEFNONE;
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_OP, obj->id, false);
}

void	set_default_op_utils(t_op_utils *obj)
{
	if (obj->obj_data.obj_operation != NULL)
		free(obj->obj_data.obj_operation);
	obj->obj_data.obj_operation = ft_strdup("none");
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_OP, obj->id, false);
}

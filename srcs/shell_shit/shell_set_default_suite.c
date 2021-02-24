/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_default_suite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:49:42 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 16:52:19 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../includes/rt_object.h"

void	set_default_mat_utils(t_op_utils *obj)
{
	if (obj->obj_data.material != NULL)
		free(obj->obj_data.material);
	obj->obj_data.material = ft_strdup("mat{solid_color}");
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_MAT, obj->id, false);
}

void	set_default_pos_obj(t_object *obj)
{
	vec3f_set(&obj->pos, 0, 1, 0);
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_POS, obj->id, false);
}

void	set_default_pos_utils(t_op_utils *obj)
{
	if (obj->obj_data.pos != NULL)
		free(obj->obj_data.pos);
	obj->obj_data.pos = ft_strdup("pos{x:0 y:1 z:0}\0");
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_POS, obj->id, false);
}

void	set_default_col_utils(t_op_utils *obj)
{
	if (obj->obj_data.color != NULL)
		free(obj->obj_data.color);
	obj->obj_data.color = ft_strdup("col{r:255 g:255 b:255}");
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_COL, obj->id, false);
}

void	set_default_shin(t_op_utils *obj)
{
	if (obj->obj_data.shininess != NULL)
		free(obj->obj_data.shininess);
	obj->obj_data.shininess = ft_strdup("0");
	message(BUILTIN_CREATE, CREATE_SET_DEFAULT_SHIN, obj->id, false);
}

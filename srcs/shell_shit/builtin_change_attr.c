/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_change_attr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:37 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 18:26:06 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	change_attr_new_material(t_object **object, char *data)
{
	int	mat_index;

	mat_index = ft_bin_search_str((char**)ret_obj_material(),
			data,
			__MATERIAL_TOTAL);
	if (mat_index < 0)
		message(BUILTIN_CHANGE_ATTR, WRONG_INPUT, "material", false);
	else
		(*object)->material = mat_index;
}

void	change_attr_new_pos(t_object **object, char *data)
{
	t_vec3f new_value;

	new_value = (t_vec3f){0, 0, 0};
	new_value = get_vec(data, "x:", "y:", "z:");
	if (check_if_null(new_value))
		message(BUILTIN_CHANGE_ATTR, WRONG_INPUT, "position", false);
	else
		(*object)->pos = new_value;
}

void	parse_new_attributes(t_object **object, char *command_line)
{
	char *tmp;

	tmp = NULL;
	if ((tmp = get_substring(command_line, "pos{", "}")))
		change_attr_new_pos(object, tmp);
	if (tmp)
		free(tmp);
	tmp = NULL;
	if ((tmp = get_substring(command_line, "op{", "}")))
		change_attr_new_deformation(object, tmp);
	if (tmp)
		free(tmp);
	tmp = NULL;
	if ((tmp = get_substring(command_line, "col{", "}")))
		change_attr_new_col(object, tmp);
	if (tmp)
		free(tmp);
	tmp = NULL;
	if ((tmp = get_substring(command_line, "mat{", "}")))
		change_attr_new_material(object, tmp);
	if (tmp)
		free(tmp);
}

void	builtin_change_attr(t_object *obj, char *buff, t_rt_utils *utils)
{
	char		*id;
	char		*attr;
	t_object	*traveller;

	(void)utils;
	id = NULL;
	attr = NULL;
	if (!(id = get_substring(buff, "id{", "}")))
		message(BUILTIN_CHANGE_ATTR, NO_ARGS_PASSED, "id", false);
	else
	{
		if (!(traveller = find_object_by_id(obj, id)))
		{
			message(BUILTIN_CHANGE_ATTR, OBJ_NOT_FOUND, id, false);
			return ;
		}
		if (!(attr = get_substring(buff, "attr{", "}")))
			message(BUILTIN_CHANGE_ATTR, WRONG_INPUT, id, false);
		if (attr)
			builtin_caller_names_array_change_attr(traveller->type, &traveller,
				attr);
		parse_new_attributes(&traveller, buff);
	}
}

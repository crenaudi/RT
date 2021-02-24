/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:24:27 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:38:26 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		if_function(t_op_utils *new_obj, char *buff, t_object *obj_list)
{
	if (!(new_obj->obj_data.attributs = get_substring(buff, "attr{", "}")))
		new_obj->obj_data.attributs = NULL;
	if (!(new_obj->id = get_substring(buff, "id{", "}")))
		new_obj->id = set_default_id_utils(new_obj, obj_list);
	if (!(new_obj->obj_data.pos = get_substring(buff, "pos{", "}")))
		set_default_pos_utils(new_obj);
	if (!(new_obj->operation = get_substring(buff, "op{", "}")))
		set_default_op_utils(new_obj);
	if (!(new_obj->obj_data.color = get_substring(buff, "col{", "}")))
		set_default_col_utils(new_obj);
	new_obj->obj_data.material = get_substring(buff, "mat{", "}");
	if (new_obj->obj_data.material == NULL
		|| ft_strstr(new_obj->obj_data.material, "none"))
		set_default_mat_utils(new_obj);
	if (!(new_obj->obj_data.shininess = get_substring(buff, "shin{", "}")))
		set_default_shin(new_obj);
}

int			parse_creation_attributes(t_op_utils *new_obj, char *buff,
	t_object *obj_list)
{
	t_e_sdf		type_enum;
	char		*typestr;
	int			type_ret;

	type_ret = 0;
	if (!(typestr = get_substring(buff, "type{", "}")))
	{
		message(BUILTIN_CREATE, CREATE_MISSING_OBJ_TYPE, NULL, false);
		return (-1);
	}
	if ((type_ret = ft_bin_search_str((char **)ret_type_strings(), typestr,
		__SDF_TOTAL)) == -1)
	{
		message(BUILTIN_CREATE, CREATE_UNKNOWN_OBJ_TYPE, typestr, false);
		return (-1);
	}
	free(typestr);
	type_enum = type_ret;
	new_obj->obj_data.type = type_enum;
	if_function(new_obj, buff, obj_list);
	return (0);
}

void		parse_args(t_op_utils *new_obj, char *buff, char *start[2],
	char *end[2])
{
	new_obj->id = get_substring(buff, start[0], end[0]);
	new_obj->operation = get_substring(buff, start[1], end[1]);
}

t_op_utils	parse_input(char *buff, char *start[2], char *end[2],
	t_object *obj_list)
{
	t_op_utils		new_obj;

	(void)start;
	(void)end;
	ft_bzero(&new_obj, sizeof(t_op_utils));
	if (parse_creation_attributes(&new_obj, buff, obj_list) < 0)
	{
		new_obj.id = NULL;
		return (new_obj);
	}
	return (new_obj);
}

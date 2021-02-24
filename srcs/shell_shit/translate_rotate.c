/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:46:45 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 16:46:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"

void	tab_found(char *found[3], t_op_utils cast)
{
	found[X] = ft_strstr(cast.operation, "x:");
	found[Y] = ft_strstr(cast.operation, "y:");
	found[Z] = ft_strstr(cast.operation, "z:");
}

void	builtin_obj_translate(t_object *object_list, char *buff,
	t_rt_utils *utils)
{
	t_op_utils	cast;
	t_object	*obj;
	char		*found[3];

	(void)utils;
	parse_args(&cast, buff, (char *[2]){"id{", "pos{"}, (char *[2]){"}", "}"});
	obj = find_object_by_id(object_list, cast.id);
	if (obj == NULL)
		message(BUILTIN_TRANSLATE, NOT_FOUND, "obj in the list", false);
	else
	{
		tab_found(found, cast);
		if (found[X])
			obj->pos.x = atof(found[X] + 2);
		if (found[Y])
			obj->pos.y = atof(found[Y] + 2);
		if (found[Z])
			obj->pos.z = atof(found[Z] + 2);
	}
}

void	builtin_obj_rotate(t_object *object_list, char *buff, t_rt_utils *utils)
{
	t_op_utils	cast;
	t_object	*obj;
	char		*found[3];
	static void (*const rot_fptr[__TOTAL_ROT])(float, t_vec3f *) = {
		&get_roll_matrix, &get_pitch_matrix, &get_yaw_matrix};

	(void)utils;
	parse_args(&cast, buff, (char *[2]){"id{", "rot{"}, (char *[2]){"}", "}"});
	obj = find_object_by_id(object_list, cast.id);
	if (obj == NULL)
		message(BUILTIN_ROTATE, NOT_FOUND, "obj in the list", false);
	else
	{
		tab_found(found, cast);
		if (found[X])
			rot_fptr[*found[X] - 'x'](deg_to_rad(atof(found[X] + 2)),
				obj->rot_mat);
		else if (found[Y])
			rot_fptr[*found[Y] - 'x'](deg_to_rad(atof(found[Y] + 2)),
				obj->rot_mat);
		else if (found[Z])
			rot_fptr[*found[Z] - 'x'](deg_to_rad(atof(found[Z] + 2)),
				obj->rot_mat);
	}
}

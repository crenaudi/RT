/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_change_attr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:37 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 18:26:06 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	builtin_caller_names_array_change_attr(int fn, t_object **obj,
	char *data)
{
	static void	(*attr_tab[__SDF_TOTAL])(t_object **, char *) = {
		[SDF_CYLINDER] = &change_attr_elli,
		[SDF_ELLI] = &change_attr_cone,
		[SDF_CONE] = &change_attr_cylinder,
		[SDF_SPHERE] = &change_attr_sphere,
		[SDF_TORUS] = &change_attr_torus,
		[SDF_CUBE] = &change_attr_cube,
		[SDF_OCTA] = &change_attr_octa,
		[SDF_PLANE] = &change_attr_plane,
		[SDF_CAPSULE] = &change_attr_capsule};

	attr_tab[fn](obj, data);
}

void	change_attr_new_col(t_object **object, char *data)
{
	t_vec3f	new_value;

	new_value = get_vec(data, "r:", "g:", "b:");
	if (check_if_null(new_value))
		message(BUILTIN_CHANGE_ATTR, WRONG_INPUT, "color", false);
	else
		(*object)->col = new_value;
}

void	change_attr_new_deformation(t_object **object, char *data)
{
	int	deformation_index;

	deformation_index = ft_bin_search_str((char**)ret_operation_names_array(),
			data,
			__DEFORMATION_TOTAL);
	if (deformation_index < 0)
		message(BUILTIN_CHANGE_ATTR, WRONG_INPUT, "deformations", false);
	else
		(*object)->deformation = deformation_index;
}

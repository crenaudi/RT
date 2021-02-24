/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_change_attr_suite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:52:31 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 18:13:08 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"

void	change_attr_torus(t_object **obj, char *data)
{
	char *found_r1;
	char *found_r2;

	found_r1 = ft_strstr(data, "r1:");
	if (found_r1)
		(*obj)->data.torus.r.x = atof(found_r1 + 3);
	else
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "torus r1", false);
	found_r2 = ft_strstr(data, "r2:");
	if (found_r2)
		(*obj)->data.torus.r.y = atof(found_r2 + 3);
	else
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "torus r2", false);
}

void	change_attr_capsule(t_object **obj, char *data)
{
	t_vec3f	new_attr;
	char	*found;

	found = NULL;
	new_attr = get_vec(data, "x1:", "y1:", "z1:");
	if (check_if_null(new_attr))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "capsule's new a", false);
	else
		(*obj)->data.capsule.a = new_attr;
	new_attr = get_vec(data, "x2:", "y2:", "z2:");
	if (check_if_null(new_attr))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "capsule's new b", false);
	else
		(*obj)->data.capsule.b = new_attr;
	if (!(ft_strstr(data, "r:")))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "capsule's new radius", false);
	else
	{
		found = ft_strstr(data, "r:");
		if (found)
			(*obj)->data.capsule.r = atof(found + 2);
	}
}

void	change_attr_cylinder(t_object **obj, char *data)
{
	t_vec3f	new_attr;
	char	*found;

	found = NULL;
	new_attr = get_vec(data, "x1:", "y1:", "z1:");
	if (check_if_null(new_attr))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "cylinder's new a", false);
	else
		(*obj)->data.cylinder.a = new_attr;
	new_attr = get_vec(data, "x2:", "y2:", "z2:");
	if (check_if_null(new_attr))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "cylinder's new b", false);
	else
		(*obj)->data.cylinder.b = new_attr;
	if (!(ft_strstr(data, "r:")))
		message(BUILTIN_CHANGE_ATTR, NOT_FOUND, "cylinder's new radius", false);
	else
	{
		found = ft_strstr(data, "r:");
		if (found)
			(*obj)->data.cylinder.r = atof(found + 2);
	}
}

void	change_attr_cone(t_object **obj, char *data)
{
	char *found_r;
	char *found_h;

	found_r = ft_strstr(data, "r:");
	if (found_r)
		(*obj)->data.cone.r = atof(found_r + 2);
	else
		attr_error(*obj);
	found_h = ft_strstr(data, "h:");
	if (found_h)
		(*obj)->data.cone.h = atof(found_h + 2);
	else
		attr_error(*obj);
}

void	change_attr_elli(t_object **obj, char *data)
{
	t_vec3f	new_attr;

	new_attr = get_vec(data, "x:", "y:", "z:");
	if (check_if_null(new_attr))
		attr_error(*obj);
	else
		(*obj)->data.ellipsoid.r = new_attr;
}

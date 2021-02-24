/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_change_attr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:53:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 16:59:30 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"

void	attr_error(t_object *obj)
{
	ft_putstr("[CHANGE_ATTR] Wrong input ");
	ft_putstr("format for new attributes to the object id{");
	ft_putstr(obj->id);
	ft_putstr("}\nAttributes remain unchanged\n");
}

void	change_attr_sphere(t_object **obj, char *data)
{
	char *found;

	found = NULL;
	if (!(ft_strstr(data, "r:")))
		attr_error(*obj);
	else
	{
		found = ft_strstr(data, "r:");
		if (found)
			(*obj)->data.sphere.rad = atof(found + 2);
	}
}

void	change_attr_cube(t_object **obj, char *data)
{
	t_vec3f	new_attr;

	new_attr = get_vec(data, "x:", "y:", "z:");
	if (check_if_null(new_attr))
		attr_error(*obj);
	else
		(*obj)->data.cube.b = new_attr;
}

void	change_attr_octa(t_object **obj, char *data)
{
	char	*found;

	found = NULL;
	if (!(ft_strstr(data, "s:")))
		attr_error(*obj);
	else
	{
		found = ft_strstr(data, "s:");
		if (found)
			(*obj)->data.sphere.rad = atof(found + 2);
	}
}

void	change_attr_plane(t_object **obj, char *data)
{
	t_vec3f		new_attr;
	int			match;
	char		*found;

	match = 0;
	new_attr = get_vec(data, "x:", "y:", "z:");
	if (check_if_null(new_attr))
	{
		ft_putendl("[CHANGE_ATTR] No match for new plane orientation");
		match++;
	}
	else
		(*obj)->data.plane.orientation = new_attr;
	found = ft_strstr(data, "h:");
	if (found)
		(*obj)->data.plane.h = atof(found + 2);
	else
	{
		ft_putendl("[CHANGE_ATTR] No match for new plane height");
		match++;
	}
	if (match == 2)
		attr_error(*obj);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:29:37 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:56:12 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../includes/rt.h"

t_vec3f			get_vec(char *data, char *x, char *y, char *z)
{
	char	*x_pos;
	char	*y_pos;
	char	*z_pos;

	if (!data)
		return ((t_vec3f){0, 0, 0});
	x_pos = NULL;
	y_pos = NULL;
	z_pos = NULL;
	if (ft_strstr(data, x))
		x_pos = ft_strstr(data, x);
	if (ft_strstr(data, y))
		y_pos = ft_strstr(data, y);
	if (ft_strstr(data, z))
		z_pos = ft_strstr(data, z);
	if (!x_pos || !y_pos || !z_pos)
	{
		ft_putstr("Wrong format or input for position or attribute\n");
		return ((t_vec3f){0, 0, 0});
	}
	return ((t_vec3f){atof(x_pos + 2), atof(y_pos + 2), atof(z_pos + 2)});
}

t_vec3f			get_color(char *data, char *x, char *y, char *z)
{
	char	*x_col;
	char	*y_col;
	char	*z_col;

	if (!data)
		return ((t_vec3f){0, 0, 0});
	x_col = NULL;
	y_col = NULL;
	z_col = NULL;
	if (ft_strstr(data, x))
		x_col = ft_strstr(data, x);
	if (ft_strstr(data, y))
		y_col = ft_strstr(data, y);
	if (ft_strstr(data, z))
		z_col = ft_strstr(data, z);
	if (!x_col || !y_col || !z_col)
	{
		ft_putstr("Wrong format or input for position or attribute\n");
		return ((t_vec3f){0, 0, 0});
	}
	return ((t_vec3f){clamp(atof(x_col + 2), 255, 0),
						clamp(atof(y_col + 2), 255, 0),
						clamp(atof(z_col + 2), 255, 0)});
}

int				check_if_null(t_vec3f vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	return (0);
}

t_e_material	get_material(char *data)
{
	int		material;

	material =
		ft_bin_search_str((char**)ret_obj_material(), data, __MATERIAL_TOTAL);
	if (material != -1)
		return (material);
	message(BUILTIN_CREATE, MATERIAL_NOT_FOUND, NULL, false);
	return (MATERIAL_SOLID_COLOR);
}

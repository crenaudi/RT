/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:33:17 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 18:33:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	print_tvec3f(t_vec3f vec)
{
	ft_putstr("x:");
	ft_putfloat(vec.x);
	ft_putstr(" y:");
	ft_putfloat(vec.y);
	ft_putstr(" z:");
	ft_putfloat(vec.z);
}

void	print_rgb(t_vec3f vec)
{
	ft_putstr("r:");
	ft_putfloat(vec.x);
	ft_putstr(" g:");
	ft_putfloat(vec.y);
	ft_putstr(" b:");
	ft_putfloat(vec.z);
}

void	print_object_common_attr(t_object *obj)
{
	ft_putstr("OBJECT [");
	ft_putstr(obj->id);
	ft_putstr("]\nTYPE:");
	ft_putstr(ret_type_strings()[obj->type]);
	ft_putstr("\nDEFORMATION: ");
	ft_putstr(ret_operation_names_array()[obj->deformation]);
	ft_putstr("\nPOSITION: ");
	print_tvec3f(obj->pos);
	ft_putstr("\nCOLOR: ");
	print_rgb(obj->col);
	ft_putstr("\nMATERIAL:");
	ft_putstr(ret_obj_material()[obj->material]);
	ft_putchar('\n');
}

void	print_object_list(t_object *obj, char *buff, t_rt_utils *utils)
{
	(void)utils;
	(void)buff;
	ft_putstr("active object list -> \n");
	obj_list_map(obj, NULL, &print_obj);
}

void	builtin_delete_object(t_object *obj, char *buff, t_rt_utils *utils)
{
	int			index;
	char		*id;
	t_object	swap;

	(void)utils;
	if (!(id = get_substring(buff, "id{", "}")))
		return ;
	if ((index = find_object_index(obj, id)) < 0)
		return ;
	swap = obj[index];
	ft_putstr("_____________\nlist before deletion:\n_____________\n");
	print_object_list(obj, buff, NULL);
	while (obj[index + 1].type != NONE)
	{
		swap = obj[index];
		obj[index] = obj[index + 1];
		obj[index + 1] = swap;
		index++;
	}
	obj[index].type = NONE;
	obj[index].id = NULL;
	ft_putstr("_____________\nlist after deletion:\n_____________\n");
	print_object_list(obj, buff, NULL);
	free(id);
	utils->nb_object -= 1;
}

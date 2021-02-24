/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_disp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:29:37 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 17:56:12 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../includes/rt.h"

t_e_disp		get_disp(char *data)
{
	int disp;

	disp = ft_bin_search_str((char**)ret_obj_disp(), data, __DISP_TOTAL);
	if (disp != -1)
		return (disp);
	message(BUILTIN_CREATE, NOT_FOUND, data, false);
	return (DISP_NONE);
}

void			get_disp_data(t_object *obj, char *buff)
{
	char *found_disp;
	char *found_disp_i;

	found_disp = get_substring(buff, "disp{", "}");
	if (found_disp && ft_strcmp(found_disp, "none") != 0)
		obj->disp = get_disp(found_disp);
	else
	{
		set_default_disp(obj);
		obj->disp_data[obj->disp] = 0;
		free(found_disp);
		return ;
	}
	free(found_disp);
	found_disp_i = get_substring(buff, "disp_intensity{", "}");
	if (found_disp_i != NULL)
		obj->disp_data[obj->disp] = atof(found_disp_i);
	else
		obj->disp_data[obj->disp] = 3;
	free(found_disp_i);
	ft_putstr(">>> ");
	ft_putendl(ret_obj_disp()[obj->disp]);
}

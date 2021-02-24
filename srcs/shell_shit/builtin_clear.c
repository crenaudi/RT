/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:44:10 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 18:42:55 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	init_object(t_object *object)
{
	ft_bzero(object, sizeof(t_object));
	object->type = NONE;
	object->deformation = DEFNONE;
	object->material = MATERIAL_NONE;
}

void	builtin_clear(t_object *obj, char *buff, t_rt_utils *utils)
{
	int		i;

	(void)buff;
	(void)utils;
	i = 0;
	ft_putstr("[CLEAR] List before deletion: \n");
	print_object_list(obj, NULL, NULL);
	while (obj[i].type != NONE)
	{
		init_object(&obj[i]);
		i++;
	}
	ft_putstr("[CLEAR] List has been cleared.\n[CLEAR] List after deletion:\n");
	print_object_list(obj, NULL, NULL);
}

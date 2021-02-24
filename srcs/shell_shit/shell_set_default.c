/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:49:50 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 16:53:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../includes/rt_object.h"

void	set_default_id_obj(t_object *obj, t_object *obj_list)
{
	int		index;
	char	*id;

	index = get_last_index(obj_list);
	id = ft_strdup("object_00\0");
	if (10 < index)
	{
		id[8] = (index % 10) + '0';
		index = index / 10;
	}
	if (index < 10)
		id[9] = index + '0';
	obj->id = id;
}

char	*set_default_id_utils(t_op_utils *obj, t_object *obj_list)
{
	int		index;
	char	*id;
	char	digit;

	(void)obj;
	digit = '0';
	if (!(id = (char*)malloc(10 * sizeof(char))))
		return (NULL);
	ft_bzero(id, 10 * sizeof(char));
	index = get_last_index(obj_list);
	strcpy(id, "object_00");
	if (10 < index)
	{
		digit = (index / 10) + '0';
		id[7] = digit;
		index = index % 10;
	}
	if (index < 10)
	{
		digit = index + '0';
		id[8] = digit;
	}
	return (id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:48:17 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 16:51:24 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"

t_object	*find_object_by_id(t_object *obj, char *id_to_find)
{
	t_object *traveller;

	traveller = obj;
	ft_putstr("[find_object_by id _ debug] looking for id = ");
	ft_putendl(id_to_find);
	while (traveller->type != NONE)
	{
		if (ft_strcmp(traveller->id, id_to_find) == 0)
		{
			ft_putstr("[find_object_by id _ debug] traveller->id : ");
			ft_putendl(traveller->id);
			break ;
		}
		traveller++;
	}
	if (traveller->type == NONE)
	{
		ft_putstr("[find_object_by_id] Object of ID[");
		ft_putstr(obj->id);
		ft_putstr("] could not be find among working obj_list\n");
		return (NULL);
	}
	return (traveller);
}

t_object	*obj_list_map(t_object *obj, void *private,
	void (*f)(t_object *, void *))
{
	t_object *traveller;

	traveller = obj;
	while (traveller->type != NONE)
	{
		f(traveller, private);
		traveller++;
	}
	return (obj);
}

int			find_object_index(t_object *obj_list, char *id)
{
	int index;

	index = 0;
	while (obj_list[index].type != NONE)
	{
		if (ft_strcmp(obj_list[index].id, id) == 0)
			return (index);
		index++;
	}
	ft_putstr("no id match for id [");
	ft_putstr(id);
	ft_putstr("] in working object list\n");
	return (-1);
}

int			get_last_index(t_object *obj_list)
{
	int index;

	index = 0;
	while (obj_list[index].type != NONE && index < 100)
		index++;
	return (index);
}

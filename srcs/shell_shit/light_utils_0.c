/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:31:31 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 18:09:16 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"

int				find_light_index(t_lights *light_list, char *id)
{
	size_t index;

	index = 0;
	while (index < light_list->num)
	{
		if (ft_strcmp(light_list->lights[index].id, id) == 0)
		{
			ft_putstr("[FIND_LIGHT_INDEX] found light of ID[");
			ft_putstr(id);
			ft_putstr("] in working light list\n");
			return ((int)index);
		}
		index++;
	}
	ft_putstr("[FIND_LIGHT_INDEX]no id match for id [");
	ft_putstr(id);
	ft_putstr("] in working light list\n");
	return (-1);
}

t_lightpoint	*find_light_by_id(t_lights *light, char *id_to_find)
{
	t_lightpoint	*traveller;
	size_t			i;

	traveller = light->lights;
	i = 0;
	while (i < light->num)
	{
		if (ft_strcmp(traveller->id, id_to_find) == 0)
		{
			ft_putstr("[FIND_LIGHT_BY_ID] Light of id{");
			ft_putstr(id_to_find);
			ft_putstr("} found among working light_list\n");
			return (traveller);
		}
		traveller++;
		i++;
	}
	ft_putstr("[FIND_LIGHT_BY_ID] Light of id{");
	ft_putstr(id_to_find);
	ft_putstr("} could not be find among working light_list\n");
	return (NULL);
}

void			print_light_attr(t_lightpoint *light)
{
	ft_putstr("LIGHT [");
	ft_putstr(light->id);
	ft_putstr("]\nPOSITION: ");
	print_tvec3f(light->light_data.origin);
	ft_putstr("\nINTENSITY: ");
	print_tvec3f(light->light_data.direction);
	ft_putchar('\n');
}

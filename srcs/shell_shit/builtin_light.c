/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:32:58 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 18:21:22 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	builtin_create_light(t_object *obj, char *buff, t_rt_utils *utils)
{
	size_t		index;

	(void)obj;
	if ((index = utils->lights->num) == 10)
	{
		ft_putstr("[CREATE_LIGHT] Could not create new\
			light as current light list is full, please delete some lights\
			to create make room for new ones.\n");
		return ;
	}
	if (!(utils->lights->lights[index].id = get_substring(buff, "id{", "}")))
		utils->lights->lights[index].id =
			set_default_id_light(utils->lights->num);
	parse_light(buff, utils->lights->lights + index, 0);
	utils->lights->num++;
}

void	builtin_print_light(t_object *obj, char *buff, t_rt_utils *utils)
{
	char			*id;
	t_lightpoint	*traveller;

	(void)utils;
	(void)obj;
	id = NULL;
	if (!(id = get_substring(buff, "id{", "}")))
		ft_putstr("[PRINT_LIGHT] Light ID required to print attributes\n");
	if (id)
	{
		if (!(traveller = find_light_by_id(utils->lights, id)))
		{
			ft_putstr("[PRINT_LIGHT] Could not find light with ID [");
			ft_putstr(id);
			ft_putstr("], please enter valid ID\n");
			return ;
		}
		print_light_attr(traveller);
	}
}

void	builtin_print_light_list(t_object *obj, char *buff, t_rt_utils *utils)
{
	size_t			i;

	(void)obj;
	(void)buff;
	i = 0;
	ft_putstr("[PRINT_LIGHT_LIST] active light list -> \n");
	if (utils->lights->num == 0)
		message(BUILTIN_PRINT_LIGHT_LIST, NOT_FOUND, " empty list", false);
	while (i < utils->lights->num)
	{
		ft_putstr(utils->lights->lights[i].id);
		ft_putstr("\n");
		i++;
	}
}

void	builtin_delete_light(t_object *obj, char *buff, t_rt_utils *utils)
{
	size_t			index;
	char			*id;
	t_lightpoint	swap;

	(void)obj;
	id = get_substring(buff, "id{", "}");
	if (!id)
	{
		ft_putstr("[DELETE_LIGHT] Light ID needed.\n");
		return ;
	}
	if (((index = (size_t)find_light_index(utils->lights, id)) + 1) == 0)
	{
		message(BUILTIN_DELETE_LIGHT, NOT_FOUND, id, false);
		return ;
	}
	while (index < utils->lights->num)
	{
		swap = utils->lights->lights[index];
		utils->lights->lights[index] = utils->lights->lights[index + 1];
		utils->lights->lights[index + 1] = swap;
		index++;
	}
	utils->lights->num--;
	init_light(&utils->lights->lights[index]);
}

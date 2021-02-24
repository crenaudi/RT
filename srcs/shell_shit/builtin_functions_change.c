/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_change.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:45:11 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 16:04:23 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

const char	**ret_operation_names_array(void)
{
	static const char *operation_names_array[__DEFORMATION_TOTAL] = {
		"inter",
		"none",
		"s_inter",
		"s_sub",
		"s_uni",
		"sub",
		"uni"};

	return (&operation_names_array[0]);
}

void		builtin_apply_op(t_object *obj, char *buff, t_rt_utils *utils)
{
	(void)utils;
	(void)obj;
	(void)buff;
	ft_putendl("Apply_OP disabled during instance");
	ft_putendl("Please apply OP directly in the .rt file");
}

void		builtin_change_id(t_object *obj, char *buff, t_rt_utils *utils)
{
	char		*id1;
	char		*id2;
	t_object	*traveller;

	(void)utils;
	if (!(id1 = get_substring(buff, "id1{", "}"))
		|| !(id2 = get_substring(buff, "id2{", "}")))
		message(BUILTIN_CHANGE_ID, CHANGE_FOCUS_OBJ_NO_ID, NULL, false);
	if (id1 && id2)
	{
		if (!(traveller = find_object_by_id(obj, id1)))
		{
			message(BUILTIN_CHANGE_ID, OBJ_NOT_FOUND, id1, false);
			free(id1);
			return ;
		}
		if (!(ft_strlen(id2)))
		{
			message(BUILTIN_CHANGE_ID, WRONG_INPUT, "id2", false);
			free(id1);
			return ;
		}
		traveller->id = id2;
	}
	free(id1);
}

void		builtin_change_order(t_object *obj, char *buff, t_rt_utils *utils)
{
	t_op_utils	swap;
	t_object	*traveller_src;
	t_object	*traveller_dst;
	t_object	tmp;

	(void)utils;
	parse_args(&swap, buff, (char *[2]){"id{", "id2{"}, (char *[2]){"}", "}"});
	traveller_src = find_object_by_id(obj, swap.id);
	traveller_dst = find_object_by_id(obj, swap.operation);
	if (traveller_src == NULL || traveller_dst == NULL)
		message(BUILTIN_CHANGE_ORDER, NOT_FOUND, "one obj in the list", false);
	else
	{
		print_object_list(obj, NULL, NULL);
		if (traveller_src->type != NONE && traveller_dst->type != NONE)
		{
			tmp = *traveller_src;
			*traveller_src = *traveller_dst;
			*traveller_dst = tmp;
		}
		else
			ft_putstr("Could not swap as one of the objects was none.\n");
		print_object_list(obj, NULL, NULL);
	}
}

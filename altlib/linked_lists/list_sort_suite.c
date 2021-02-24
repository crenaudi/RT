/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:44:57 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"

static void	list_sort_single_pass(t_list *list, t_e_sort_type sort_type)
{
	t_list *traveller;
	t_list *prev_traveller;

	traveller = list->next;
	prev_traveller = list;
	while (traveller)
	{
		if (list_cmp_functions[sort_type](prev_traveller, traveller) == false)
			list_swap_links(&prev_traveller, &traveller);
		traveller = traveller->next;
		prev_traveller = prev_traveller->next;
	}
}

void		list_sort(t_list *list, t_e_sort_type sort_type,
	bool (*custom_function)(t_list *, t_list *))
{
	if (custom_function && sort_type == CUSTOM_CMP)
		list_cmp_functions[0] = custom_function;
	while (!list_check_is_sorted(list, sort_type))
		list_sort_single_pass(list, sort_type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:45:31 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"

static bool	list_compare_links_str(t_list *link_a, t_list *link_b)
{
	int cmp_value;

	cmp_value = ft_strcmp(link_a->data, link_b->data);
	if (cmp_value < 0)
		return (true);
	return (false);
}

static bool	list_compare_links_num(t_list *link_a, t_list *link_b)
{
	if (link_a->data < link_b->data)
		return (true);
	return (false);
}

static bool	(*g_list_cmp_functions[3])(t_list *, t_list *) = {
	NULL,
	&list_compare_links_str,
	&list_compare_links_num,
};

static void	list_swap_links(t_list **link_a, t_list **link_b)
{
	t_list	*link_tmp;

	link_tmp = *link_a;
	*link_a = *link_b;
	*link_b = link_tmp;
}

bool		list_check_is_sorted(t_list *list, t_e_sort_type sort_type)
{
	t_list *traveller;
	t_list *prev_traveller;

	traveller = list->next;
	prev_traveller = list;
	while (traveller)
	{
		if (list_cmp_functions[sort_type](prev_traveller, traveller) == true)
			traveller = traveller->next;
		else
			return (false);
	}
	return (true);
}

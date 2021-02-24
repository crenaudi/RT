/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappable_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:31:31 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 18:09:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"

void		print_obj(t_object *obj_list, void *nothing)
{
	(void)nothing;
	if (obj_list->id)
		ft_putstr(obj_list->id);
	else
		ft_putstr("obj id was not found.");
	ft_putstr("\n");
}

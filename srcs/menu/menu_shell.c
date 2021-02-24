/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:27:25 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"
#include "../shell_shit/shell.h"

bool		rt_shell(t_rt_utils *rt, t_menu *menu, char *storage)
{
	int		i;

	ft_strclean(storage);
	i = ft_bin_search_str((char **)ret_builtin_names(),
	ft_strnext(storage, true), BUILTIN_TOTAL);
	if (i == -1)
		ft_putstr("command not found\n");
	else if (i == BUILTIN_FREECAM)
		return (false);
	else
	{
		if (ft_strstr(storage, "quit") != NULL)
			close_menu(menu);
		builtin_caller(i, rt->obj, storage, rt);
		if (ft_strstr(storage, "display") != NULL)
		{
			clear_menu(menu);
			return (false);
		}
	}
	return (true);
}

bool		rt_shell_inputbox(t_rt_utils *rt, t_menu *menu)
{
	bool	state;

	ft_putstr("[SHELL] :");
	ft_putendl(menu->iinput->storage);
	state = rt_shell(rt, menu, menu->iinput->storage);
	clear_input(menu->iinput);
	menu->ncmd = -1;
	menu->state = MENU_ACTIVE;
	return (state);
}

bool		rt_shell_chatbox(t_rt_utils *rt, t_menu *menu)
{
	bool	ret;

	ft_putstr("[SHELL] :");
	ft_putendl(menu->ichatbox->storage);
	ret = rt_shell(rt, menu, menu->ichatbox->storage);
	clear_chatbox(menu->ichatbox);
	return (ret);
}

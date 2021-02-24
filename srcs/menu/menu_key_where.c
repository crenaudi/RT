/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:36:36 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

int				key_press_menu(t_menu *menu, int utils[3])
{
	if (hit_hitbox(menu->txs[NAVBAR]->hitbox, utils[0], utils[1]))
	{
		if (utils[0] < (SCREEN_W / 2))
		{
			if (utils[2] == 1)
				menu->state = MENU_ACTIVE | MENU_INFO;
			return (2);
		}
		else
		{
			if (utils[2] == 1)
				menu->state = MENU_ACTIVE | MENU_COMD;
			return (1);
		}
	}
	return (0);
}

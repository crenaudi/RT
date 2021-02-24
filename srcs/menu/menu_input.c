/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_inpubox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:13:06 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

bool			show_input(t_menu *menu, int utils[3])
{
	if (hit_hitbox(menu->iinput->hitbox_valide, utils[0], utils[1]))
	{
		put_tx(menu, menu->txs[INPUT], 1, menu->txs[INPUT]->pos);
		if (utils[2] == 1)
		{
			valide_onprocess_input(menu, menu->iinput->str);
			return (false);
		}
	}
	else if (hit_hitbox(menu->iinput->hitbox_cancel, utils[0], utils[1]))
	{
		put_tx(menu, menu->txs[INPUT], 2, menu->txs[INPUT]->pos);
		if (utils[2] == 1)
		{
			ft_putendl("[PROCESS] > abort");
			clear_input(menu->iinput);
			menu->ncmd = -1;
			menu->state = MENU_ACTIVE;
			return (false);
		}
	}
	else
		put_tx(menu, menu->txs[INPUT], 0, menu->txs[INPUT]->pos);
	return (true);
}

void			copy_twostorage(t_input *input, char *str1, char *str2)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(str1);
	copy_storage(input, str1);
	while (str2[++j])
		input->storage[i++] = str2[j];
}

void			copy_storage(t_input *input, char *src)
{
	int i;

	i = -1;
	if (!src)
		return ;
	ft_bzero(input->storage, sizeof(char) * BUFF_STORAGE);
	while (src[++i])
		input->storage[i] = src[i];
}

void			valide_onprocess_input(t_menu *menu, char *str)
{
	char	start[BUFF_STORAGE];
	char	end[BUFF_STORAGE];
	char	*ret;
	t_vec2	i;

	ft_bzero(start, sizeof(char) * BUFF_STORAGE);
	ft_bzero(end, sizeof(char) * BUFF_STORAGE);
	if (ft_strlen(str) != 0)
	{
		i = -1;
		while (++i.x < menu->iinput->ip)
			start[i.x] = menu->iinput->storage[i.x];
		i.x += 1;
		while (menu->iinput->storage[i.x])
			end[++i.y] = menu->iinput->storage[i.x++];
		ret = my_strcat(start, str);
		menu->iinput->ip = ft_strlen(ret);
		ret = my_strcat(ret, end);
		copy_storage(menu->iinput, ret);
	}
	ft_bzero(menu->iinput->str, sizeof(char) * 15);
	menu->iinput->step += 1;
	menu->iinput->ip += 1;
	menu->iinput->is = 0;
	menu->state ^= IPTB_VALIDE & IPTB_ACTIVE;
}

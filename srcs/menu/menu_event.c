/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:22:40 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"
#include "../../altlib/altlib.h"

bool	menu_state(t_rt_utils *rt, t_menu *menu, int utils[3], bool loop)
{
	int		state;

	if (loop)
	{
		state = key_press_menu(menu, utils);
		if ((menu->state & MENU_INFO) == MENU_INFO)
		{
			put_tx(menu, menu->txs[NAVBAR], 2, menu->txs[NAVBAR]->pos);
			put_tx(menu, menu->txs[INFO], 0, menu->txs[INFO]->pos);
			apply_surface_renderer(rt->sdl_objs->renderer, menu->screen);
		}
		else if ((menu->state & MENU_COMD) == MENU_COMD)
			loop = command(rt, menu, utils);
		else
		{
			put_tx(menu, menu->txs[NAVBAR], state, menu->txs[NAVBAR]->pos);
			apply_surface_renderer(rt->sdl_objs->renderer, menu->screen);
		}
	}
	else
		write_colors_to_image(rt->thr_data, rt->sdl_objs->renderer);
	return (loop);
}

bool	command(t_rt_utils *rt, t_menu *menu, int utils[3])
{
	put_tx(menu, menu->txs[NAVBAR], 1, menu->txs[NAVBAR]->pos);
	if (menu->ncmd == -1)
	{
		menu->ncmd = tx_btn(menu, utils, (t_vec2){18, 70}, BUILTIN_TOTAL);
		apply_surface_renderer(rt->sdl_objs->renderer, menu->screen);
		txt_btncmd(rt->sdl_objs->renderer, menu->ttf, (t_vec2){38, 76});
	}
	else
	{
		if ((menu->state & PROCESS_VALIDE) == PROCESS_VALIDE)
			return (rt_shell_inputbox(rt, menu));
		else
		{
			if ((menu->state & PROCESS_ACTIVE) != PROCESS_ACTIVE)
			{
				fill_input(menu->iinput, 0, menu->ncmd);
				menu->state |= PROCESS_ACTIVE;
			}
			process(rt->sdl_objs->renderer, menu, utils);
		}
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:21:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

static void		fill_opt(SDL_Renderer *renderer, t_menu *menu, int utils[3])
{
	int		select;
	t_vec2	margin;
	t_vec2	padding;

	margin = (t_vec2){122, 160};
	padding = (t_vec2){20, 6};
	select = tx_btn(menu, utils, margin, __DEFORMATION_TOTAL);
	apply_surface_renderer(renderer, menu->screen);
	margin += padding;
	txt_btnopt(renderer, menu->ttf, margin);
	if (select != -1)
		valide_onprocess_input(menu, ret_opt(select));
}

static void		fill_mat(SDL_Renderer *renderer, t_menu *menu, int utils[3])
{
	int		select;
	t_vec2	margin;
	t_vec2	padding;

	margin = (t_vec2){122, 160};
	padding = (t_vec2){20, 6};
	select = tx_btn(menu, utils, margin, __MATERIAL_TOTAL);
	apply_surface_renderer(renderer, menu->screen);
	margin += padding;
	txt_btnmat(renderer, menu->ttf, margin);
	if (select != -1)
		valide_onprocess_input(menu, ret_mat(select));
}

static void		fill_type(SDL_Renderer *renderer, t_menu *menu, int utils[3])
{
	int		select;
	t_vec2	margin;
	t_vec2	padding;

	margin = (t_vec2){122, 120};
	padding = (t_vec2){20, 6};
	select = tx_btn(menu, utils, margin, __SDF_TOTAL);
	apply_surface_renderer(renderer, menu->screen);
	margin += padding;
	txt_btnobj(renderer, menu->ttf, margin);
	if (select != -1)
	{
		find_create_process(menu->iinput, select);
		menu->ncmd_create = select;
		menu->iinput->ip = 0;
	}
}

void			process(SDL_Renderer *renderer, t_menu *menu, int utils[3])
{
	char	c;

	c = menu->iinput->storage[menu->iinput->ip];
	if (c == 'B' || c == 'S' || c == 'V')
	{
		menu->state |= IPTB_ACTIVE;
		if (!(fill_div(renderer, menu, utils, c)))
			return ;
		writeonscreen(renderer, menu->ttf, menu->iinput->str,
			menu->txs[INPUT]->pos + menu->iinput->padding);
	}
	else if (c == 'T')
		fill_type(renderer, menu, utils);
	else if (c == 'O')
		fill_opt(renderer, menu, utils);
	else if (c == 'M')
		fill_mat(renderer, menu, utils);
	else if (c == '\0')
		menu->state |= PROCESS_VALIDE;
	else
		menu->iinput->ip += 1;
}

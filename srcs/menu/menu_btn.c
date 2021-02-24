/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:19:00 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

int		tx_btn(t_menu *menu, int mutils[3], t_vec2 margin, int nb)
{
	int		i;
	t_vec2	pos;
	t_vec2	pad;

	i = -1;
	pad = 0;
	pos = margin;
	while (++i < nb)
	{
		pos = columns_btn(pos, margin, nb, i);
		init_hitbox(menu->txs[BTN], pos, menu->txs[BTN]->size, pad);
		if (hit_hitbox(menu->txs[BTN]->hitbox, mutils[0], mutils[1]))
		{
			put_tx(menu, menu->txs[BTN], 1, pos);
			if (mutils[2] == 1)
				return (i);
		}
		else
			put_tx(menu, menu->txs[BTN], 0, pos);
		pos.y += 31;
	}
	return (-1);
}

void	txt_btncmd(SDL_Renderer *renderer, t_sdl_font *ttf, t_vec2 origin)
{
	const char	**cmd;
	int			i;
	int			nbuilt;
	int			built_div[2];
	t_vec2		pos;

	nbuilt = BUILTIN_TOTAL;
	built_div[0] = nbuilt / 3;
	built_div[1] = built_div[0] * 2;
	cmd = ret_builtin_names();
	i = -1;
	pos = origin;
	while (++i < nbuilt)
	{
		if (i == built_div[0])
			pos = (t_vec2){origin.x + 200, origin.y};
		if (i == built_div[1])
			pos = (t_vec2){pos.x + 200, origin.y};
		writeonscreen(renderer, ttf, (char *)cmd[i], pos);
		pos.y += 31;
	}
}

void	txt_btnobj(SDL_Renderer *renderer, t_sdl_font *ttf, t_vec2 origin)
{
	const char	**obj;
	int			i;
	int			nsdf;
	int			sdf_div;
	t_vec2		pos;

	nsdf = __SDF_TOTAL;
	sdf_div = nsdf / 2;
	obj = ret_type_strings();
	i = -1;
	pos = origin;
	while (++i < nsdf)
	{
		if (i == sdf_div)
		{
			pos = origin;
			pos.x += 200;
		}
		writeonscreen(renderer, ttf, (char *)obj[i], pos);
		pos.y += 31;
	}
}

void	txt_btnmat(SDL_Renderer *renderer, t_sdl_font *ttf, t_vec2 origin)
{
	const char	**mat;
	int			i;
	int			nmat;
	int			mat_div;
	t_vec2		pos;

	nmat = __MATERIAL_TOTAL;
	mat_div = nmat / 2;
	mat = ret_obj_material();
	i = -1;
	pos = origin;
	while (++i < nmat)
	{
		if (i == mat_div)
		{
			pos = origin;
			pos.x += 200;
		}
		writeonscreen(renderer, ttf, (char *)mat[i], pos);
		pos.y += 31;
	}
}

void	txt_btnopt(SDL_Renderer *renderer, t_sdl_font *ttf, t_vec2 origin)
{
	const char	**opt;
	int			i;
	int			nopt;
	int			opt_div;
	t_vec2		pos;

	nopt = __DEFORMATION_TOTAL;
	opt_div = nopt / 2;
	opt = ret_operation_names_array();
	i = -1;
	pos = origin;
	while (++i < nopt)
	{
		if (i == opt_div)
		{
			pos = origin;
			pos.x += 200;
		}
		writeonscreen(renderer, ttf, (char *)opt[i], pos);
		pos.y += 31;
	}
}

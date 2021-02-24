/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_dfltm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:17:22 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void	dfltm_rotate(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];

	deflt[0] = "Nommez l element";
	deflt[1] = "Entrez rotation en x";
	deflt[2] = "Entrez rotation en y";
	deflt[3] = "Entrez rotation en z";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	dfltm_translate(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];

	deflt[0] = "Nommez l element dont vous souhaitez modifier la position";
	deflt[1] = "Entrez translation en x";
	deflt[2] = "Entrez translation en y";
	deflt[3] = "Entrez translation en z";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

t_vec2	columns_btn(t_vec2 origin, t_vec2 margin, int nb, int i)
{
	int		columns;
	t_vec2	pos;

	pos = origin;
	if (nb > 15)
	{
		columns = nb / 3;
		if (i == columns)
		{
			pos.x = margin.x + 203;
			pos.y = margin.y;
		}
		if (i == columns * 2)
		{
			pos.x = origin.x + 203;
			pos.y = margin.y;
		}
	}
	else
	{
		if (i == nb / 2)
			pos = (t_vec2){origin.x + 203, margin.y};
	}
	return (pos);
}

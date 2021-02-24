/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:14:18 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

int		lerp_color(t_rtcolor s, t_rtcolor e, float t)
{
	int	r;
	int	g;
	int	b;

	if (s.color == e.color)
		return (s.color);
	r = (int)(s.bgra[2] + (e.bgra[2] - s.bgra[2]) * t);
	g = (int)(s.bgra[1] + (e.bgra[1] - s.bgra[1]) * t);
	b = (int)(s.bgra[0] + (e.bgra[0] - s.bgra[0]) * t);
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	put_tx(t_menu *menu, t_texture *tx, int frame, t_vec2 pos)
{
	t_vec2		i;
	int			iscreen;
	t_rtcolor	c1;
	t_rtcolor	c2;

	i.y = -1;
	while (++i.y < tx->size.y)
	{
		i.x = -1;
		while (++i.x < tx->size.x)
		{
			iscreen = ((i.y + pos.y) * SCREEN_W + (i.x + pos.x)) * 4;
			c2.color = tx->frames[frame][i.y * tx->size.x + i.x];
			c1.color = *(int *)(menu->screen->pixels + iscreen);
			if (c2.bgra[3] == 255 || c1.bgra[3] == 0)
				*(int *)(menu->screen->pixels + iscreen) = c2.color;
			if (c2.bgra[3] < 255 && c2.bgra[3] > 0)
			{
				*(int *)(menu->screen->pixels + iscreen) =
					lerp_color(c1, c2, (float)(1 * c2.bgra[3]) / 255.);
			}
			if (c2.color == 0 || c2.bgra[3] == 0)
				*(int *)(menu->screen->pixels + iscreen) = c1.color;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bitwase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:09:10 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

static unsigned int		positionbymask(unsigned int mask)
{
	return (countbymask((mask & (~mask + 1)) - 1));
}

static unsigned int		counttomask(unsigned int bitcount)
{
	return ((bitcount == 32) ? 0xFFFFFFFF : (1 << bitcount) - 1);
}

unsigned int			countbymask(unsigned int mask)
{
	unsigned int bitcount;

	bitcount = 0;
	while (mask)
	{
		mask &= mask - 1;
		bitcount++;
	}
	return (bitcount);
}

unsigned int			component_mask(unsigned int color, unsigned int mask)
{
	unsigned int component;

	component = color & mask;
	return (component >> positionbymask(mask));
}

unsigned int			convertcolor(unsigned int color,
	unsigned int frontbitcount, unsigned int tobitcount)
{
	if (tobitcount < frontbitcount)
		color >>= (frontbitcount - tobitcount);
	else
	{
		color <<= (tobitcount - frontbitcount);
		if (color > 0)
			color |= counttomask(tobitcount - frontbitcount);
	}
	return (color);
}

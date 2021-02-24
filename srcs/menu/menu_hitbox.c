/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hitbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:24:55 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void	clear_hitbox(t_texture *tx)
{
	tx->hitbox[0] = 0;
	tx->hitbox[1] = 0;
	tx->hitbox[2] = 0;
	tx->hitbox[3] = 0;
}

void	init_hitbox(t_texture *tx, t_vec2 pos, t_vec2 size, t_vec2 pad)
{
	tx->hitbox[0] = pos.x + pad.x;
	tx->hitbox[1] = pos.x + size.x + pad.x;
	tx->hitbox[2] = pos.y + pad.y;
	tx->hitbox[3] = pos.y + size.y + pad.y;
}

bool	hit_hitbox(int hitbox[4], int x, int y)
{
	if (hitbox[0] <= 0 && hitbox[1] && hitbox[2] && hitbox[3])
		return (false);
	if (x >= hitbox[0] && x <= hitbox[1] && y >= hitbox[2] && y <= hitbox[3])
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 14:59:31 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

void	vec2f_copy(t_vec2f *dest, t_vec2f src)
{
	dest->x = src.x;
	dest->y = src.y;
}

void	vec2f_set(t_vec2f *dest, float x, float y)
{
	dest->x = x;
	dest->y = y;
}

t_vec2f	vec2f_add(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = b.x + a.x;
	new.y = b.y + a.y;
	return (new);
}

t_vec2f	vec2f_sub(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	return (new);
}

t_vec2f	vec2f_div_k(t_vec2f a, float k)
{
	t_vec2f new;

	new.x = a.x / k;
	new.y = a.y / k;
	return (new);
}

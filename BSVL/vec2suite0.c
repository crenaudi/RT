/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 14:59:17 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

float	vec2f_dist_origin(t_vec2f a)
{
	float x;
	float y;

	x = a.x * a.x;
	y = a.y * a.y;
	return (sqrt(x + y));
}

t_vec2f	vec2f_normalize(t_vec2f a)
{
	float	vec_len;
	t_vec2f	vec;

	vec_len = vec2f_dist_origin(a);
	vec = vec2f_div_k(a, vec_len);
	return (vec);
}

float	vec2f_dist_ab(t_vec2f a, t_vec2f b)
{
	float x;
	float y;

	x = (b.x - a.x) * (b.x - a.x);
	y = (b.y - a.y) * (b.y - a.y);
	return (sqrt(x + y));
}

t_vec2f	vec2f_apply_fn_float(t_vec2f a, float (*fn)(float k))
{
	t_vec2f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	return (new);
}

t_vec2f	vec2f_apply_fn_int(t_vec2f a, int (*fn)(float k))
{
	t_vec2f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	return (new);
}

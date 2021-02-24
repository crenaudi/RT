/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 14:58:43 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

t_vec2f	vec2f_mul_vec(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	return (new);
}

t_vec2f	vec2f_mul_mat2f(t_vec2f a, t_vec2f mat[2])
{
	t_vec2f res;
	t_vec2f l1;
	t_vec2f l2;

	l1 = vec2f_mul_vec(a, (t_vec2f){mat[0].x, mat[1].x});
	l2 = vec2f_mul_vec(a, (t_vec2f){mat[0].y, mat[1].y});
	res = (t_vec2f){l1.x + l1.y, l2.x + l2.y};
	return (res);
}

t_vec2f	vec2f_mul_k(t_vec2f a, float k)
{
	t_vec2f new;

	new.x = a.x * k;
	new.y = a.y * k;
	return (new);
}

t_vec2f	vec2f_div_vec(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x / b.x;
	new.y = a.y / b.y;
	return (new);
}

float	vec2f_dotprod(t_vec2f a, t_vec2f b)
{
	t_vec2f	dest;
	float	res;

	dest.x = a.x * b.x;
	dest.y = a.y * b.y;
	res = dest.x + dest.y;
	return (res);
}

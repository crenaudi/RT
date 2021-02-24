/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/06 23:38:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

float	vec3f_dotprod(t_vec3f a, t_vec3f b)
{
	t_vec3f	dest;
	float	res;

	dest.x = a.x * b.x;
	dest.y = a.y * b.y;
	dest.z = a.z * b.z;
	res = dest.x + dest.y + dest.z;
	return (res);
}

t_vec3f	vec3f_crossprod(t_vec3f a, t_vec3f b)
{
	t_vec3f	dest;

	dest.x = a.y * b.z - b.y * a.z;
	dest.y = a.z * b.x - b.z * a.x;
	dest.z = a.x * b.y - b.x * a.y;
	return (dest);
}

t_vec3f	vec3f_normalize(t_vec3f a)
{
	float	vec_len;
	t_vec3f	vec;

	vec_len = vec3f_dist_origin(a);
	vec.x = a.x / vec_len;
	vec.y = a.y / vec_len;
	vec.z = a.z / vec_len;
	return (vec);
}

float	vec3f_dist_origin(t_vec3f a)
{
	float x;
	float y;
	float z;

	x = a.x * a.x;
	y = a.y * a.y;
	z = a.z * a.z;
	return (sqrt(x + y + z));
}

float	vec3f_dist_ab(t_vec3f a, t_vec3f b)
{
	float x;
	float y;
	float z;

	x = (b.x - a.x) * (b.x - a.x);
	y = (b.y - a.y) * (b.y - a.y);
	z = (b.z - a.z) * (b.z - a.z);
	return (sqrt(x + y + z));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 14:59:05 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

t_vec3f	vec3f_mul_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x * k;
	new.y = a.y * k;
	new.z = a.z * k;
	return (new);
}

void	vec3f_copy(t_vec3f *dest, t_vec3f src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_vec3f	vec3f_apply_fn_int(t_vec3f a, int (*fn)(int k))
{
	t_vec3f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	new.z = fn(a.z);
	return (new);
}

void	get_roll_matrix(float theta, t_vec3f mat[static 3])
{
	mat[0] = (t_vec3f){1, 0, 0};
	mat[1] = (t_vec3f){0, cos(theta), -sin(theta)};
	mat[2] = (t_vec3f){0, sin(theta), cos(theta)};
}

t_vec3f	vec3f_div_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x / k;
	new.y = a.y / k;
	new.z = a.z / k;
	return (new);
}

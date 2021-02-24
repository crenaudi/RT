/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/06 23:45:43 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

t_vec3f	vec3f_apply_fn_float(t_vec3f a, float (*fn)(float k))
{
	t_vec3f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	new.z = fn(a.z);
	return (new);
}

t_vec3f	vec3f_max(t_vec3f a, t_vec3f b)
{
	t_vec3f vector;

	vector.x = max(a.x, b.x);
	vector.y = max(a.y, b.y);
	vector.z = max(a.z, b.z);
	return (vector);
}

t_vec3f	vec3f_min(t_vec3f a, t_vec3f b)
{
	t_vec3f vector;

	vector.x = min(a.x, b.x);
	vector.y = min(a.y, b.y);
	vector.z = min(a.z, b.z);
	return (vector);
}

t_vec3f	vec3f_mul_mat3(t_vec3f a, t_vec3f mat[3])
{
	t_vec3f	tmp;
	t_vec3f	res;

	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].x, mat[1].x, mat[2].x});
	res.x = tmp.x + tmp.y + tmp.z;
	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].y, mat[1].y, mat[2].y});
	res.y = tmp.x + tmp.y + tmp.z;
	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].z, mat[1].z, mat[2].z});
	res.z = tmp.x + tmp.y + tmp.z;
	return (res);
}

t_vec3f	vec3f_mul_mat4f(t_vec3f a, t_vec4f mat[static 4])
{
	t_vec4f tmp;

	tmp = (t_vec4f){a.x, a.y, a.z, 1};
	tmp = vec4f_mul_mat4f(tmp, mat);
	return ((t_vec3f){tmp.x, tmp.y, tmp.z});
}

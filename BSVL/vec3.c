/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/06 23:57:35 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

t_vec3f	vec3f_div_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x / b.x;
	new.y = a.y / b.y;
	new.z = a.z / b.z;
	return (new);
}

t_vec3f	vec3f_mod_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = fmod(a.x, b.x);
	new.y = fmod(a.y, b.y);
	new.z = fmod(a.z, b.z);
	return (new);
}

t_vec3f	vec3f_mod_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = fmod(a.x, k);
	new.y = fmod(a.y, k);
	new.z = fmod(a.z, k);
	return (new);
}

t_vec3f	vec3f_mul_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	return (new);
}

void	get_vec3_identity_matrix(t_vec3f mat[static 3])
{
	mat[0] = (t_vec3f){1, 0, 0};
	mat[1] = (t_vec3f){0, 1, 0};
	mat[2] = (t_vec3f){0, 0, 1};
}

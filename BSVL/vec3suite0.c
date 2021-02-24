/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/06 23:41:38 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

void	vec3f_set(t_vec3f *dest, float x, float y, float z)
{
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

t_vec3f	vec3f_add_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = b.x + a.x;
	new.y = b.y + a.y;
	new.z = b.z + a.z;
	return (new);
}

t_vec3f	vec3f_add_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x + k;
	new.y = a.y + k;
	new.z = a.z + k;
	return (new);
}

t_vec3f	vec3f_sub_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_vec3f	vec3f_sub_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x - k;
	new.y = a.y - k;
	new.z = a.z - k;
	return (new);
}

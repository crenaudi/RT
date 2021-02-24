/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_displacement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_displacements.h"

float	displace_perlin(t_object *obj, t_vec3f p, float k)
{
	(void)obj;
	(void)p;
	(void)k;
	return (0);
}

float	displace_sin(t_object *obj, t_vec3f p, float k)
{
	float d2;

	d2 = sin(k * p.x) * sin(k * p.y) * sin(k * p.z);
	return (sdf_caller(obj->type, p, *obj) + d2);
}

float	displace_twist(t_object *obj, t_vec3f p, float k)
{
	t_vec2f harmonics;
	t_vec2f m[2];
	t_vec2f	j;
	t_vec3f	q;

	harmonics = (t_vec2f){cos(k * p.y), sin(k * p.y)};
	m[0] = (t_vec2f){harmonics.x, -harmonics.y};
	m[1] = (t_vec2f){harmonics.y, harmonics.x};
	j = vec2f_mul_mat2f((t_vec2f){p.x, p.z}, m);
	q = (t_vec3f){j.x, p.y, j.y};
	return (sdf_caller(obj->type, q, *obj));
}

float	displace_bend(t_object *obj, t_vec3f p, float k)
{
	t_vec2f harmonics;
	t_vec2f m[2];
	t_vec2f	j;
	t_vec3f	q;

	harmonics = (t_vec2f){cos(k * p.x), sin(k * p.x)};
	m[0] = (t_vec2f){harmonics[0], -harmonics[1]};
	m[1] = (t_vec2f){harmonics[1], harmonics[0]};
	j = vec2f_mul_mat2f((t_vec2f){p.x, p.y}, m);
	q = (t_vec3f){j.x, j.y, p.z};
	return (sdf_caller(obj->type, q, *obj));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdfunctions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include <math.h>

float	sdf_cone(t_vec3f p, t_object obj)
{
	float q;

	q = vec2f_dist_origin((t_vec2f){p.x, p.z});
	return (vec2f_dotprod(obj.data.cone.c, (t_vec2f){q, p.y}));
}

float	sdf_capsule(t_vec3f origin, t_object obj)
{
	t_vec3f	ab;
	t_vec3f	ap;
	float	t;
	t_vec3f c;
	float	dist;

	ab = vec3f_sub_vec(obj.data.capsule.b, obj.data.capsule.a);
	ap = vec3f_sub_vec(origin, obj.data.capsule.a);
	t = vec3f_dotprod(ap, ab) / vec3f_dotprod(ab, ab);
	t = clamp(t, 1.0, 0.0);
	c = vec3f_add_vec(obj.data.capsule.a, vec3f_mul_k(ab, t));
	dist = vec3f_dist_origin(vec3f_sub_vec(origin, c));
	return (dist - obj.data.capsule.r);
}

float	sdf_ellipsoid(t_vec3f p, t_object obj)
{
	float k0;
	float k1;

	k0 = vec3f_dist_origin(vec3f_div_vec(p, obj.data.ellipsoid.r));
	k1 = vec3f_dist_origin(vec3f_div_vec(p,
		vec3f_mul_vec(obj.data.ellipsoid.r, obj.data.ellipsoid.r)));
	return (k0 * (k0 - 1.0) / k1);
}

float	sdf_cylinder(t_vec3f p, t_object obj)
{
	return (max(fabsf(p.z) - (obj.data.cylinder.heigth / 2),
		vec2f_dist_origin((t_vec2f){p.x, p.y}) - obj.data.cylinder.r));
}

float	sdf_custom(t_vec3f p, t_object obj)
{
	(void)p;
	(void)obj;
	return (0);
}

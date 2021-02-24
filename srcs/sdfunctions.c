/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdfucntions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include <math.h>

float	sdf_sphere(t_vec3f origin, t_object obj)
{
	return (vec3f_dist_ab(origin, obj.pos) - obj.data.sphere.rad);
}

float	sdf_torus(t_vec3f p, t_object obj)
{
	float q;

	q = (vec2f_dist_ab((t_vec2f){p.x, p.z}, (t_vec2f){obj.pos.x,
				obj.pos.y}))
		- obj.data.torus.r.x;
	return (vec2f_dist_origin((t_vec2f){q, p.y}) - obj.data.torus.r.y);
}

float	sdf_octahedron(t_vec3f p, t_object obj)
{
	p = vec3f_apply_fn_float(p, fabsf);
	return (p.x + p.y + p.z - obj.data.octa.s) * 0.57735027;
}

float	sdf_plane(t_vec3f p, t_object obj)
{
	return (vec3f_dotprod(p, vec3f_normalize(obj.data.plane.orientation))
			+ obj.data.plane.h);
}

float	sdf_box(t_vec3f p, t_object obj)
{
	t_vec3f d;

	d = vec3f_sub_vec(vec3f_apply_fn_float(p, fabsf), obj.data.cube.b);
	return (min(max(d.x, max(d.y, d.z)), 0.0) + vec3f_dist_origin((vec3f_max(d
						, (t_vec3f){0.0, 0.0, 0.0}))));
}

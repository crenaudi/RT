/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_lights.h"

bool		check_limits(float to_origin, float to_scene)
{
	if (to_origin > MAX_DIST || to_scene < SURFACE_DIST)
		return (true);
	return (false);
}

void		apply_fresnel(t_intersect_data *inter,
				t_vec3f frescolor, t_vec3f *color)
{
	float fres;

	fres = vec3f_dotprod(inter->normal, inter->intersect_pos);
	fres = clamp(fres, 255, 0);
	fres = pow(fres, 1.2);
	frescolor = vec3f_mul_k(frescolor, fres);
	*color = vec3f_add_vec(*color, frescolor);
}

float		get_shadow(t_intersect_data *inter, t_object *obj, size_t i)
{
	t_ray				shadow;
	t_intersect_data	dist;
	t_vec3f				point;
	t_vec3f				l;
	float				dotln;

	point = inter->intersect_pos;
	l = vec3f_normalize(vec3f_sub_vec(inter->l->lights[i].light_data.origin,
							point));
	dotln = vec3f_dotprod(l, inter->normal);
	if (dotln < 0)
		return (0);
	shadow.origin = vec3f_sub_vec(inter->l->lights[i].light_data.origin,
						vec3f_normalize(vec3f_sub_vec(point,
						inter->l->lights[i].light_data.origin)));
	shadow.direction = vec3f_normalize(vec3f_sub_vec(point,
						inter->l->lights[i].light_data.origin));
	dist = ray_march(shadow, obj);
	if (dist.dist < vec3f_dist_ab(point, inter->l->lights[i].light_data.origin)
					&& dist.material != MATERIAL_GLASS)
		return (1);
	return (0);
}

t_vec3f		phong_contrib(t_ray diff_spec,
					t_ray lpos_lint,
					t_intersect_data inter_data)
{
	t_vec3f		vectors[4];
	float		dotln;
	float		dotrv;
	t_ray		dsc;

	vectors[0] = inter_data.normal;
	vectors[1] = vec3f_normalize(vec3f_sub_vec(lpos_lint.origin,
							inter_data.intersect_pos));
	vectors[2] = vec3f_normalize(vec3f_sub_vec(lpos_lint.origin,
							inter_data.intersect_pos));
	vectors[3] = vec3f_normalize(reflect(vec3f_mul_k(vectors[1], -1),
							vectors[0]));
	dotln = vec3f_dotprod(vectors[1], vectors[0]);
	dotrv = vec3f_dotprod(vectors[3], vectors[2]);
	dsc.origin = vec3f_mul_k(diff_spec.origin, dotln);
	dsc.direction = vec3f_mul_k(diff_spec.direction, inter_data.shininess
					* pow(dotrv, 32));
	if (dotln < 0.0)
		return (t_vec3f){0, 0, 0};
	if (dotrv < 0.0)
		return (vec3f_mul_vec(lpos_lint.direction, dsc.origin));
	return (vec3f_mul_vec(lpos_lint.direction,
					vec3f_add_vec(dsc.origin, dsc.direction)));
}

t_vec3f		phong_illumination(t_vec3f amb_col,
					t_ray diff_spec,
					t_intersect_data inter_data)
{
	t_vec3f		amb_intensity;
	t_vec3f		color;
	size_t		i;

	i = 0;
	amb_intensity = (t_vec3f){10, 10, 10};
	color = vec3f_mul_vec(amb_col, amb_intensity);
	while (inter_data.l->num != 0 && i < inter_data.l->num)
	{
		color = vec3f_add_vec(color,
					phong_contrib(diff_spec,
							inter_data.l->lights[i].light_data,
							inter_data));
		i++;
	}
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metalic_surface_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_object.h"
#include "../includes/rt_lights.h"
#include <stdio.h>

void	metalic_surface_pure(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object *obj)
{
	(void)cam_ray;
	material_set_solid_color(color, obj, ref_ray, NULL);
}

void	metalic_surface_colored(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object *obj)
{
	(void)obj;
	ref_ray->color = vec3f_mul_vec(ref_ray->color,
				vec3f_mul_k(cam_ray->l->lights->light_data.direction,
				get_diffuse_contrib(ref_ray, cam_ray->l->lights->light_data)));
	ref_ray->color = vec3f_add_k(ref_ray->color,
				get_specular_contrib(ref_ray, cam_ray->l->lights->light_data));
	*color = ref_ray->color;
}

void	metalic_surface_impure(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object *obj)
{
	(void)obj;
	ref_ray->color = phong_illumination((t_vec3f){10, 10, 10},
						(t_ray){ref_ray->color,
						(t_vec3f){255, 255, 255}},
						*ref_ray);
	gamma_correction(&ref_ray->color);
	cam_ray->shininess = 100.;
	cam_ray->color = phong_illumination((t_vec3f){10, 10, 10},
						(t_ray){ref_ray->color,
						(t_vec3f){255, 255, 255}},
						*cam_ray);
	*color = vec3_lerp(cam_ray->color, ref_ray->color, 0);
}

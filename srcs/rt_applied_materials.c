/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_applied_materials.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by tigondol          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_textures.h"
#include "../includes/rt.h"
#include "../includes/rt_lights.h"
#include <pthread.h>
#define T_INTER t_intersect_data

void				metallic_surface_array(T_INTER *r_ray,
						T_INTER *c_ray, t_vec3f *color, t_object *obj)
{
	static void	(*array[__MATERIAL_TOTAL])(T_INTER *, T_INTER *, t_vec3f *,
		t_object *) = {[MATERIAL_MIRROR_COLORED] = &metalic_surface_colored,
		[MATERIAL_MIRROR_IMPURE] = &metalic_surface_impure,
		[MATERIAL_MIRROR_PURE] = &metalic_surface_pure};

	return (array[c_ray->material](r_ray, c_ray, color, obj));
}

void				material_set_solid_color(t_vec3f *color, t_object *obj,
				t_intersect_data *inter, SDL_Surface **textures)
{
	size_t i;

	(void)textures;
	(void)obj;
	*color = phong_illumination((t_vec3f){10, 10, 10},
			(t_ray){inter->color, (t_vec3f){255, 255, 255}},
			*inter);
	i = 0;
	while (i < inter->l->num)
	{
		if (get_shadow(inter, obj, i) != 0)
			*color = vec3_lerp((t_vec3f){0, 0, 0}, *color, 0.1);
		i++;
	}
}

void				material_metallic_surface_handler(t_intersect_data *r_ray,
						t_intersect_data *c_ray, t_vec3f *color, t_object *obj)
{
	metallic_surface_array(r_ray, c_ray, color, obj);
}

t_intersect_data	make_ray(t_intersect_data *idt, t_vec3f dir, t_object *obj)
{
	t_intersect_data	ray;
	t_ray				r;

	r.origin = vec3f_add_vec(idt->intersect_pos,
				vec3f_div_k(vec3f_normalize(idt->normal), 10));
	r.direction = dir;
	ray = ray_march(r, obj);
	ray.origin = idt->intersect_pos;
	ray.bounce = idt->bounce;
	ray.normal = get_normal(ray.intersect_pos, obj);
	ray.dir = vec3f_normalize(vec3f_sub_vec(r.direction, r.origin));
	ray.l = idt->l;
	return (ray);
}

void				reflection(t_vec3f *color, t_object *obj,
						t_intersect_data *inter, SDL_Surface **textures)
{
	t_vec3f				rebound;
	t_intersect_data	ray;

	rebound = reflect(vec3f_normalize(vec3f_sub_vec(inter->dir,
			inter->origin)), vec3f_normalize(inter->normal));
	ray = make_ray(inter, rebound, obj);
	if (ray.dist < MAX_DIST)
	{
		if (ray.material == MATERIAL_MIRROR_PURE
				|| ray.material == MATERIAL_MIRROR_IMPURE
				|| ray.material == MATERIAL_MIRROR_COLORED)
		{
			if (ray.bounce++ < 5)
				reflection(color, obj, &ray, textures);
			else
			{
				*color = vec3_lerp(inter->color, ray.color, 0.5);
				return ;
			}
		}
		else
			material_metallic_surface_handler(&ray, inter, color, obj);
	}
	else
		*color = vec3f_mul_k(inter->color, 0.8);
}

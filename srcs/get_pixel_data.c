/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/rt_materials.h"

#define GVM 	get_view_matrix

t_vec3f		get_normal(t_vec3f p, t_object *obj)
{
	float	distance;
	t_vec3f store;
	t_vec3f pm[3];
	t_vec3f normal;

	distance = get_dist(obj, p).dist;
	pm[0] = (t_vec3f){0.1f, 0, 0};
	pm[1] = (t_vec3f){0, 0.1f, 0};
	pm[2] = (t_vec3f){0, 0, 0.1f};
	vec3f_set(&store,
		get_dist(obj, vec3f_add_vec(p, pm[0])).dist,
		get_dist(obj, vec3f_add_vec(p, pm[1])).dist,
		get_dist(obj, vec3f_add_vec(p, pm[2])).dist);
	normal = vec3f_div_k(vec3f_sub_k(store, distance), .001f);
	return (normal);
}

t_vec2f		get_normalized_screen_coordinates(int x, int y)
{
	t_vec2f		uv;

	uv = vec2f_div_vec(
		(t_vec2f){(x - (SCREEN_W / 2)), -(y - (SCREEN_H / 2))},
		(t_vec2f){SCREEN_H, SCREEN_H});
	return (uv);
}

void		gamma_correction(t_vec3f *color)
{
	*color = (t_vec3f){
		pow(color->x, 0.4545),
		pow(color->y, 0.4545),
		pow(color->z, 0.4545),
	};
}

t_vec3f		get_cam_direction(t_vec2f uv, t_vec2f size, float fov)
{
	t_vec2f		xy;
	float		z;

	xy = vec2f_sub(uv, vec2f_div_k(size, 2.));
	z = size.y / tan(deg_to_rad(fov) / 2.0);
	return (vec3f_normalize((t_vec3f){xy.x, -xy.y, -z}));
}

t_vec3f		get_pixel_color(t_thread_data *t,
		t_vec2f pos)
{
	t_vec3f				color;
	t_vec3f				uv;
	t_intersect_data	scene_min_intersect_data;
	t_vec4f				mat[4];
	t_surface_stuff		lol;

	uv = get_cam_direction(pos, (t_vec2f){640, 480}, t->cam->fov);
	GVM(t->cam->posdata.origin, t->cam->focus, (t_vec3f){0, 1, 0}, mat);
	t->cam->posdata.direction = vec3f_mul_mat4f(uv, mat);
	scene_min_intersect_data = ray_march(t->cam->posdata, t->obj);
	scene_min_intersect_data.origin = t->cam->posdata.origin;
	scene_min_intersect_data.l = t->lights;
	if (scene_min_intersect_data.dist < MAX_DIST)
	{
		lol = (t_surface_stuff){
			.color = &color,
			.obj = t->obj,
			.inter = &scene_min_intersect_data,
			.textures = t->textures};
		surface_caller(scene_min_intersect_data.material, lol);
		gamma_correction(&color);
	}
	else
		vec3f_set(&color, 0, 0, 0);
	return (color);
}

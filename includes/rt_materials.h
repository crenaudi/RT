/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATERIALS_H
# define RT_MATERIALS_H
# include "../includes/rt_object.h"
# include "../minilibsdl/include/ft_minilibsdl.h"

void	material_set_texture(t_vec3f *color,
				t_object *obj,
				t_intersect_data *inter,
				SDL_Surface **textures);

void	material_set_solid_color(t_vec3f *color,
				t_object *obj,
				t_intersect_data *inter,
				SDL_Surface **textures);

void	material_set_solid_color(t_vec3f *color,
				t_object *obj,
				t_intersect_data *inter,
				SDL_Surface **textures);

void	reflection(t_vec3f *color,
				t_object *obj,
				t_intersect_data *inter,
				SDL_Surface **textures);

void	refraction(t_vec3f *color,
				t_object *obj,
				t_intersect_data *inter,
				SDL_Surface **textures);

void	metalic_surface_pure(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object	*obj);

void	metalic_surface_colored(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object	*obj);

void	metalic_surface_impure(t_intersect_data *ref_ray,
				t_intersect_data *cam_ray,
				t_vec3f *color,
				t_object	*obj);

#endif

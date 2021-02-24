/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lights.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_LIGHTS_H
# define RT_LIGHTS_H
# include "../BSVL/bsvl.h"
# include "./rt_object.h"
# include "./rt.h"

t_vec3f	phong_illumination(t_vec3f amb_col,
				t_ray diff_spec,
				t_intersect_data inter_data);

float	get_diffuse_contrib(t_intersect_data *inter,
				t_ray lpos_lint);

float	get_shadow(t_intersect_data *inter, t_object *obj, size_t i);

float	get_specular_contrib(t_intersect_data *intersect_data,
				t_ray lpos_lint);

void	apply_fresnel(t_intersect_data *intersect_data,
				t_vec3f frescolor,
				t_vec3f *color);

void	gamma_correction(t_vec3f *color);

#endif

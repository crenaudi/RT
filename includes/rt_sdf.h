/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SDF_H
# define RT_SDF_H
# include "../BSVL/bsvl.h"
# include "../includes/rt_object.h"

float	sdf_sphere(t_vec3f origin, t_object obj);
float	sdf_box(t_vec3f p, t_object obj);
float	sdf_cone(t_vec3f origin, t_object obj);
float	sdf_plane(t_vec3f origin, t_object obj);
float	sdf_torus(t_vec3f origin, t_object obj);
float	sdf_capsule(t_vec3f origin, t_object obj);
float	sdf_octahedron(t_vec3f p, t_object obj);
float	sdf_ellipsoid(t_vec3f p, t_object obj);
float	sdf_cylinder(t_vec3f p, t_object obj);

float	sdf_caller(t_e_sdf type, t_vec3f pos, t_object obj);
float	sdf_custom(t_vec3f p, t_object obj);

void	sdf_arg_setup_caller(t_vec3f *rd, t_object *obj);
void	setup_args_nosetup(t_vec3f *p, t_object *obj);
void	setup_args_tr_rot(t_vec3f *p, t_object *obj);

#endif

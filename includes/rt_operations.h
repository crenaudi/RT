/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OPERATIONS_H
# define RT_OPERATIONS_H
# include "../BSVL/bsvl.h"
# include "rt_sdf.h"

float			operation_caller(t_e_def op, float d1, float d2, float k);
void			surface_caller(t_e_material surface_mat, t_surface_stuff surf);

float			op_uni(float d1, float d2, float k);
float			op_sub(float d1, float d2, float k);
float			op_inter(float d1, float d2, float k);
float			clamp(float x, float upper, float lower);
float			lerp(float a, float b, float f);

float			op_s_uni(float d1, float d2, float k);
float			op_s_sub(float d1, float d2, float k);
float			op_s_inter(float d1, float d2, float k);

float			op_inf_rep(t_vec3f cam, t_vec3f rep, t_object obj,
					float (*sdf)(t_vec3f, t_object));

float			apply_operations(t_object *obj, t_intersect_data *dist_array);
#endif

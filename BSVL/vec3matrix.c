/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 00:09:55 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

void	get_pitch_matrix(float theta, t_vec3f mat[static 3])
{
	mat[0] = (t_vec3f){cos(theta), 0, sin(theta)};
	mat[1] = (t_vec3f){0, 1, 0};
	mat[2] = (t_vec3f){-sin(theta), 0, cos(theta)};
}

void	get_yaw_matrix(float theta, t_vec3f mat[static 3])
{
	mat[0] = (t_vec3f){cos(theta), -sin(theta), 0};
	mat[1] = (t_vec3f){sin(theta), cos(theta), 0};
	mat[2] = (t_vec3f){0, 0, 1};
}

void	get_rotation_matrix(float theta, enum e_axis axis,
				t_vec3f mat[static 3])
{
	static void (*const rot_fptr[__TOTAL_ROT])(float, t_vec3f *) =
	{&get_roll_matrix, &get_pitch_matrix, &get_yaw_matrix};

	rot_fptr[axis](theta, &mat[0]);
}

void	apply_rotation_matrix(t_vec3f *vec_addr, t_vec3f mat[static 3])
{
	*vec_addr = vec3f_mul_mat3(*vec_addr, mat);
}

void	get_and_apply_rotation_matrix(float theta, enum e_axis axis,
		t_vec3f *vec_addr)
{
	t_vec3f	mat[3];

	get_rotation_matrix(theta, axis, &mat[0]);
	apply_rotation_matrix(vec_addr, &mat[0]);
}

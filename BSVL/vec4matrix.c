/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/06 23:27:30 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

void	get_translation_matrix(t_vec3f tr_vec, t_vec4f mat[static 4])
{
	mat[0] = (t_vec4f){1., 0., 0., 0};
	mat[1] = (t_vec4f){0., 1., 0., 0};
	mat[2] = (t_vec4f){0., 0., 1., 0};
	mat[3] = (t_vec4f){tr_vec.x, tr_vec.y, tr_vec.z, 1};
}

void	get_and_apply_translation_matrix(t_vec3f *target_addr,
	t_vec3f translation_vector)
{
	t_vec4f mat[4];
	t_vec3f res;

	get_translation_matrix(translation_vector, mat);
	res = vec3f_mul_mat4f(*target_addr, mat);
	*target_addr = res;
}

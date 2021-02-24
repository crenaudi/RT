/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdf_arg_setup_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	setup_args_nosetup(t_vec3f *p, t_object *obj)
{
	(void)p;
	(void)obj;
	return ;
}

void	setup_args_tr_rot(t_vec3f *p, t_object *obj)
{
	get_and_apply_translation_matrix(p, vec3f_mul_k(obj->pos, -1));
	*p = vec3f_mul_mat3(*p, obj->rot_mat);
	return ;
}

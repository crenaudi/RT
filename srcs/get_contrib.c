/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_contrib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_lights.h"

float		get_specular_contrib(t_intersect_data *inter, t_ray lpos_lint)
{
	t_vec3f light;
	t_vec3f rvec;
	float	dotrv;

	light = vec3f_normalize(vec3f_sub_vec(lpos_lint.origin,
						inter->intersect_pos));
	rvec = vec3f_normalize(reflect(vec3f_mul_k(light, -1),
						inter->normal));
	dotrv = vec3f_dotprod(light, rvec);
	return (inter->shininess * pow(dotrv, 32));
}

float		get_diffuse_contrib(t_intersect_data *inter_data, t_ray l_posin)
{
	t_vec3f light;
	float	dotln;

	light = vec3f_normalize(vec3f_sub_vec(l_posin.origin,
						inter_data->intersect_pos));
	dotln = vec3f_dotprod(inter_data->normal, light);
	return (dotln);
}

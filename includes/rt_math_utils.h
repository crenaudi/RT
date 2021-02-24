/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_UTILS_H
# define RT_MATH_UTILS_H
# include "../BSVL/bsvl.h"

float		clamp(float x, float upper, float lower);
float		lerp(float a, float b, float f);
float		deg_to_rad(double radians);
t_vec3f		reflect(t_vec3f i, t_vec3f n);
t_vec3f		refract(t_vec3f i, t_vec3f n, float n1, float n2, float radical);
float		sqr(float i);

#endif

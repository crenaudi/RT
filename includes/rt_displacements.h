/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_displacements.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 17:29:51 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DISPLACEMENTS_H
# define RT_DISPLACEMENTS_H
# include "../includes/rt.h"

float	displace_sin(t_object *obj, t_vec3f p, float k);
float	displace_twist(t_object *obj, t_vec3f p, float k);
float	displace_bend(t_object *obj, t_vec3f p, float k);
float	displace_perlin(t_object *obj, t_vec3f p, float k);

#endif

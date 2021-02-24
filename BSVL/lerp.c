/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/18 17:16:13 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

bool	vec3f_cmp(t_vec3f a, t_vec3f b)
{
	bool xcmp;
	bool ycmp;
	bool zcmp;

	xcmp = a.x == b.x ? true : false;
	ycmp = a.y == b.y ? true : false;
	zcmp = a.z == b.z ? true : false;
	return (xcmp && ycmp && zcmp);
}

t_vec3f	vec3_lerp(t_vec3f a, t_vec3f b, float t)
{
	t_vec3f res;

	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	res.z = a.z + (b.z - a.z) * t;
	return (res);
}

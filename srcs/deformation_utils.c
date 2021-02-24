/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deformation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float	op_s_sub(float d1, float d2, float k)
{
	float h;

	h = clamp(0.5 - 0.5 * (d2 + d1) / k, 0.0, 1.0);
	return (lerp(d2, -d1, h) + k * h * (1.0 - h));
}

float	op_s_inter(float d1, float d2, float k)
{
	float h;

	h = clamp(0.5 - 0.5 * (d2 - d1) / k, 0.0, 1.0);
	return (lerp(d2, d1, h) + k * h * (1.0 - h));
}

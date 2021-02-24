/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/18 17:13:01 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

float	sqr(float i)
{
	return (i * i);
}

float	clamp(float x, float upper, float lower)
{
	return (min(upper, max(x, lower)));
}

float	lerp(float a, float b, float f)
{
	return (a + f * (b - a));
}

float	deg_to_rad(double radians)
{
	return (radians * (180.0 / M_PI));
}

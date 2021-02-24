/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by tigondol          #+#    #+#             */
/*   Updated: 2020/12/18 17:13:01 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsvl.h"

float	min(float a, float b)
{
	if (a > b)
		return (b);
	return (a);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

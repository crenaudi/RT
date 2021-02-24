/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print_attr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:51:15 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 16:58:02 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../altlib/altlib.h"

void	print_attr_ellipsoid(t_object *obj)
{
	ft_putstr("r1:");
	ft_putfloat(obj->data.ellipsoid.r.x);
	ft_putchar('\n');
	ft_putstr("r2:");
	ft_putfloat(obj->data.ellipsoid.r.y);
	ft_putchar('\n');
	ft_putstr("r3:");
	ft_putfloat(obj->data.ellipsoid.r.z);
	ft_putchar('\n');
}

void	print_attr_sphere(t_object *obj)
{
	ft_putstr("r:");
	ft_putfloat(obj->data.sphere.rad);
	ft_putchar('\n');
}

void	print_attr_torus(t_object *obj)
{
	ft_putstr("r1: ");
	ft_putfloat(obj->data.torus.r.x);
	ft_putstr(" r2: ");
	ft_putfloat(obj->data.torus.r.y);
	ft_putchar('\n');
}

void	print_attr_cube(t_object *obj)
{
	ft_putstr("b: ");
	print_tvec3f(obj->data.cube.b);
	ft_putchar('\n');
}

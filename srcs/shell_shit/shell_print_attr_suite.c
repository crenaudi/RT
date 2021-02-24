/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print_attr_suite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:50:46 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/20 16:55:00 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "../../altlib/altlib.h"

void	print_attr_octa(t_object *obj)
{
	ft_putstr("s:");
	ft_putfloat(obj->data.octa.s);
	ft_putchar('\n');
}

void	print_attr_plane(t_object *obj)
{
	ft_putstr("orientation: ");
	print_tvec3f(obj->data.plane.orientation);
	ft_putstr(" h:");
	ft_putfloat(obj->data.plane.h);
	ft_putchar('\n');
}

void	print_attr_capsule(t_object *obj)
{
	ft_putstr("r:");
	ft_putfloat(obj->data.capsule.r);
	ft_putstr("a: ");
	print_tvec3f(obj->data.capsule.a);
	ft_putstr("b: ");
	print_tvec3f(obj->data.capsule.b);
	ft_putchar('\n');
}

void	print_attr_cylinder(t_object *obj)
{
	ft_putstr("r:");
	ft_putfloat(obj->data.cylinder.r);
	ft_putstr("a: ");
	print_tvec3f(obj->data.cylinder.a);
	ft_putstr("b: ");
	print_tvec3f(obj->data.cylinder.b);
	ft_putchar('\n');
}

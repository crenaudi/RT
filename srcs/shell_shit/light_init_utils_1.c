/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_init_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:31:53 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/18 18:31:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	init_light(t_lightpoint *light)
{
	ft_bzero(light, sizeof(t_lightpoint));
	light->id = NULL;
}

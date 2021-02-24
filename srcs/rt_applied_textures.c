/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_applied_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by tigondol          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_textures.h"
#include "../includes/rt.h"
#include "../includes/rt_lights.h"
#include <pthread.h>

void		material_set_texture(t_vec3f *color, t_object *obj,
				t_intersect_data *inter, SDL_Surface **textures)
{
	(void)obj;
	(void)inter;
	(void)textures;
	*color = (t_vec3f){0, 0, 0};
}

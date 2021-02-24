/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_textures_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rt_textures.h"

Uint32		get_texture_pixel_color(SDL_Surface *texture, int x_pos, int y_pos)
{
	int		bpp;
	Uint8	*p;

	bpp = texture->format->BytesPerPixel;
	p = (Uint8 *)texture->pixels + y_pos * texture->pitch + x_pos * bpp;
	if (bpp == 1)
	{
		return (*p);
	}
	else if (bpp == 2)
	{
		return (*(Uint16 *)p);
	}
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
	{
		return (*(Uint32 *)p);
	}
	return (0);
}

t_vec3f		get_rgb_from_uint32(uint32_t uint_color)
{
	t_vec3f	vec_color;

	vec_color.x = (uint8_t)uint_color >> 16;
	vec_color.y = (uint8_t)uint_color >> 8;
	vec_color.z = (uint8_t)uint_color;
	return (vec_color);
}

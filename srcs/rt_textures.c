/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../altlib/altlib.h"

char		**return_texture_names(void)
{
	static char	*texture_names[__MATERIAL_TOTAL] = {
		"./assets/texture_checkers.bmp",
		NULL,
		NULL,
		"./assets/texture_polkadot.bmp",
		NULL,
		"./assets/texture_stone_0.bmp",
	};

	return (texture_names);
}

SDL_Surface	*load_single_texture(char *filename)
{
	SDL_Surface		*img_surface;

	img_surface = SDL_LoadBMP(filename);
	if (!img_surface)
	{
		ft_putstr("Failed to load texture file: [");
		ft_putstr(filename);
		ft_putstr("]. Exitting...\n");
		exit(EXIT_FAILURE);
	}
	return (img_surface);
}

void		destroy_all_loaded_textures(SDL_Surface **loaded_textures)
{
	int i;

	i = 0;
	while (loaded_textures[i])
	{
		SDL_FreeSurface(loaded_textures[i]);
		i++;
	}
}

SDL_Surface	**load_textures(char **texture_names)
{
	static SDL_Surface	*loaded_textures[__MATERIAL_TOTAL];
	unsigned short		i;

	i = 0;
	while (i < __MATERIAL_TOTAL)
	{
		if (texture_names[i])
			loaded_textures[i] = load_single_texture(texture_names[i]);
		i++;
	}
	return (loaded_textures);
}

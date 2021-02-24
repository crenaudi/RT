/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_ttf_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 12:04:35 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minilibsdl.h"

t_sdl_font	*sdl_ttf_font_open(const char *font, int size)
{
	t_sdl_font *ttf;

	ttf = NULL;
	if (!(ttf = malloc(sizeof(*ttf))))
		return (NULL);
	if (!(ttf->font = TTF_OpenFont(font, size)))
		return (NULL);
	ttf->color = (SDL_Color){0xFF, 0xFF, 0xFF, 0xFF};
	return (ttf);
}

bool		sdl_ttf_init(void)
{
	if (TTF_Init() < 0)
		return (false);
	SDL_StartTextInput();
	return (true);
}

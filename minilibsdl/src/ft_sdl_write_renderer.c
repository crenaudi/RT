/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_write_rendderer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 12:02:15 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

int		*renderer_int_tab(SDL_Renderer *renderer, int w, int h)
{
	int	pitch;
	int	*pixels;

	if (!renderer)
		return (NULL);
	pitch = sizeof(Uint32) * w;
	if (!(pixels = (int *)malloc(pitch * h)))
		return (NULL);
	if (SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, pixels,
		pitch) < 0)
		return (NULL);
	return (pixels);
}

bool	apply_surface_renderer(SDL_Renderer *renderer, SDL_Surface *screen)
{
	SDL_Texture *texture;

	if (!renderer || !screen)
	{
		write(1, "Nothing to apply.", 17);
		return (true);
	}
	texture = SDL_CreateTextureFromSurface(renderer, screen);
	if (!texture)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", TTF_GetError());
		return (false);
	}
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
	return (true);
}

void	writeonscreen(SDL_Renderer *renderer, t_sdl_font *ttf, char *str,
	t_vec2 pos)
{
	SDL_Rect		rect;
	SDL_Surface		*text;
	SDL_Texture		*txm;

	if (renderer != NULL && ttf != NULL && *str)
	{
		if ((text = TTF_RenderText_Solid(ttf->font, str, ttf->color)) == NULL)
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", TTF_GetError());
		else
		{
			if ((txm = SDL_CreateTextureFromSurface(renderer, text)) == NULL)
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s",
					TTF_GetError());
			else
			{
				SDL_QueryTexture(txm, NULL, NULL, &rect.w, &rect.h);
				rect.x = pos.x;
				rect.y = pos.y;
				SDL_RenderCopy(renderer, txm, NULL, &rect);
				SDL_DestroyTexture(txm);
			}
			SDL_FreeSurface(text);
		}
	}
}

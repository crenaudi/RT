/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_write_rendderer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/05 17:51:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

bool	window_init(SDL_Window **window, const char *win_name,
	const size_t width, const size_t height)
{
	if (!win_name || !width || !height)
	{
		sdl_error_handler("USER", "window_init", MISSING_WIN_SPEC);
		return (false);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		sdl_error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	if (!(*window = SDL_CreateWindow(win_name,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width,
					height,
					SDL_SWSURFACE | SDL_WINDOW_OPENGL)))
	{
		sdl_error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	return (true);
}

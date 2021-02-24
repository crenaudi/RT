/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/11/24 17:51:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

bool	surface_init(SDL_Window *window, SDL_Surface **win_surface)
{
	if (!(*win_surface = SDL_GetWindowSurface(window)))
	{
		sdl_error_handler("SDL", "surface_init", SDL_ERROR);
		return (false);
	}
	return (true);
}

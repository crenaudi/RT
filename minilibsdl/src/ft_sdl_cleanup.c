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

void	ft_sdl_cleanup(t_sdl_objs *sdl_objs, bool surfacep)
{
	if (surfacep == true)
	{
		SDL_FreeSurface(sdl_objs->surface);
		write(1, "freed surface\n", 14);
	}
	if (sdl_objs->renderer)
	{
		SDL_DestroyRenderer(sdl_objs->renderer);
		write(1, "doestroyed renderer\n", 20);
	}
	if (sdl_objs->window)
	{
		SDL_DestroyWindow(sdl_objs->window);
		write(1, "destroyed window\n", 17);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/07 00:39:24 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

bool	ft_sdl_check_quit(SDL_Event event)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_ESCAPE))
		return (true);
	return (false);
}

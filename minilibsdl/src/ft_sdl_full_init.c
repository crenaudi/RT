/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/07 12:11:26 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_sdl_objs *sdl_objs, const int dimentions[2],
	const char *win_title, const bool rendererp)
{
	unsigned char state[2];

	state[0] = window_init(&sdl_objs->window, win_title,
		dimentions[0], dimentions[1]);
	if (rendererp == true)
		state[1] = renderer_init(sdl_objs->window,
			&sdl_objs->renderer, dimentions);
	else
		state[1] = surface_init(sdl_objs->window, &sdl_objs->surface);
	return (state[0] & state[1]);
}

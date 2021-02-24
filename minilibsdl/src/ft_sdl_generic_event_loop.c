/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/07 12:13:52 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

void		ft_sdl_generic_event_loop(t_sdl_objs *sdl_objs, void *private)
{
	SDL_Event	event;
	bool		state;

	(void)private;
	state = true;
	while (state == true)
	{
		while (SDL_PollEvent(&event))
		{
			if (ft_sdl_check_quit(event))
			{
				state = false;
				break ;
			}
			SDL_RenderPresent(sdl_objs->renderer);
		}
		SDL_Delay(16);
	}
}

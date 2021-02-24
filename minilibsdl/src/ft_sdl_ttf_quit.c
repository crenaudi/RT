/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_ttf_quit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 12:07:29 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

void	sdl_ttf_font_close(t_sdl_font *ttf)
{
	if (!ttf)
		return ;
	if (ttf->font)
		TTF_CloseFont(ttf->font);
	bzero(&ttf->color, sizeof(SDL_Color));
	free(ttf);
}

void	sdl_ttf_quit(void)
{
	TTF_Quit();
	SDL_StopTextInput();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:27:25 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"
#include "../shell_shit/shell.h"

void		debugerror(unsigned int err, char *line)
{
	char			*s[6];
	unsigned int	close;

	s[0] = "Error fd : ";
	s[1] = "Invalid size : ";
	s[2] = "Error malloc : ";
	s[3] = "Error SDL : ";
	s[4] = "Error SDL_TTF : ";
	s[5] = "Error Texture : ";
	close = err >> 16;
	ft_putstr(s[err & 0x8F]);
	if (err == 3)
		ft_putendl(SDL_GetError());
	else if (err == 4)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] %s",
			TTF_GetError());
	else if (line != NULL)
		ft_putendl(line);
	else
		ft_putendl("no more information.");
	if (close == 1)
		ft_putendl("ATTENTION CETTE ERREUR VA FAIRE CRASH LE PROJET");
}

static void	key_caller(SDL_Event e, t_menu *menu, int utils[3])
{
	if ((menu->state & IPTB_ACTIVE) == IPTB_ACTIVE)
	{
		if (menu->iinput->storage[menu->iinput->ip] == 'V')
			key_press_num(e, menu);
		if (menu->iinput->storage[menu->iinput->ip] == 'S')
			key_press_letter(e, menu);
	}
	if (e.type == SDL_MOUSEBUTTONDOWN)
		utils[2] = 1;
	if ((menu->state & IPTB_VALIDE) == IPTB_VALIDE)
		valide_onprocess_input(menu, menu->iinput->str);
}

void		rt_menu_loop(t_rt_utils *rt, t_menu *menu)
{
	bool		loop;
	SDL_Event	e;
	int			utils[3];

	loop = true;
	while (loop)
	{
		update_menu_screen(rt->sdl_objs->renderer, menu);
		SDL_GetMouseState(&utils[0], &utils[1]);
		utils[2] = 0;
		if (SDL_PollEvent(&e))
		{
			key_caller(e, menu, utils);
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE
				&& (menu->state & PROCESS_ACTIVE) != PROCESS_ACTIVE)
				loop = false;
		}
		loop = menu_state(rt, menu, utils, loop);
		SDL_RenderPresent(rt->sdl_objs->renderer);
	}
	clear_menu(menu);
}

void		rt_chatbox_loop(t_rt_utils *rt, t_menu *menu)
{
	SDL_Event	e;
	bool		loop;

	loop = true;
	while (loop)
	{
		update_menu_screen(rt->sdl_objs->renderer, menu);
		SDL_RenderClear(rt->sdl_objs->renderer);
		if (SDL_PollEvent(&e) && e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				loop = false;
			if (e.key.keysym.sym == SDLK_RETURN)
				loop = rt_shell_chatbox(rt, menu);
			key_press_chatbox(e, menu->ichatbox);
		}
		render_chatbox(rt, menu, loop);
		SDL_RenderPresent(rt->sdl_objs->renderer);
	}
	clear_menu(menu);
}

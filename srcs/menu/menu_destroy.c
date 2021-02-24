/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:26:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void		destroy_texture_tab(t_texture **tab)
{
	if (!tab)
		return ;
	destroy_tx(tab[NAVBAR]);
	destroy_tx(tab[BTN]);
	destroy_tx(tab[INPUT]);
	destroy_tx(tab[DIV]);
	destroy_tx(tab[INFO]);
	destroy_tx(tab[CHATBOX]);
	free(tab);
	tab = NULL;
}

void		clear_menu(t_menu *menu)
{
	menu->state = 0;
	menu->ncmd = -1;
	if (menu->screen)
		ft_bzero(menu->screen->pixels, sizeof(menu->screen->h
			* menu->screen->w * 4));
	clear_input(menu->iinput);
	clear_chatbox(menu->ichatbox);
	if (menu->bg)
	{
		ft_bzero(menu->bg, sizeof(SCREEN_H * SCREEN_W));
		free(menu->bg);
		menu->bg = NULL;
	}
}

void		close_menu(t_menu *menu)
{
	sdl_ttf_font_close(menu->ttf);
	sdl_ttf_quit();
	if (menu->screen)
		SDL_FreeSurface(menu->screen);
	destroy_input(menu->iinput);
	destroy_chatbox(menu->ichatbox);
	destroy_texture_tab(menu->txs);
	if (menu->bg)
	{
		ft_bzero(menu->bg, sizeof(SCREEN_H * SCREEN_W));
		free(menu->bg);
		menu->bg = NULL;
	}
	ft_bzero(&menu, sizeof(menu));
}

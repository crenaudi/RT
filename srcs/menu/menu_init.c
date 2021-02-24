/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:26:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

t_texture	**init_texture_tab(void)
{
	t_texture	**tab;
	t_vec2		null;

	null.x = 0;
	null.y = 0;
	if (!(tab = (t_texture **)malloc(sizeof(t_texture *) * TOTAL_TEXTURE)))
		return (NULL);
	tab[NAVBAR] = add_tx("./assets/navbar.bmp", (t_vec2){255, 430},
		(t_vec2){120, 26}, (t_vec2){5, 10});
	tab[BTN] = add_tx("./assets/btn.bmp", null, (t_vec2){200, 27}, null);
	tab[INPUT] = add_tx("./assets/input.bmp", (t_vec2){215, 215},
		(t_vec2){30, 200}, (t_vec2){5, 6});
	tab[DIV] = add_tx("./assets/div.bmp", (t_vec2){135, 280}, null, null);
	tab[INFO] = add_tx("./assets/info.bmp", (t_vec2){190, 170}, null, null);
	tab[CHATBOX] = add_tx("./assets/chatbox.bmp", (t_vec2){20, 340}, null,
		(t_vec2){30, 55});
	return (tab);
}

bool		init_menu(t_menu *menu)
{
	ft_bzero(menu, sizeof(t_menu));
	if (!(sdl_ttf_init()))
		return (false);
	if ((menu->ttf = sdl_ttf_font_open("./font/proxima_nova.ttf", 12)) == NULL)
		return (false);
	if ((menu->screen = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H,
		32, 0, 0, 0, 0)) == NULL)
		return (false);
	if ((menu->txs = init_texture_tab()) == NULL)
		return (false);
	menu->ncmd = -1;
	if (!(menu->iinput = init_input(menu->txs[INPUT])))
		return (false);
	if (!(menu->ichatbox = init_chatbox()))
		return (false);
	menu->bg = NULL;
	return (true);
}

void		update_menu_screen(SDL_Renderer *renderer, t_menu *menu)
{
	int	x;
	int	y;

	if (menu->bg == NULL)
		menu->bg = renderer_int_tab(renderer, SCREEN_W, SCREEN_H);
	ft_bzero(menu->screen->pixels, sizeof(menu->screen->h
		* menu->screen->w * 4));
	y = -1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			*(int *)(menu->screen->pixels + (y * SCREEN_W + x) * 4) =
				menu->bg[y * SCREEN_W + x];
		}
	}
	SDL_RenderClear(renderer);
}

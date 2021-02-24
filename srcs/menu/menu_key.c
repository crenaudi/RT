/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:36:36 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

static void		find_num(SDL_Event e, char *storage, int *istorage)
{
	int		nums[12];
	char	*num;
	int		i;

	nums[0] = SDLK_0;
	nums[1] = SDLK_1;
	nums[2] = SDLK_2;
	nums[3] = SDLK_3;
	nums[4] = SDLK_4;
	nums[5] = SDLK_5;
	nums[6] = SDLK_6;
	nums[7] = SDLK_7;
	nums[8] = SDLK_8;
	nums[9] = SDLK_9;
	nums[10] = SDLK_PERIOD;
	nums[11] = SDLK_MINUS;
	i = -1;
	num = "0123456789.-";
	while (++i < 12)
		if (nums[i] == e.key.keysym.sym)
		{
			storage[*istorage] = num[i];
			*istorage = *istorage + 1;
		}
}

static void		find_alpha(SDL_Event e, char *storage, int *istorage)
{
	static int	alphas[28] = {
		SDLK_a, SDLK_b, SDLK_c, SDLK_d, SDLK_e, SDLK_f, SDLK_g, SDLK_h, SDLK_i,
		SDLK_j, SDLK_k, SDLK_l, SDLK_m, SDLK_n, SDLK_o, SDLK_p, SDLK_q, SDLK_r,
		SDLK_s, SDLK_t, SDLK_u, SDLK_v, SDLK_w, SDLK_x, SDLK_y, SDLK_z,
		SDLK_SPACE, SDLK_SLASH};
	char		*alpha;
	int			i;

	i = -1;
	alpha = "abcdefghijklmnopqrstuvwxyz /";
	while (++i < 28)
		if (alphas[i] == e.key.keysym.sym)
		{
			storage[*istorage] = alpha[i];
			*istorage = *istorage + 1;
		}
	if (e.key.keysym.sym == SDLK_LSHIFT
		|| e.key.keysym.sym == SDLK_UNDERSCORE)
	{
		storage[*istorage] = '_';
		*istorage = *istorage + 1;
	}
}

void			key_press_letter(SDL_Event event, t_menu *menu)
{
	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_BACKSPACE && menu->iinput->is > 0)
			menu->iinput->str[--menu->iinput->is] = '\0';
		if (menu->iinput->is < BUFF_INPUT)
		{
			find_num(event, menu->iinput->str, &menu->iinput->is);
			find_alpha(event, menu->iinput->str, &menu->iinput->is);
			if (event.key.keysym.sym == SDLK_LEFTBRACKET
				|| event.key.keysym.sym == SDLK_CARET
				|| event.key.keysym.sym == SDLK_LEFTPAREN)
				menu->iinput->str[menu->iinput->is++] = '{';
			if (event.key.keysym.sym == SDLK_RIGHTBRACKET
				|| event.key.keysym.sym == SDLK_DOLLAR
				|| event.key.keysym.sym == SDLK_RIGHTPAREN)
				menu->iinput->str[menu->iinput->is++] = '}';
			if (event.key.keysym.sym == SDLK_SEMICOLON
				|| event.key.keysym.sym == SDLK_COLON)
				menu->iinput->str[menu->iinput->is++] = ':';
		}
	}
}

void			key_press_num(SDL_Event event, t_menu *menu)
{
	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_BACKSPACE && menu->iinput->is > 0)
			menu->iinput->str[--menu->iinput->is] = '\0';
		if (menu->iinput->is < BUFF_INPUT)
			find_num(event, menu->iinput->str, &menu->iinput->is);
	}
}

void			key_press_chatbox(SDL_Event e, t_chatbox *cb)
{
	if (e.key.keysym.sym == SDLK_BACKSPACE && cb->i > 0)
		cb->storage[--cb->i] = '\0';
	if (cb->i < BUFF_STORAGE)
	{
		find_num(e, cb->storage, &cb->i);
		find_alpha(e, cb->storage, &cb->i);
		if (e.key.keysym.sym == SDLK_LEFTBRACKET
			|| e.key.keysym.sym == SDLK_CARET
			|| e.key.keysym.sym == SDLK_LEFTPAREN)
			cb->storage[cb->i++] = '{';
		if (e.key.keysym.sym == SDLK_RIGHTBRACKET
			|| e.key.keysym.sym == SDLK_DOLLAR
			|| e.key.keysym.sym == SDLK_RIGHTPAREN)
			cb->storage[cb->i++] = '}';
		if (e.key.keysym.sym == SDLK_SEMICOLON
			|| e.key.keysym.sym == SDLK_COLON)
			cb->storage[cb->i++] = ':';
	}
}

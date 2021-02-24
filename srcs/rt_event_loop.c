/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibsdl/include/ft_minilibsdl.h"
#include "../includes/rt.h"
#include "../srcs/shell_shit/shell.h"
#include "../includes/rt_threads.h"

void		*display_scene(void *arg)
{
	t_thread_data	*thr_data;
	int				x;
	int				y;

	thr_data = (t_thread_data *)arg;
	y = thr_data->y;
	x = thr_data->x;
	while (y <= thr_data->lim.y)
	{
		while (x <= thr_data->lim.x)
		{
			thr_data->colors[(y * SCREEN_H) + x] =
					get_pixel_color(thr_data, (t_vec2f){x, y});
			x++;
		}
		x = thr_data->x;
		y++;
	}
	return (NULL);
}

void		image_maker(t_rt_utils *utils)
{
	ft_putstr("Getting thread data...\n");
	get_thr_data(utils->thr, utils->thr_data);
	ft_putstr("Writing colors...\n");
	write_colors_to_image(utils->thr_data, utils->sdl_objs->renderer);
	ft_putstr("Flipping image to screen...\n");
	SDL_RenderPresent(utils->sdl_objs->renderer);
	ft_putstr("Done.\n");
}

static bool	rt_loop(t_menu *menu, t_rt_utils *utils)
{
	SDL_Event	event;
	bool		state;

	state = true;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_TAB)
			menu->state = CHATBOX_ACTIVE;
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_m)
			menu->state = MENU_ACTIVE;
		if (ft_sdl_check_quit(event))
		{
			state = false;
			free_obj_data(utils->obj, utils->nb_object);
			free_thread_data(utils->thr_data);
			return (false);
		}
		if (event.type == SDL_KEYDOWN)
			camera_move(utils, event.key.keysym.sym);
	}
	return (state);
}

void		rt_event_loop(void *private)
{
	bool		state;
	t_rt_utils	*utils;
	t_menu		menu;

	utils = (t_rt_utils *)private;
	state = init_menu(&menu);
	image_maker(utils);
	while (state == true)
	{
		if ((menu.state & CHATBOX_ACTIVE) == CHATBOX_ACTIVE)
			rt_chatbox_loop(utils, &menu);
		else if ((menu.state & MENU_ACTIVE) == MENU_ACTIVE)
			rt_menu_loop(utils, &menu);
		else
			state = rt_loop(&menu, utils);
	}
	close_menu(&menu);
}

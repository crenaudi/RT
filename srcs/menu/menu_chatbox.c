/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_chatbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:26:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

t_chatbox	*init_chatbox(void)
{
	t_chatbox		*cb;

	if (!(cb = (t_chatbox *)malloc(sizeof(t_chatbox))))
		return (NULL);
	ft_bzero(cb, sizeof(t_chatbox));
	ft_bzero(cb->storage, sizeof(char) * BUFF_STORAGE);
	cb->i = 0;
	return (cb);
}

void		clear_chatbox(t_chatbox *cb)
{
	if (!cb)
		return ;
	ft_bzero(cb->storage, sizeof(char) * BUFF_STORAGE);
	cb->i = 0;
}

void		destroy_chatbox(t_chatbox *cb)
{
	if (!cb)
		return ;
	clear_chatbox(cb);
	ft_bzero(cb, sizeof(t_chatbox));
	free(cb);
}

void		gestion_chatbox(SDL_Renderer *renderer, t_menu *menu, t_chatbox *cb)
{
	char	line[101];
	t_vec2	pos;
	int		ip;
	int		i;

	pos = menu->txs[CHATBOX]->pos + menu->txs[CHATBOX]->pad;
	if (cb->i >= 100)
	{
		ip = (cb->i >= 300) ? cb->i - 300 : 0;
		while (cb->storage[ip] != '\0')
		{
			my_bzero(line, sizeof(char) * 101);
			i = -1;
			while (++i < 100)
			{
				if (cb->storage[ip] != '\0')
					line[i] = cb->storage[ip++];
			}
			line[i] = '\0';
			writeonscreen(renderer, menu->ttf, line, pos);
			pos.y += 20;
		}
	}
	else
		writeonscreen(renderer, menu->ttf, cb->storage, pos);
}

void		render_chatbox(t_rt_utils *rt, t_menu *menu, bool loop)
{
	if (loop)
	{
		put_tx(menu, menu->txs[CHATBOX], 0, menu->txs[CHATBOX]->pos);
		apply_surface_renderer(rt->sdl_objs->renderer, menu->screen);
		gestion_chatbox(rt->sdl_objs->renderer, menu, menu->ichatbox);
	}
	else
		write_colors_to_image(rt->thr_data, rt->sdl_objs->renderer);
}

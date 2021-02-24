/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 20:02:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

t_texture	*init_tx(int x, int y, int nframes)
{
	t_texture	*tx;

	if (x <= 0 || y <= 0)
		return (NULL);
	if (!(tx = malloc(sizeof(*tx))))
		return (NULL);
	ft_bzero(tx, sizeof(*tx));
	tx->data = NULL;
	if ((tx->frames = malloc(sizeof(int*) * nframes)))
		ft_bzero(tx->frames, sizeof(int*) * nframes);
	if (!tx->frames)
	{
		if (tx->frames)
			free(tx->data);
		ft_bzero(tx, sizeof(*tx));
		free(tx);
		tx = NULL;
	}
	return (tx);
}

bool		init_data(t_texture *tx, t_bmp_header *bmphdr)
{
	int		x;
	int		y;
	int		nframes;

	x = tx->size.x;
	y = tx->size.y;
	nframes = (bmphdr->nframes <= 0) ? 1 : bmphdr->nframes;
	if (!(tx->data = generateimage(*bmphdr)))
	{
		destroy_tx(tx);
		return (false);
	}
	while (nframes--)
		tx->frames[nframes] = tx->data + nframes * x * y;
	free(bmphdr->data);
	return (true);
}

t_texture	*add_tx(const char *file, t_vec2 pos, t_vec2 hit, t_vec2 pad)
{
	char			*data;
	int				fd;
	t_bmp_header	bmphdr;
	t_texture		*tx;

	if ((fd = fd_check_open(file)) == -1)
		return (NULL);
	data = readncharacter(fd, 14);
	if (generateheader(fd, &bmphdr, data) == false)
		return (NULL);
	free(data);
	if (!(tx = init_tx(bmphdr.width, bmphdr.height, bmphdr.nframes)))
	{
		debugerror(ERR_MALLOC, "fail init texture.");
		return (NULL);
	}
	tx->size.x = bmphdr.width;
	tx->nframes = (bmphdr.nframes <= 0) ? 1 : bmphdr.nframes;
	tx->size.y = bmphdr.height / tx->nframes;
	tx->pos = pos;
	tx->pad = pad;
	init_hitbox(tx, pos, hit, pad);
	if (init_data(tx, &bmphdr) == false)
		return (NULL);
	return (tx);
}

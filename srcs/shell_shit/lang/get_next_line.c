/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 17:29:51 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lang.h"
#include <stdio.h>

void				ft_augment_size(char **original_container, size_t *size)
{
	char			*tmp_container;
	size_t			size_to_augment;

	size_to_augment = *size * 2;
	if (!(tmp_container = (char *)malloc(sizeof(char) * (size_to_augment))))
	{
		free((void **)original_container);
		return ;
	}
	memcpy(tmp_container, *original_container, *size);
	free((void **)original_container);
	*original_container = tmp_container;
	*size = size_to_augment;
}

int					ft_get(const int fd, char *c)
{
	static t_getc_vars t_getv;

	if (c == NULL)
	{
		t_getv.len = 0;
		t_getv.i = 0;
		return (0);
	}
	if (t_getv.i == t_getv.len)
	{
		t_getv.len = read(fd, t_getv.tmp, BUFF_SIZE);
		t_getv.i = 0;
	}
	if (t_getv.len != 0)
		*c = t_getv.tmp[t_getv.i++];
	else
		*c = 0;
	return (t_getv.len);
}

void				manage_line(char **line)
{
	free((void **)*line);
	*line = NULL;
	ft_get(0, NULL);
}

int					init_gnl(t_vars *vr, const int fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	vr->buf = 0;
	vr->len = 128;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	t_vars vr;

	if (init_gnl(&vr, fd, line) < 0)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * vr.len)))
		return (-1);
	while (vr.buf < vr.len)
	{
		if ((vr.ret = ft_get(fd, &vr.c)) < 0 || (vr.ret == 0 && vr.buf == 0))
		{
			if (**line != '\0')
			{
				manage_line(line);
			}
			return (0);
		}
		if (vr.ret == 0 || vr.c == '\n')
		{
			line[0][vr.buf] = '\0';
			return (1);
		}
		line[0][vr.buf++] = vr.c;
		vr.buf >= vr.len ? ft_augment_size(line, &vr.len) : 0;
	}
	return (-1);
}

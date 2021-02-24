/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:08:37 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

static bool		generatebmpdata(SDL_Renderer *rdrr, t_bmp_header *fhdr)
{
	int		i;
	int		x;
	int		y;
	int		*pixels;

	if (!(pixels = renderer_int_tab(rdrr, fhdr->width, fhdr->height)))
		return (false);
	i = 0;
	y = fhdr->height;
	while (--y)
	{
		x = -1;
		while (++x < fhdr->width)
			*(int *)(fhdr->data + ((i * fhdr->width + x) * 4 + 54)) =
				pixels[y * fhdr->width + x];
		i++;
	}
	free(pixels);
	return (true);
}

static bool		generateheaderfromsdl(t_bmp_header *fhdr, int w, int h)
{
	my_bzero(fhdr, sizeof(t_bmp_header));
	if (w <= 0 || h <= 0)
		return (ERR_SIZE);
	fhdr->width = w;
	fhdr->height = h;
	fhdr->fsize = 54 + (fhdr->width * fhdr->height * 4);
	if (!(fhdr->data = (char *)my_memalloc(fhdr->fsize * sizeof(char))))
		return (ERR_MALLOC);
	my_bzero(fhdr->data, sizeof(char) * fhdr->fsize);
	*(short*)(fhdr->data) = (short)(('M' << 8) | 'B');
	*(int*)(fhdr->data + 2) = fhdr->fsize;
	fhdr->data[10] = 54;
	fhdr->data[14] = 40;
	*(int*)(fhdr->data + 18) = fhdr->width;
	*(int*)(fhdr->data + 22) = fhdr->height;
	fhdr->data[26] = 1;
	fhdr->data[28] = 32;
	*(int*)(fhdr->data + 38) = 12000;
	*(int*)(fhdr->data + 44) = 12000;
	return (true);
}

void			generatebmpfromsdl(SDL_Window *win, SDL_Renderer *rdrr,
	const char *path, const char *name)
{
	int				size[2];
	int				fd;
	int				err;
	char			pn[NAME_MAX + PATH_MAX];
	t_bmp_header	fhdr;

	if ((fd_check_param(name, ".bmp")) == false)
		return ;
	my_strcpy(pn, path);
	my_strcat(pn, name);
	if ((fd = fd_check_dest(pn)) < 0)
		debugerror(0, (fd == -1) ? "false" : "Canceled");
	else
	{
		SDL_GetWindowSize(win, &size[0], &size[1]);
		if ((err = generateheaderfromsdl(&fhdr, size[0], size[1]))
			&& (err = generatebmpdata(rdrr, &fhdr)))
		{
			write(fd, fhdr.data, fhdr.fsize);
			free(fhdr.data);
		}
		else
			debugerror(err, "in bmp_generate.c");
		close(fd);
	}
}

static void		addbmpdata(int *pixels, t_bmp_header *fhdr)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = fhdr->height;
	while (--y)
	{
		x = -1;
		while (++x < fhdr->width)
		{
			*(int *)(fhdr->data + ((i * fhdr->width + x) * 4 + 54)) =
				pixels[y * fhdr->width + x];
		}
		i++;
	}
}

void			generatebmp(const char *path, const char *name, int *px,
	t_vec2 s)
{
	int				fd;
	int				err;
	char			pn[NAME_MAX + PATH_MAX];
	t_bmp_header	fhdr;

	if ((fd_check_param(name, ".bmp")) == false)
		name = "tickle_me_i_didnt_put_a_filename.bmp";
	my_strcpy(pn, path);
	my_strcat(pn, name);
	if ((fd = fd_check_dest(pn)) < 0)
		debugerror(0, (fd == -1) ? "false" : "Canceled");
	else
	{
		if ((err = generateheaderfromsdl(&fhdr, s.x, s.y)) != true)
			debugerror(err, "in generatebmp.c");
		else
		{
			addbmpdata(px, &fhdr);
			write(fd, fhdr.data, fhdr.fsize);
			free(fhdr.data);
		}
		close(fd);
	}
	free(px);
}

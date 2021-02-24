/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:27:55 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

int				bmpcolorconvert(t_bmp_header bmp, int x, int y)
{
	int			iclr;
	int			color;
	t_rtcolor	ret;

	iclr = ((y * bmp.width + x) * 4) + bmp.bmpinfo.size;
	color = *(int *)(bmp.data + iclr);
	ret.bgra[2] = convertcolor(component_mask(color,
		bmp.bmpinfo.maskred), countbymask(bmp.bmpinfo.maskred), 8);
	ret.bgra[1] = convertcolor(component_mask(color,
		bmp.bmpinfo.maskgreen), countbymask(bmp.bmpinfo.maskgreen), 8);
	ret.bgra[0] = convertcolor(component_mask(color,
		bmp.bmpinfo.maskblue), countbymask(bmp.bmpinfo.maskblue), 8);
	ret.bgra[3] = convertcolor(component_mask(color,
		bmp.bmpinfo.maskalfa), countbymask(bmp.bmpinfo.maskalfa), 8);
	return ((int)ret.color);
}

int				*generateimage(t_bmp_header bmp)
{
	int			*img;
	int			x;
	int			y[2];

	if (!(img = (int *)malloc(bmp.bmpinfo.isize)))
		return (NULL);
	y[0] = 0;
	y[1] = bmp.height;
	while (--y[1])
	{
		x = -1;
		while (++x < bmp.width)
			img[y[0] * bmp.width + x] = bmpcolorconvert(bmp, x, y[1]);
		y[0]++;
	}
	return (img);
}

t_bmp_info		generateinfo(void *data)
{
	t_bmp_info	bmpinfo;

	my_bzero(&bmpinfo, sizeof(t_bmp_info));
	bmpinfo.size = *(int *)(data);
	bmpinfo.convert = *(short *)(data + 16);
	bmpinfo.isize = *(int *)(data + 20);
	bmpinfo.ncpalette = *(int *)(data + 32);
	bmpinfo.ncimportant = *(int *)(data + 36);
	bmpinfo.maskred = *(int *)(data + 40);
	bmpinfo.maskgreen = *(int *)(data + 44);
	bmpinfo.maskblue = *(int *)(data + 48);
	bmpinfo.maskalfa = *(int *)(data + 52);
	return (bmpinfo);
}

bool			generateheader(int fd, t_bmp_header *bmpheader, void *data)
{
	void		*data2;
	t_bmp_info	bmpinfo;

	if (!fd || !data)
	{
		debugerror(0, "wrong fd or fail to read it");
		return (false);
	}
	my_bzero(&bmpinfo, sizeof(t_bmp_info));
	bmpheader->fsize = *(int *)(data + 2);
	bmpheader->nframes = *(int *)(data + 6);
	data2 = readncharacter(fd, bmpheader->fsize - 14);
	if (data2 == NULL)
	{
		debugerror(0, "fail to read fd");
		return (false);
	}
	bmpheader->width = *(int *)(data2 + 4);
	bmpheader->height = *(int *)(data2 + 8);
	bmpheader->formats = *(uint16_t *)(data2 + 14);
	bmpheader->bmpinfo = generateinfo(data2);
	bmpheader->data = data2;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:28:22 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

int			fd_check_dest(const char *path)
{
	int		fd;
	char	c;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (open(path, O_WRONLY | O_CREAT,
			S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH));
	else
		ft_putendl("Already exits, do you want to Replace? Append? or Cancel?");
	close(fd);
	read(0, &c, 1);
	if (c == 'C' || c == 'c')
		return (-2);
	else if (c == 'R' || c == 'r')
	{
		if (!(remove(path)))
			return (open(path, O_WRONLY | O_CREAT,
				S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH));
		else
			return (-2);
	}
	else if (c == 'A' || c == 'a')
		return (open(path, O_WRONLY | O_APPEND));
	return (-1);
}

bool		fd_check_param(const char *src, char *ext)
{
	unsigned int	s1;
	unsigned int	s2;

	s1 = my_strlen(src);
	s2 = my_strlen(ext);
	if (!(src) || !(ext) || s1 < s2)
		return (false);
	return ((my_strcmp(src + s1 - s2, ext)) ? false : true);
}

int			fd_check_open(const char *file)
{
	int fd;

	if ((fd_check_param(file, ".bmp")) == false)
	{
		debugerror(0, "usage : file.bmp");
		return (-1);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		debugerror(0, "invalide file or doesn't exist");
		return (-1);
	}
	return (fd);
}

void		*readncharacter(int fd, int len)
{
	char	*new;
	int		ret;

	if (!fd)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * len)))
	{
		debugerror(ERR_MALLOC, "fd_gestion.c");
		return (NULL);
	}
	if ((ret = read(fd, new, len)) < 0)
	{
		debugerror(0, "file can't be read, or wrong length needed.");
		free(new);
		return (NULL);
	}
	return ((void *)(new));
}

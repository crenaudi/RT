/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:08:47 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:17:41 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void	ft_putendl(char const *s)
{
	if (!s)
		write(1, "(null)", 6);
	else
		write(1, s, my_strlen(s));
	write(1, "\n", 1);
}

void	*my_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n-- > 0)
		*s2++ = (unsigned char)c;
	return (s);
}

void	my_bzero(void *s, size_t n)
{
	my_memset(s, '\0', n);
}

void	*my_memalloc(size_t size)
{
	char	*pointeur;

	if (!(pointeur = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	my_bzero(pointeur, size);
	return (pointeur);
}

size_t	my_strlen(const char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

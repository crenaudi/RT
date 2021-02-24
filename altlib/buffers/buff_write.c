/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 14:28:23 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../altlib.h"

bool	buff_write(char *buff_ptr, const char *data, const size_t size)
{
	size_t	buff_len;
	size_t	leftover;

	if (!buff_ptr || !data || !size)
		return (false);
	leftover = buff_get_remainder(buff_ptr);
	buff_len = BUFFSIZE - leftover - 1;
	if (leftover >= size)
	{
		ft_strncpy(buff_ptr + buff_len, data, size);
	}
	else
	{
		ft_strncpy(buff_ptr + buff_len, data, leftover);
		buff_flush(buff_ptr);
		buff_write(buff_ptr, data + leftover, size - leftover);
	}
	return (true);
}

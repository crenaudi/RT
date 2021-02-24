/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:49:27 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./strings.h"
#include "../mem/mem.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *haystackptr;
	const char *needleptr;

	if (!haystack)
		return (NULL);
	if (*needle == '\0')
		return (NULL);
	while (*haystack)
	{
		haystackptr = haystack;
		needleptr = needle;
		while (*haystack && *needleptr && *haystack == *needleptr)
		{
			haystack++;
			needleptr++;
		}
		if (!*needleptr)
			return (char *)haystackptr;
		haystack = haystackptr + 1;
	}
	return (NULL);
}

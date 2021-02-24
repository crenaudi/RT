/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:24:27 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:38:26 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

const char	**ret_type_strings(void)
{
	static const char *type_strings[__SDF_TOTAL] = {
	"capsule",
	"cone",
	"cube",
	"custom",
	"cylinder",
	"elli",
	"none",
	"octa",
	"plane",
	"sphere",
	"torus"};

	return (&type_strings[0]);
}

char		*get_substring(char *buff, char *start, char *end)
{
	char		*str_start_end[2];
	char		string_buff[500];
	ptrdiff_t	ptr_diff;
	ptrdiff_t	i;
	char		*ret;

	ret = NULL;
	i = 0;
	str_start_end[0] = ft_strstr(buff, start);
	if (!str_start_end[0])
		return (NULL);
	str_start_end[1] = ft_strstr(str_start_end[0], end);
	if (!str_start_end[1])
		return (NULL);
	bzero(string_buff, sizeof(string_buff));
	ptr_diff = (char *)str_start_end[1] - (char *)str_start_end[0];
	while (i < ptr_diff && str_start_end[0] != str_start_end[1])
	{
		string_buff[i] = *str_start_end[0];
		str_start_end[0]++;
		i++;
	}
	ret = strdup(string_buff + ft_strlen(start));
	return (ret);
}

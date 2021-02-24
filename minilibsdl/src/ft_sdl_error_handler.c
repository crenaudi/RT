/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/11 13:36:05 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minilibsdl.h"

static size_t		my_strlen(const char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static const char	*error_messages(int n)
{
	const char	*error_messages[2] = { NULL,
		"Missing window intializer variable.\n"};

	return (error_messages[n]);
}

void				strcat_w_endl(char *stackstr, const char *txt,
	const char *endl_char)
{
	strcpy(stackstr + strlen(stackstr), txt);
	strcpy(stackstr + strlen(stackstr), endl_char);
}

void				sdl_error_handler(const char *err_source,
	const char *err_function, int err_code)
{
	static char err_str[256];

	strcat_w_endl(err_str, err_source, " -> ");
	strcat_w_endl(err_str, err_function, " : ");
	if (err_code == SDL_ERROR)
		strcat_w_endl(err_str, SDL_GetError(), "\n\0");
	else
		strcat_w_endl(err_str, error_messages(err_code), "\n\0");
	write(1, err_str, my_strlen(err_str));
}

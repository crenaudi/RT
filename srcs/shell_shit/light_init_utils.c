/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:32:11 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 18:19:03 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

t_vec3f	set_default_light_pos(t_lightpoint *light)
{
	t_vec3f ret;

	ret = (t_vec3f){0, 1, 0};
	ft_putstr("[SET_DEFAULT_LIGHT_POS] No input for light ID[");
	ft_putstr(light->id);
	ft_putendl("], pos set to default x:0 y:0 z:0");
	return (ret);
}

t_vec3f	set_default_light_intensity(t_lightpoint *light)
{
	t_vec3f ret;

	ret = (t_vec3f){1, 1, 1};
	ft_putstr("[SET_DEFAULT_LIGHT_INTENSITY] No input for light ID[");
	ft_putstr(light->id);
	ft_putendl("], intensity set to default x:1 y:1 z:1");
	return (ret);
}

t_vec3f	set_default_light_col(t_lightpoint *light, int flag)
{
	t_vec3f ret;

	ret = (t_vec3f){255, 255, 255};
	if (flag == 0)
		ft_putstr("[SET_DEFAULT_LIGHT_DIFFUSE_COLOR] No input for light ID[");
	else if (flag == 1)
		ft_putstr("[SET_DEFAULT_LIGHT_SPECULAR_COLOR] No input for light ID[");
	ft_putstr(light->id);
	ft_putendl("], diffuse color set to default r:255 g:255 b:255");
	return (ret);
}

void	parse_light(char *command_line, t_lightpoint *light, int flag)
{
	char	*input;
	t_vec3f	proxy;

	(void)flag;
	input = NULL;
	if (!(input = get_substring(command_line, "pos{", "}"))
		|| (check_if_null(proxy = get_vec(input, "x:", "y:", "z:"))))
		light->light_data.origin = set_default_light_pos(light);
	else
		light->light_data.origin = proxy;
	if (input)
		free(input);
	if (!(input = get_substring(command_line, "col{", "}"))
		|| (check_if_null(proxy = vec3f_div_k(get_color(input,
			"r:", "g:", "b:"), 255))))
	{
		light->light_data.direction = (ft_strstr(input, "r:V g:V b:V")) ?
		set_default_light_intensity(light) : (t_vec3f){1., 1., 1.};
	}
	else
		light->light_data.direction = proxy;
	if (input)
		free(input);
}

char	*set_default_id_light(size_t num)
{
	int		index;
	char	*id;
	char	digit;

	digit = '0';
	if (!(id = (char*)malloc(10 * sizeof(char))))
		return (NULL);
	ft_bzero(id, 10 * sizeof(char));
	index = num;
	strcpy(id, "light_00");
	if (10 < index)
	{
		digit = (index / 10) + '0';
		id[7] = digit;
		index = index % 10;
	}
	if (index < 10)
	{
		digit = index + '0';
		id[8] = digit;
	}
	return (id);
}

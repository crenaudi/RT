/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:44:22 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 15:58:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include "../../altlib/altlib.h"
#include "../../includes/rt_threads.h"

void	builtin_create(t_object *obj, char *buff, t_rt_utils *utils)
{
	t_op_utils	obj_data;
	int			index;

	(void)utils;
	index = 0;
	obj_data = parse_input(buff, (char *[2]){NULL, NULL},
		(char *[2]){NULL, NULL}, obj);
	if (!obj_data.id)
	{
		message(BUILTIN_CREATE, CREATE_COULD_NOT_CREATE, NULL, false);
		return ;
	}
	ft_putstr(">>>>>>> UWU WE PARSED ");
	ft_putendl(obj_data.operation);
	index = get_last_index(obj);
	get_object_data(&obj[index], &obj_data);
	get_disp_data(&obj[index], buff);
	utils->nb_object += 1;
}

void	insert_obj_at_end(t_object *obj, t_object obj_new, char *new_name)
{
	size_t i;

	i = 0;
	while (obj[i].type != NONE)
		i++;
	obj[i] = obj_new;
	obj[i].id = new_name;
	obj[i + 1].type = NONE;
}

void	builtin_display(t_object *obj, char *buff, t_rt_utils *utils)
{
	(void)buff;
	(void)obj;
	get_thr_data(utils->thr, utils->thr_data);
	write_colors_to_image(utils->thr_data, utils->sdl_objs->renderer);
	ft_putstr("[__SHELL_BUILTIN_DISPLAY] -> Renderered image!\n");
	SDL_RenderPresent(utils->sdl_objs->renderer);
}

void	builtin_load_scene(t_object *obj, char *buff, t_rt_utils *utils)
{
	builtin_clear(obj, NULL, NULL);
	interpret_source(ft_strnext(buff, false), obj, utils);
	builtin_display(obj, buff, utils);
	ft_putstr("\n[__SHELL_MESSAGE] Done.\n");
}

void	builtin_quit(t_object *obj, char *buff, t_rt_utils *utils)
{
	(void)buff;
	if (utils->loaded_textures)
		destroy_all_loaded_textures(utils->loaded_textures);
	if (utils->thr_data)
		free_thread_data(utils->thr_data);
	if (obj)
		free_obj_data(obj, utils->nb_object);
	utils->loaded_textures = NULL;
	utils->thr_data = NULL;
	utils->obj = NULL;
	ft_sdl_cleanup(utils->sdl_objs, false);
	ft_putstr("Bye!\n");
	exit(0);
}

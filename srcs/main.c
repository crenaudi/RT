/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/rt_threads.h"

t_object	*ret_blank_obj_list(void)
{
	t_object	*object_list;
	t_object	none;
	int			i;

	object_list = (t_object *)malloc(sizeof(t_object) * 100);
	if (!object_list)
	{
		return (NULL);
	}
	i = 0;
	none.type = NONE;
	none.deformation = DEFNONE;
	none.disp = DISP_NONE;
	get_vec3_identity_matrix(none.rot_mat);
	while (i < MAX_OBJ)
	{
		object_list[i] = none;
		i++;
	}
	return (object_list);
}

t_lights	*ret_blank_light_list(void)
{
	t_lights	*lights_list;

	lights_list = (t_lights *)malloc(sizeof(t_lights));
	if (!lights_list)
	{
		return (NULL);
	}
	lights_list->num = 0;
	lights_list->lights = (t_lightpoint *)malloc(sizeof(t_lightpoint)
			* MAX_LIGHTS);
	bzero(lights_list->lights, sizeof(t_lightpoint) * MAX_LIGHTS);
	return (lights_list);
}

int			main(int ac, char *av[])
{
	t_sdl_objs		sdl;
	t_rt_utils		event_loop_data;
	pthread_t		thr[NUM_THREADS];
	t_thread_data	*thr_data;

	ft_sdl_full_init(&sdl, (int[2]){SCREEN_W, SCREEN_H}, "OMEGART", true);
	event_loop_data.cam = &(t_cam){.posdata = (t_ray){.origin =
						(t_vec3f){0, 1, 7},
						.direction = (t_vec3f){0.0, 0.0, 0.0}},
						.fov = 45.0f, .focus = (t_vec3f){0, 0, 0}};
	event_loop_data.obj = ret_blank_obj_list();
	event_loop_data.lights = ret_blank_light_list();
	event_loop_data.sdl_objs = &sdl;
	event_loop_data.screen_dat = (t_vec3f){SCREEN_W, SCREEN_H, 0};
	event_loop_data.loaded_textures = load_textures(return_texture_names());
	thr_data = setup_threads(&event_loop_data, event_loop_data.loaded_textures);
	event_loop_data.thr = thr;
	event_loop_data.thr_data = thr_data;
	event_loop_data.nb_object = 0;
	if (ac == 2)
		interpret_source(av[1], event_loop_data.obj, &event_loop_data);
	rt_event_loop(&event_loop_data);
	ft_sdl_cleanup(&sdl, false);
	SDL_Quit();
	return (0);
}

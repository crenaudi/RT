/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_event_loop.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_EVENT_LOOP_H
# define RT_EVENT_LOOP_H
# include "../minilibsdl/include/ft_minilibsdl.h"
# include "../BSVL/bsvl.h"
# include "../includes/rt_object.h"

typedef struct		s_thread_data
{
	SDL_Renderer	*renderer;
	t_cam			*cam;
	t_object		*obj;
	t_lights		*lights;
	t_vec3f			lim;
	int				x;
	int				y;
	int				thr_id;
	SDL_Surface		**textures;
	t_vec3f			*colors;
}					t_thread_data __attribute__((aligned));

typedef struct		s_rt_utils
{
	t_sdl_objs		*sdl_objs;
	t_cam			*cam;
	t_object		*obj;
	t_lights		*lights;
	t_vec3f			screen_dat;
	SDL_Surface		**loaded_textures;
	SDL_Renderer	*renderer;
	pthread_t		*thr;
	t_thread_data	*thr_data;
	int				nb_object;
}					t_rt_utils;

void				free_obj_data(t_object *obj, int n);

#endif

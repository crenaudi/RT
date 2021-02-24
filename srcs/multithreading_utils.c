/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../includes/rt_threads.h"

void			write_colors_to_image(t_thread_data *data, SDL_Renderer *rend)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		x = data[i].x;
		y = data[i].y;
		while (y++ < data[i].lim.y)
		{
			while (x++ < data[i].lim.x)
			{
				SDL_SetRenderDrawColor(rend,
								data[i].colors[(SCREEN_H * y) + x].x,
								data[i].colors[(SCREEN_H * y) + x].y,
								data[i].colors[(SCREEN_H * y) + x].z,
								255);
				SDL_RenderDrawPoint(rend, x, y);
			}
			x = data[i].x;
		}
		i++;
	}
}

void			free_thread_data(t_thread_data *thr_data)
{
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		free(thr_data[i].colors);
		i++;
	}
	ft_putendl("Freed all thread data.");
}

void			get_thr_data(pthread_t *thr, t_thread_data *thr_data)
{
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		if (pthread_create(&thr[i], NULL, display_scene, &thr_data[i]))
		{
			ft_putstr("Thread creation error. exitting...\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_putstr("joining threads...\n");
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(thr[i], NULL);
		i++;
	}
	ft_putstr("joined threads!\n");
}

t_thread_data	*setup_threads(t_rt_utils *utils, SDL_Surface **textures)
{
	int						index;
	int						line;
	int						i;
	static t_thread_data	thr_data[NUM_THREADS];

	index = 0;
	line = 0;
	i = 0;
	while (i < NUM_THREADS)
	{
		if (i % 32 == 0 && i != 0)
			line++;
		index = i - line * 32;
		thr_data[i] = (t_thread_data)
			{
				.cam = utils->cam, .obj = utils->obj,
				.lights = utils->lights, .lim = (t_vec3f){
					index * 20 + 20, line * 15 + 15, 0},
				index * 20, line * 15,
				.colors = (t_vec3f *)malloc(sizeof(t_vec3f)
						* (SCREEN_H * SCREEN_W)),
				.thr_id = i, .textures = textures};
		i++;
	}
	return (thr_data);
}

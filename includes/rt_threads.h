/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by tigondol          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_THREADS_H
# define RT_THREADS_H
# include "../includes/rt.h"

void			write_colors_to_image(t_thread_data *data,
					SDL_Renderer *renderer);
void			free_thread_data(t_thread_data *thr_data);
void			get_thr_data(pthread_t *thr, t_thread_data *thr_data);
t_thread_data	*setup_threads(t_rt_utils *utils, SDL_Surface **textures);

#endif

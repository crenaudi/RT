/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 20:02:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void		destroy_tx(t_texture *tx)
{
	if (!tx)
		return ;
	if (tx->data)
	{
		ft_bzero(tx->data, sizeof(int) * tx->size.x * tx->size.y * tx->nframes);
		free(tx->data);
	}
	if (tx->frames)
	{
		ft_bzero(tx->frames, sizeof(int*) * tx->nframes);
		free(tx->frames);
	}
	ft_bzero(tx, sizeof(t_texture));
	free(tx);
	ft_putendl("Free texture menu");
}

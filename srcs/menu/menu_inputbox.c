/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_inpubox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:31:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

t_input		*init_input(t_texture *tx)
{
	t_input		*input;

	if (!(input = (t_input *)malloc(sizeof(t_input))))
		return (NULL);
	ft_bzero(input, sizeof(t_input));
	ft_bzero(input->str, sizeof(char) * BUFF_INPUT);
	ft_bzero(input->storage, sizeof(char) * BUFF_STORAGE);
	input->padding.x = 60;
	input->padding.y = 13;
	input->ip = 0;
	input->is = 0;
	input->step = 0;
	input->hitbox_cancel[0] = tx->pos.x + 5;
	input->hitbox_cancel[1] = input->hitbox_cancel[0] + 40;
	input->hitbox_cancel[2] = tx->pos.y + 6;
	input->hitbox_cancel[3] = input->hitbox_cancel[2] + 30;
	input->hitbox_valide[0] = input->hitbox_cancel[0] + 160;
	input->hitbox_valide[1] = input->hitbox_cancel[1] + 160;
	input->hitbox_valide[2] = input->hitbox_cancel[2];
	input->hitbox_valide[3] = input->hitbox_cancel[3];
	return (input);
}

void		fill_input(t_input *input, int i, int process)
{
	if (!input)
		return ;
	ft_bzero(input->str, sizeof(char) * BUFF_INPUT);
	find_process(input, process);
	input->ip = i;
	input->is = 0;
	input->step = 0;
}

void		clear_input(t_input *input)
{
	if (!input)
		return ;
	ft_bzero(input->storage, sizeof(char) * BUFF_STORAGE);
	ft_bzero(input->str, sizeof(char) * BUFF_INPUT);
	input->ip = 0;
	input->is = 0;
	input->step = 0;
}

void		destroy_input(t_input *input)
{
	if (!input)
		return ;
	clear_input(input);
	ft_bzero(input, sizeof(t_input));
	free(input);
}

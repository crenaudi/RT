/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibsdl/include/ft_minilibsdl.h"
#include "../BSVL/bsvl.h"
#include "../includes/rt.h"

void	handle_arrows(t_rt_utils *utils, int key)
{
	if (key == SDLK_UP)
	{
		get_and_apply_translation_matrix(&utils->cam->posdata.origin
			, vec3f_mul_k(vec3f_sub_vec(utils->cam->posdata.origin
			, utils->cam->focus), -0.1));
		image_maker(utils);
	}
	if (key == SDLK_DOWN)
	{
		get_and_apply_translation_matrix(&utils->cam->posdata.origin
			, vec3f_mul_k(vec3f_sub_vec(utils->cam->posdata.origin
			, utils->cam->focus), 0.1));
		image_maker(utils);
	}
}

void	wasd_handler(t_rt_utils *utils, int key)
{
	if (key == SDLK_d)
	{
		get_and_apply_rotation_matrix(deg_to_rad(50), Y
			, &utils->cam->posdata.origin);
		image_maker(utils);
	}
	if (key == SDLK_a)
	{
		get_and_apply_rotation_matrix(deg_to_rad(-50), Y
			, &utils->cam->posdata.origin);
		image_maker(utils);
	}
	if (key == SDLK_w)
	{
		get_and_apply_translation_matrix(&utils->cam->posdata.origin
			, (t_vec3f){0, 1, 0});
		image_maker(utils);
	}
	if (key == SDLK_s)
	{
		get_and_apply_translation_matrix(&utils->cam->posdata.origin
			, (t_vec3f){0, -1, 0});
		image_maker(utils);
	}
}

void	camera_move(t_rt_utils *utils, int key)
{
	handle_arrows(utils, key);
	wasd_handler(utils, key);
	if (key == SDLK_PAGEUP)
	{
		get_and_apply_translation_matrix(&utils->cam->focus
			, (t_vec3f){0, 1, 0});
		image_maker(utils);
	}
	if (key == SDLK_PAGEDOWN)
	{
		get_and_apply_translation_matrix(&utils->cam->focus
			, (t_vec3f){0, -1, 0});
		image_maker(utils);
	}
}

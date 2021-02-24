/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:26:11 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 17:29:59 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	builtin_print_cam(t_object *obj, char *command_line, t_rt_utils *utils)
{
	(void)obj;
	(void)command_line;
	ft_putstr("[PRINT_CAM]\nPOSTION: ");
	print_tvec3f(utils->cam->posdata.origin);
	ft_putstr("\nDIRECTION: ");
	print_tvec3f(utils->cam->posdata.direction);
	ft_putstr("\nFOV: ");
	ft_putfloat(utils->cam->fov);
	ft_putstr("\nFOCUS: ");
	print_tvec3f(utils->cam->focus);
	ft_putstr("\n");
}

void	builtin_change_focus(t_object *obj, char *buff, t_rt_utils *utils)
{
	char	*focus;
	t_vec3f f;

	(void)obj;
	if (!(focus = get_substring(buff, "focus{", "}")))
	{
		message(BUILTIN_CHANGE_FOCUS, CHANGE_FOCUS_NO_POS, NULL, false);
		return ;
	}
	f = get_vec(focus, "x:", "y:", "z:");
	utils->cam->focus = f;
	if (focus)
		free(focus);
}

void	builtin_change_fov(t_object *obj, char *buff, t_rt_utils *utils)
{
	char *fov;

	(void)obj;
	if (!(fov = get_substring(buff, "fov{", "}")))
	{
		message(BUILTIN_CHANGE_FOCUS, CHANGE_FOV_NO_FOV, NULL, false);
		return ;
	}
	utils->cam->fov = atof(fov);
	if (fov)
		free(fov);
}

void	builtin_focus_obj(t_object *obj, char *buff, t_rt_utils *utils)
{
	char		*id;
	t_object	*traveller;

	if (!(id = get_substring(buff, "id{", "}")))
	{
		message(BUILTIN_FOCUS_OBJ, CHANGE_FOCUS_OBJ_NO_ID, NULL, false);
		return ;
	}
	if (!(traveller = find_object_by_id(obj, id)))
	{
		message(BUILTIN_FOCUS_OBJ, OBJ_NOT_FOUND, NULL, false);
		return ;
	}
	utils->cam->focus = traveller->pos;
	if (id)
		free(id);
}

void	builtin_move_cam(t_object *obj, char *buff, t_rt_utils *utils)
{
	char		*data;
	t_vec3f		pos;

	(void)obj;
	if (!(data = get_substring(buff, "pos{", "}")))
	{
		message(BUILTIN_MOVE_CAM, MOVE_CAM_NO_POS, NULL, false);
		return ;
	}
	pos = get_vec(data, "x:", "y:", "z:");
	utils->cam->posdata.origin = pos;
	if (data)
		free(data);
}

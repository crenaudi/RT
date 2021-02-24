/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:31:14 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 18:31:25 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char	**ret_error_strings(void)
{
	static const char *error_messages[__ERRCODE_TOTAL] = {
		[CHANGE_FOCUS_NO_POS] = "no pos to focus provided ",
		[CHANGE_FOCUS_OBJ_NO_ID] = "no id provided ",
		[CHANGE_FOV_NO_FOV] = "no fov provided ",
		[CREATE_COULD_NOT_CREATE] = "could not create ",
		[CREATE_MISSING_OBJ_TYPE] = "missing obj type ",
		[CREATE_SET_DEFAULT_COL] = "set default col (255, 255, 255) ",
		[CREATE_SET_DEFAULT_DISP] = "set default displacement (none) ",
		[CREATE_SET_DEFAULT_ID] = "set default id ",
		[CREATE_SET_DEFAULT_MAT] = "set default mat (solid_color) ",
		[CREATE_SET_DEFAULT_OP] = "set default op (none) ",
		[CREATE_SET_DEFAULT_POS] = "set default pos (0, 1, 0) ",
		[CREATE_SET_DEFAULT_SHIN] = "set default shininess (0) ",
		[CREATE_UNKNOWN_OBJ_TYPE] = "unknown obj type ",
		[INIT_CAPSULE_NO_A] = "no attr vec3 a  provided ",
		[INIT_CAPSULE_NO_B] = "no attr vec3 b  provided ",
		[INIT_CAPSULE_NO_R] = "no attr float r provided ",
		[INIT_CONE_NO_C] = "no attr vec3 c provided ",
		[INIT_CUBE_NO_B] = "no attr vec3 b{} provided ",
	};

	return (error_messages);
}

static const char	**ret_error_strings2(void)
{
	static const char *error_messages[__ERRCODE_TOTAL] = {
		[INIT_CYL_NO_A] = "no attr vec3 a provided ",
		[INIT_CYL_NO_B] = "no attr vec3 b provided ",
		[INIT_CYL_NO_H] = "no attr float h provided ",
		[INIT_CYL_NO_R] = "no attr float r provided ",
		[INIT_OCTA_NO_S] = "no attr float s provided ",
		[INIT_PLANE_NO_H] = "no attr float h provided ",
		[INIT_PLANE_NO_O] = "no attr vec3 b{} provided ",
		[INIT_SPHERE_NO_RAD] = "no rad ",
		[INIT_TORUS_NO_R1] = "no attr float r1 provided ",
		[INIT_TORUS_NO_R2] = "no attr float r2 provided ",
		[INVALID_VEC3] = "Invalid vec3 ",
		[MATERIAL_NOT_FOUND] = "material not found ",
		[MOVE_CAM_NO_POS] = "no position given ",
		[NOT_FOUND] = "not found ",
		[NO_ARGS_PASSED] = "no arguments passed ",
		[OBJ_NOT_FOUND] = "object not found ",
		[WRONG_INPUT] = "wrong input for ",
	};

	return (error_messages);
}

void				message(enum e_builtins caller, t_e_errcode err, char *add,
	bool exitp)
{
	static char buff[BUFFSIZE];
	const char	*caller_name_str;
	const char	*error_str;

	ft_bzero(buff, BUFFSIZE);
	caller_name_str = ret_builtin_names()[caller];
	if (err >= 0 && err <= INIT_CUBE_NO_B)
		error_str = ret_error_strings()[err];
	else
		error_str = ret_error_strings2()[err];
	buff_write(&buff[0], caller_name_str, ft_strlen(caller_name_str));
	buff_write(&buff[0], " : ", 1);
	buff_write(&buff[0], error_str, ft_strlen(error_str));
	if (add)
		buff_write(&buff[0], add, ft_strlen(add));
	buff_write(&buff[0], ".\n", 1);
	buff_flush(&buff[0]);
	if (exitp)
		exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:19:51 by tigondol          #+#    #+#             */
/*   Updated: 2021/01/13 17:09:10 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include <stdbool.h>
#include "../../altlib/altlib.h"

void			first_half(int fn, t_object *o, char *b, t_rt_utils *u)
{
	static void	(*arr[BUILTIN_TOTAL])(t_object *, char *, t_rt_utils *) = {
		[BUILTIN_APPLY_OP] = &builtin_apply_op,
		[BUILTIN_CHANGE_ATTR] = &builtin_change_attr,
		[BUILTIN_CHANGE_FOCUS] = &builtin_change_focus,
		[BUILTIN_CHANGE_FOV] = &builtin_change_fov,
		[BUILTIN_CHANGE_ID] = &builtin_change_id,
		[BUILTIN_CHANGE_ORDER] = &builtin_change_order,
		[BUILTIN_CLEAR] = &builtin_clear,
		[BUILTIN_CREATE_LIGHT] = &builtin_create_light,
		[BUILTIN_CREATE] = &builtin_create,
		[BUILTIN_DELETE_LIGHT] = &builtin_delete_light,
		[BUILTIN_DELETE_OBJECT] = &builtin_delete_object,
		[BUILTIN_DISPLAY] = &builtin_display};

	arr[fn](o, b, u);
}

void			second_half(int fn, t_object *o, char *b, t_rt_utils *u)
{
	static void	(*arr[BUILTIN_TOTAL])(t_object *, char *, t_rt_utils *) = {
		[BUILTIN_DUMP_BMP] = &builtin_bmp,
		[BUILTIN_FOCUS_OBJ] = &builtin_focus_obj,
		[BUILTIN_LOAD_SCENE] = &builtin_load_scene,
		[BUILTIN_MOVE_CAM] = &builtin_move_cam,
		[BUILTIN_PRINT_CAM] = &builtin_print_cam,
		[BUILTIN_PRINT_LIGHT_LIST] = &builtin_print_light_list,
		[BUILTIN_PRINT_LIGHT] = &builtin_print_light,
		[BUILTIN_PRINT_LIST] = &print_object_list,
		[BUILTIN_QUIT] = &builtin_quit,
		[BUILTIN_ROTATE] = &builtin_obj_rotate,
		[BUILTIN_TRANSLATE] = &builtin_obj_translate};

	arr[fn](o, b, u);
}

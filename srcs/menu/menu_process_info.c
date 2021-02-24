/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 20:02:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

static void		enum_process(char *cmd[BUILTIN_TOTAL])
{
	cmd[BUILTIN_LOAD_SCENE] = "S";
	cmd[BUILTIN_DUMP_BMP] = "dump_bmp name{S}";
	cmd[BUILTIN_APPLY_OP] = "apply_op";
	cmd[BUILTIN_CHANGE_ATTR] = "change_attr id{S} attr{S}";
	cmd[BUILTIN_CHANGE_FOCUS] = "change_focus focus{x:V y:V z:V}";
	cmd[BUILTIN_CHANGE_FOV] = "change_fov fov{V}";
	cmd[BUILTIN_CHANGE_ID] = "change_id id1{S} id2{S}";
	cmd[BUILTIN_CHANGE_ORDER] = "change_order id1{S} id2{S}";
	cmd[BUILTIN_CLEAR] = "clear";
	cmd[BUILTIN_CREATE] = "create type{T}";
	cmd[BUILTIN_CREATE_LIGHT] =
		"create_light id{S} pos{x:V y:V z:V} col{r:V g:V b:V}";
	cmd[BUILTIN_DELETE_LIGHT] = "delete_light id{S}";
	cmd[BUILTIN_DELETE_OBJECT] = "delete_object id{S}";
	cmd[BUILTIN_DISPLAY] = "display";
	cmd[BUILTIN_FOCUS_OBJ] = "focus_object id{S}";
	cmd[BUILTIN_FREECAM] = "freecam";
	cmd[BUILTIN_MOVE_CAM] = "move_cam pos{x:V y:V z:V}";
	cmd[BUILTIN_PRINT_CAM] = "print_cam";
	cmd[BUILTIN_PRINT_LIGHT] = "print_light id{S}";
	cmd[BUILTIN_PRINT_LIGHT_LIST] = "print_light_list";
	cmd[BUILTIN_PRINT_LIST] = "print_list";
	cmd[BUILTIN_QUIT] = "quit";
	cmd[BUILTIN_ROTATE] = "rotate id{S} rot{x:V y:V z:V}";
	cmd[BUILTIN_TRANSLATE] = "translate id{S} pos{x:V y:V z:V}";
}

void			find_process(t_input *input, int process)
{
	char	*cmd[BUILTIN_TOTAL];

	enum_process(cmd);
	copy_storage(input, cmd[process]);
}

void			find_create_process(t_input *input, int process)
{
	char	*cmd[__SDF_TOTAL];
	char	*opt;

	if (process < 0 || process >= __SDF_TOTAL)
		return ;
	opt = " pos{x:V y:V z:V} op{O} mat{M} col{r:V g:V b:V}";
	cmd[SDF_CUSTOM] = "none";
	cmd[NONE] = "none";
	cmd[SDF_CAPSULE] =
		"create type{capsule} id{S} attr{x1:V y1:V z1:V x2:V y2:V z2:V}";
	cmd[SDF_CONE] = "create type{cone} id{S} attr{r:V h:V}";
	cmd[SDF_CUBE] = "create type{cube} id{S} attr{x:V y:V z:V}";
	cmd[SDF_CYLINDER] =
		"create type{cylinder} id{S} attr{x1:V y1:V z1:V x2:V y2:V z2:V}";
	cmd[SDF_ELLI] = "create type{elli} id{S} attr{x:V y:V z:V}";
	cmd[SDF_OCTA] = "create type{octa} id{S} attr{s:V}";
	cmd[SDF_PLANE] = "create type{plane} id{S} attr{x:V y:V z:V}";
	cmd[SDF_SPHERE] = "create type{sphere} id{S} attr{r:V}";
	cmd[SDF_TORUS] = "create type{torus} id{S} attr{r:V}";
	if (process != NONE && process != SDF_CUSTOM)
		copy_twostorage(input, cmd[process], opt);
	else
		copy_storage(input, cmd[process]);
}

char			*ret_opt(int select)
{
	char		*ret;
	const char	**opt;

	opt = ret_operation_names_array();
	ret = (char *)opt[select];
	return (ret);
}

char			*ret_mat(int select)
{
	char		*ret;
	const char	**mat;

	mat = ret_obj_material();
	ret = (char *)mat[select];
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:19:51 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/20 17:09:10 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell.h"
#include <stdbool.h>
#include "../../altlib/altlib.h"
#define OBJ_MAX 101

void			builtin_bmp(t_object *o, char *b, t_rt_utils *u)
{
	char	*found_name;
	char	name[NAME_MAX + PATH_MAX];

	(void)o;
	found_name = get_substring(b, "name{", "}");
	if (found_name != NULL)
	{
		my_strcpy(name, found_name);
		my_strcat(name, ".bmp");
		free(found_name);
	}
	else
		my_strcpy(name, "tickle_me_i_didnt_put_a_filename.bmp");
	get_thr_data(u->thr, u->thr_data);
	write_colors_to_image(u->thr_data, u->sdl_objs->renderer);
	generatebmp("./BMP/",
				name,
				renderer_int_tab(u->sdl_objs->renderer, SCREEN_W, SCREEN_H),
				(t_vec2){SCREEN_W, SCREEN_H});
}

void			builtin_caller(int fn, t_object *o, char *b, t_rt_utils *u)
{
	if (fn >= BUILTIN_APPLY_OP && fn <= BUILTIN_DISPLAY)
		first_half(fn, o, b, u);
	else if (fn >= BUILTIN_DUMP_BMP && fn <= BUILTIN_TRANSLATE)
		second_half(fn, o, b, u);
}

const char		**ret_obj_disp(void)
{
	static const char *obj_material[__MATERIAL_TOTAL] = {
		"bend",
		"none",
		"perlin",
		"sin",
		"twist"};

	return (obj_material);
}

const char		**ret_obj_material(void)
{
	static const char *obj_material[__MATERIAL_TOTAL] = {
		"checkers",
		"mirror_colored",
		"mirror_impure",
		"mirror_pure",
		"none",
		"polkadot",
		"solidcolor",
		"stone",
		"glass"};

	return (obj_material);
}

const char		**ret_builtin_names(void)
{
	static const char *builtin_names[BUILTIN_TOTAL] = {"apply_op",
		"change_attr",
		"change_focus",
		"change_fov",
		"change_id",
		"change_order",
		"clear",
		"create",
		"create_light",
		"delete_light",
		"delete_object",
		"display",
		"dump_bmp",
		"focus_object",
		"freecam",
		"load_scene",
		"move_cam",
		"print_cam",
		"print_light",
		"print_light_list",
		"print_list",
		"quit",
		"rotate", "translate"};

	return (builtin_names);
}

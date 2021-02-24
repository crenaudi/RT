/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:55:23 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 18:19:09 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SHELL_H
# define RT_SHELL_H
# include "../../includes/rt.h"
# include "../../altlib/altlib.h"
# include "../../includes/rt_event_loop.h"
# include "../../includes/rt_sdf.h"
# include "../../includes/rt_object.h"
# include "../../includes/rt_operations.h"
# include "../../includes/rt_materials.h"
# include "../../includes/rt_textures.h"
# include "../menu/include/rt_menu.h"

enum			e_builtins
{
	BUILTIN_APPLY_OP,
	BUILTIN_CHANGE_ATTR,
	BUILTIN_CHANGE_FOCUS,
	BUILTIN_CHANGE_FOV,
	BUILTIN_CHANGE_ID,
	BUILTIN_CHANGE_ORDER,
	BUILTIN_CLEAR,
	BUILTIN_CREATE,
	BUILTIN_CREATE_LIGHT,
	BUILTIN_DELETE_LIGHT,
	BUILTIN_DELETE_OBJECT,
	BUILTIN_DISPLAY,
	BUILTIN_DUMP_BMP,
	BUILTIN_FOCUS_OBJ,
	BUILTIN_FREECAM,
	BUILTIN_LOAD_SCENE,
	BUILTIN_MOVE_CAM,
	BUILTIN_PRINT_CAM,
	BUILTIN_PRINT_LIGHT,
	BUILTIN_PRINT_LIGHT_LIST,
	BUILTIN_PRINT_LIST,
	BUILTIN_QUIT,
	BUILTIN_ROTATE,
	BUILTIN_TRANSLATE,
	BUILTIN_TOTAL,
};

typedef enum	e_errcode
{
	CHANGE_FOCUS_NO_POS,
	CHANGE_FOCUS_OBJ_NO_ID,
	CHANGE_FOV_NO_FOV,
	CREATE_COULD_NOT_CREATE,
	CREATE_MISSING_OBJ_TYPE,
	CREATE_SET_DEFAULT_COL,
	CREATE_SET_DEFAULT_DISP,
	CREATE_SET_DEFAULT_ID,
	CREATE_SET_DEFAULT_MAT,
	CREATE_SET_DEFAULT_OP,
	CREATE_SET_DEFAULT_POS,
	CREATE_SET_DEFAULT_SHIN,
	CREATE_UNKNOWN_OBJ_TYPE,
	INIT_CAPSULE_NO_A,
	INIT_CAPSULE_NO_B,
	INIT_CAPSULE_NO_R,
	INIT_CONE_NO_C,
	INIT_CUBE_NO_B,
	INIT_CYL_NO_A,
	INIT_CYL_NO_B,
	INIT_CYL_NO_H,
	INIT_CYL_NO_R,
	INIT_OCTA_NO_S,
	INIT_PLANE_NO_H,
	INIT_PLANE_NO_O,
	INIT_SPHERE_NO_RAD,
	INIT_TORUS_NO_R1,
	INIT_TORUS_NO_R2,
	INVALID_VEC3,
	MATERIAL_NOT_FOUND,
	MOVE_CAM_NO_POS,
	NOT_FOUND,
	NO_ARGS_PASSED,
	OBJ_NOT_FOUND,
	WRONG_INPUT,
	__ERRCODE_TOTAL,
}				t_e_errcode;

typedef struct s_menu	t_menu;

typedef	struct	s_obj_data
{
	t_e_sdf				type;
	char				*obj_operation;
	char				*pos;
	char				*color;
	char				*attributs;
	char				*material;
	char				*shininess;
}				t_obj_data;

typedef struct	s_op_utils
{
	char				*id;
	char				*operation;
	char				*str1;
	char				*str2;
	t_obj_data			obj_data;
}				t_op_utils;

void			first_half(int fn, t_object *o, char *b, t_rt_utils *u);
void			second_half(int fn, t_object *o, char *b, t_rt_utils *u);
void			get_var_obj(t_object *obj, t_op_utils *data, char *orientation);
void			set_default_disp(t_object *obj);
const char		**ret_obj_disp(void);
t_e_disp		get_disp(char *data);
void			get_disp_data(t_object *obj, char *buff);
void			message(enum e_builtins caller, t_e_errcode error,
					char *additional, bool exit);
t_op_utils		parse_input(char *buff, char *start[2], char *end[2],
					t_object *obj_list);
void			parse_args(t_op_utils *new_obj, char *buff, char *start[2],
					char *end[2]);
t_object		*find_object_by_id(t_object *obj, char *id_to_find);
t_object		*obj_list_map(t_object *obj, void *private,
					void (*f)(t_object *, void *));
int				find_object_index(t_object *obj_list, char *id);
char			*get_substring(char *buff, char *start, char *end);
t_vec3f			get_vec(char *data, char *x, char *y, char *z);
int				get_last_index(t_object *obj_list);
int				check_if_null(t_vec3f vec);
void			print_tvec3f(t_vec3f vec);
t_e_material	get_material(char *data);
void			init_sphere(t_object *obj, t_op_utils *data);
void			init_torus(t_object *obj, t_op_utils *data);
void			init_cube(t_object *obj, t_op_utils *data);
void			init_octa(t_object *obj, t_op_utils *data);
void			init_plane(t_object *obj, t_op_utils *data);
void			init_capsule(t_object *obj, t_op_utils *data);
void			init_cylinder(t_object *obj, t_op_utils *data);
void			init_cone(t_object *obj, t_op_utils *data);
void			init_custom(t_object *obj, t_op_utils *data);
void			init_ellipsoid(t_object *obj, t_op_utils *data);
void			print_obj(t_object *obj_list, void *nothing);
void			set_default_pos_utils(t_op_utils *obj);
void			set_default_pos_obj(t_object *obj);
void			set_default_col_utils(t_op_utils *obj);
void			set_default_op_obj(t_object *obj);
void			set_default_op_utils(t_op_utils *obj);
char			*set_default_id_utils(t_op_utils *obj, t_object *obj_list);
void			set_default_id_obj(t_object *obj, t_object *obj_list);
void			set_default_mat_utils(t_op_utils *obj);
void			set_default_mat(t_object *obj);
void			set_default_shin(t_op_utils *obj);
void			shell_get_attr(char *input, t_op_utils *new_obj);
char			**splitwspc(char *string);
void			attr_error(t_object *obj);
void			change_attr_sphere(t_object **obj, char *data);
void			change_attr_cube(t_object **obj, char *data);
void			change_attr_octa(t_object **obj, char *data);
void			change_attr_plane(t_object **obj, char *data);
void			change_attr_torus(t_object **obj, char *data);
void			change_attr_capsule(t_object **obj, char *data);
void			print_attr_sphere(t_object *obj);
void			print_attr_torus(t_object *obj);
void			print_attr_cube(t_object *obj);
void			print_attr_octa(t_object *obj);
void			print_attr_plane(t_object *obj);
void			print_attr_capsule(t_object *obj);
void			print_attr_cylinder(t_object *obj);
void			print_attr_ellipsoid(t_object *obj);
const char		**ret_builtin_names(void);
const char		**ret_obj_material(void);
const char		**ret_operation_names_array(void);
const char		**ret_type_strings(void);
void			builtin_change_focus(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_change_fov(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_focus_obj(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_move_cam(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_print_cam(t_object *obj, char *command_line,
					t_rt_utils *utils);
t_lightpoint	*find_light_by_id(t_lights *light, char *id_to_find);
void			builtin_display(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_apply_noise(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_apply_op(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_change_attr(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_change_order(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_create(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_dup(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_load_object(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_load_scene(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_obj_translate(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_obj_rotate(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_delete_object(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_print_object(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_clear(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_quit(t_object *obj, char *buff, t_rt_utils *uils);
void			builtin_create_light(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_print_light(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_print_light_list(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_delete_light(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_change_id(t_object *obj, char *buff,
					t_rt_utils *uils);
void			builtin_bmp(t_object *o, char *b, t_rt_utils *u);
void			print_object_list(t_object *obj, char *buff,
					t_rt_utils *uils);
void			print_light_attr(t_lightpoint *light);
void			parse_light(char *command_line, t_lightpoint *light, int flag);
int				find_light_index(t_lights *light_list, char *id);
char			*set_default_id_light(size_t num);
t_vec3f			set_default_light_pos(t_lightpoint *light);
t_vec3f			set_default_light_intensity(t_lightpoint *light);
t_vec3f			set_default_light_col(t_lightpoint *light, int flag);
void			init_light(t_lightpoint *light);
void			shell(t_rt_utils *utils);
void			get_object_data(t_object *obj, t_op_utils *private);
void			builtin_print_object(t_object *obj, char *buff,
					t_rt_utils *utils);
void			get_object_attributes(t_object *obj, t_op_utils *obj_dat);
void			get_object_data(t_object *obj, t_op_utils *private);
const char		**ret_operation_names_array(void);
void			builtin_apply_op(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_change_id(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_change_order(t_object *obj, char *buff,
					t_rt_utils *utils);
void			print_tvec3f(t_vec3f vec);
void			print_rgb(t_vec3f vec);
void			print_object_common_attr(t_object *obj);
void			print_object_list(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_delete_object(t_object *obj, char *buff,
					t_rt_utils *utils);
void			builtin_caller(int fn, t_object *o, char *b, t_rt_utils *u);
void			builtin_caller_names_array_change_attr(int fn, t_object **obj,
					char *data);
void			builtin_caller_names_array_print_attr(int fn, t_object *obj);
void			builtin_caller_names_array(int fn, t_object *obj,
					t_op_utils *data);
void			set_default_disp(t_object *obj);
void			set_material_col_utils(t_op_utils *obj);
void			set_default_op_obj(t_object *obj);
void			set_default_op_utils(t_op_utils *obj);
void			builtin_caller_names_array_change_attr(int fn, t_object **obj,
					char *data);
void			change_attr_new_col(t_object **object, char *data);
void			change_attr_new_deformation(t_object **object, char *data);
void			change_attr_cone(t_object **obj, char *data);
void			change_attr_elli(t_object **obj, char *data);
void			change_attr_cylinder(t_object **obj, char *data);

t_vec3f			get_color(char *data, char *x, char *y, char *z);

#endif

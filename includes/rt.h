/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdbool.h>
# include "../BSVL/bsvl.h"
# include "../includes/rt.h"
# include "../includes/rt_sdf.h"
# include "../includes/rt_object.h"
# include "../includes/rt_operations.h"
# include "../includes/rt_materials.h"
# include "../includes/rt_textures.h"
# include "../minilibsdl/include/ft_minilibsdl.h"
# include "../srcs/shell_shit/lang/lang.h"
# include "../includes/rt_event_loop.h"
# include "../includes/rt_displacements.h"
# define SCREEN_H 480
# define SCREEN_W  640
# define NUM_THREADS 1024
# define MAX_STEPS    100
# define MAX_DIST     100.
# define SURFACE_DIST .0001
# define MAX_LIGHTS 10
# define MAX_OBJ 100

typedef	t_vec3f	t_color;

t_vec3f				get_pixel_color(t_thread_data *t,
						t_vec2f pos);

t_intersect_data	ray_march(t_ray ray,
						t_object *obj);

bool				check_limits(float to_origin, float to_scene);
float				get_point_illumination(t_ray camera,
							float min_distance_to_object_in_scene,
							t_object *object_list,
							t_intersect_data *intersect_data);
t_vec3f				get_normal(t_vec3f p,
						t_object *obj);
void				rt_event_loop(void *private);
void				camera_move(t_rt_utils *utils,
						int key);
t_intersect_data	get_dist(t_object *obj, t_vec3f rd);
void				*display_scene(void *args);
void				get_thr_data(pthread_t *thr,
						t_thread_data *thr_data);
void				image_maker(t_rt_utils *utils);
float				operation_caller(t_e_def op, float d1, float d2, float k);

float				deg_to_rad(double radians);

float				get_diffuse_contrib(t_intersect_data *intersect_data,
						t_ray lpos_lint);

float				get_diffuse_shadow(t_intersect_data *intersect_data,
						t_ray lpos_lint, t_object *obj);

float				get_specular_contrib(t_intersect_data *intersect_data,
						t_ray lpos_lint);

void				apply_fresnel(t_intersect_data *intersect_data,
						t_vec3f frescolor,
						t_vec3f *color);

float				get_idata_op(t_object *obj, t_vec3f rd,
							t_intersect_data *idata, float depth);
void				get_idata_obj(t_object *obj, t_vec3f rd,
							t_intersect_data *idata);
float				get_array_min_index(float *array, size_t size);
float				get_array_min(float *array, size_t size);
t_intersect_data	get_min_intersect_obj(t_intersect_data *array, size_t size);

void				gamma_correction(t_vec3f *color);

t_intersect_data	make_ray(t_intersect_data *intersect, t_vec3f dir,
							t_object *obj);

float				displacement_caller(t_e_disp disp, t_object *obj,
						t_vec3f p);

void				apply_displacements(t_object *obj, t_intersect_data *array,
							t_vec3f p);

#endif

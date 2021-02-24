/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/18 17:11:36 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSVL_H
# define BSVL_H

# include <stdint.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>

typedef int					t_vec2 __attribute__((ext_vector_type(2)));
typedef int					t_vec3 __attribute__((ext_vector_type(3)));
typedef int					t_vec4 __attribute__((ext_vector_type(4)));
typedef float				t_vec2f __attribute__((ext_vector_type(2)));
typedef float				t_vec3f __attribute__((ext_vector_type(3)));
typedef float				t_vec4f __attribute__((ext_vector_type(4)));
typedef double				t_vec2d __attribute__((ext_vector_type(2)));
typedef double				t_vec3d __attribute__((ext_vector_type(3)));
typedef double				t_vec4d __attribute__((ext_vector_type(4)));

struct		s_tri
{
	t_vec3f	a;
	t_vec3f	b;
	t_vec3f	c;
};

enum		e_axis
{
	X,
	Y,
	Z,
	__TOTAL_ROT
};

t_vec2f		vec2f_mul_mat2f(t_vec2f a, t_vec2f mat[static 2]);
t_vec3f		vec3f_mul_mat3(t_vec3f a, t_vec3f mat[static 3]);
void		get_roll_matrix(float theta, t_vec3f mat[static 3]);
void		get_pitch_matrix(float theta, t_vec3f mat[static 3]);
void		get_yaw_matrix(float theta, t_vec3f mat[static 3]);
void		get_rotation_matrix(float theta, enum e_axis axis,
	t_vec3f mat[static 3]);
void		apply_rotation_matrix(t_vec3f *vec_addr, t_vec3f mat[static 3]);
void		get_and_apply_rotation_matrix(float theta, enum e_axis axis,
	t_vec3f *vec_addr);
t_vec3f		vec3f_mul_mat4f(t_vec3f a, t_vec4f mat[static 4]);
void		get_vec3_identity_matrix(t_vec3f mat[static 3]);
t_vec4f		vec4f_mul_mat4f(t_vec4f a, t_vec4f mat[static 4]);
void		get_arbitrary_rot_mat(t_vec3f axis, float angle,
	t_vec4f mat[static 4]);
void		get_view_matrix(t_vec3f eye, t_vec3f center, t_vec3f up,
	t_vec4f mat[static 4]);
void		get_translation_matrix(t_vec3f translation_vector,
	t_vec4f mat[static 4]);
void		get_and_apply_translation_matrix(t_vec3f *target_addr,
	t_vec3f translation_vector);
void		get_vec4_identity_matrix(t_vec4f mat[static 4]);
void		vec3f_copy(t_vec3f *dest, t_vec3f src);
void		vec3f_set(t_vec3f *dest, float x, float y, float z);
t_vec4f		vec4f_mul_vec(t_vec4f a, t_vec4f b);
t_vec3f		vec3f_add_vec(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_add_k(t_vec3f a, float k);
t_vec3f		vec3f_sub_vec(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_sub_k(t_vec3f a, float k);
t_vec3f		vec3f_div_vec(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_div_k(t_vec3f a, float k);
t_vec3f		vec3f_mul_vec(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_mul_k(t_vec3f a, float k);
t_vec3f		vec3f_crossprod(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_normalize(t_vec3f a);
t_vec3f		vec3f_apply_fn_int(t_vec3f a, int(*fn)(int k));
t_vec3f		vec3f_apply_fn_float(t_vec3f a, float(*fn)(float k));
t_vec3f		vec3f_max(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_min(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_mod_vec(t_vec3f a, t_vec3f b);
t_vec3f		vec3f_mod_k(t_vec3f a, float k);
bool		vec3f_cmp(t_vec3f a, t_vec3f b);
t_vec3f		vec3_lerp(t_vec3f a, t_vec3f b, float t);
t_vec3f		refract(t_vec3f i, t_vec3f n, float n1, float n2, float radical);
t_vec3f		reflect(t_vec3f i, t_vec3f n);
t_vec2f		vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f		vec2f_sub(t_vec2f a, t_vec2f b);
t_vec2f		vec2f_div_k(t_vec2f a, float k);
t_vec2f		vec2f_div_vec(t_vec2f a, t_vec2f b);
t_vec2f		vec2f_mul_vec(t_vec2f a, t_vec2f b);
t_vec2f		vec2f_mul_k(t_vec2f a, float k);
t_vec2f		vec2f_normalize(t_vec2f a);
t_vec2f		vec2f_apply_fn_float(t_vec2f a, float(*fn)(float k));
t_vec2f		vec2f_apply_fn_int(t_vec2f a, int(*fn)(float k));
float		vec3f_dotprod(t_vec3f a, t_vec3f b);
float		vec3f_dist_origin(t_vec3f a);
float		vec3f_dist_ab(t_vec3f a, t_vec3f b);
float		vec2f_dotprod(t_vec2f a, t_vec2f b);
float		vec2f_dist_origin(t_vec2f a);
float		vec2f_dist_ab(t_vec2f a, t_vec2f b);
float		min(float a, float b);
float		max(float a, float b);
float		sqr(float i);
float		clamp(float x, float upper, float lower);
float		lerp(float a, float b, float f);
float		deg_to_rad(double radians);

#endif

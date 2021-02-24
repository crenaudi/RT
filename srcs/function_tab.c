/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../includes/rt_sdf.h"
#define INTER t_intersect_data

void	sdf_arg_setup_caller(t_vec3f *rd, t_object *obj)
{
	static	void	(*sdf_setup_arr[__SDF_TOTAL])(t_vec3f *, t_object *) = {
		[SDF_SPHERE] = &setup_args_nosetup,
		[SDF_CUBE] = &setup_args_tr_rot,
		[SDF_CONE] = &setup_args_tr_rot,
		[SDF_TORUS] = &setup_args_tr_rot,
		[SDF_CAPSULE] = &setup_args_nosetup,
		[SDF_PLANE] = &setup_args_nosetup,
		[SDF_CYLINDER] = &setup_args_tr_rot,
		[SDF_OCTA] = &setup_args_tr_rot,
		[SDF_ELLI] = &setup_args_tr_rot,
		[SDF_CUSTOM] = &setup_args_nosetup};

	return (sdf_setup_arr[obj->type](rd, obj));
}

float	sdf_caller(t_e_sdf type, t_vec3f pos, t_object obj)
{
	static	float	(*sdf_fptr_array[__SDF_TOTAL])(t_vec3f, t_object) = {
	[SDF_SPHERE] = &sdf_sphere,
	[SDF_CUBE] = &sdf_box,
	[SDF_CONE] = &sdf_cone,
	[SDF_TORUS] = &sdf_torus,
	[SDF_CAPSULE] = &sdf_capsule,
	[SDF_PLANE] = &sdf_plane,
	[SDF_CYLINDER] = &sdf_cylinder,
	[SDF_OCTA] = &sdf_octahedron,
	[SDF_ELLI] = &sdf_ellipsoid,
	[SDF_CUSTOM] = &sdf_custom};

	return (sdf_fptr_array[type](pos, obj));
}

float	operation_caller(t_e_def op, float d1, float d2, float k)
{
	static float	(*ope[__DEFORMATION_TOTAL])(float, float, float) = {
	[DEF_UNI] = &op_uni,
	[DEF_SUB] = &op_sub,
	[DEF_INTER] = &op_inter,
	[DEF_S_UNI] = &op_s_uni,
	[DEF_S_SUB] = &op_sub,
	[DEF_S_INTER] = &op_s_inter};

	return (ope[op](d1, d2, k));
}

void	surface_caller(t_e_material surface_mat, t_surface_stuff surf)
{
	static void	(*tex[__MATERIAL_TOTAL])(t_vec3f *, t_object *, INTER *,
		SDL_Surface **) = {[MATERIAL_SOLID_COLOR] = &material_set_solid_color,
		[MATERIAL_POLKADOT] = &material_set_solid_color,
		[MATERIAL_STONE_0] = &material_set_solid_color,
		[MATERIAL_CHECKERS] = &material_set_solid_color,
		[MATERIAL_MIRROR_PURE] = &reflection,
		[MATERIAL_MIRROR_IMPURE] = &reflection,
		[MATERIAL_MIRROR_COLORED] = &reflection};

	tex[surface_mat](surf.color, surf.obj, surf.inter, surf.textures);
}

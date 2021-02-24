/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJECT_H
# define RT_OBJECT_H
# include "../BSVL/bsvl.h"
# include "../minilibsdl/include/ft_minilibsdl.h"

typedef enum		e_sdf {
	SDF_CAPSULE,
	SDF_CONE,
	SDF_CUBE,
	SDF_CUSTOM,
	SDF_CYLINDER,
	SDF_ELLI,
	NONE,
	SDF_OCTA,
	SDF_PLANE,
	SDF_SPHERE,
	SDF_TORUS,
	__SDF_TOTAL,
}					t_e_sdf;

typedef enum		e_def {
	DEF_INTER,
	DEFNONE,
	DEF_S_INTER,
	DEF_S_SUB,
	DEF_S_UNI,
	DEF_SUB,
	DEF_UNI,
	__DEFORMATION_TOTAL,
}					t_e_def;

typedef enum		e_disp
{
	DISP_BEND,
	DISP_NONE,
	DISP_PERLIN,
	DISP_SIN,
	DISP_TWIST,
	__DISP_TOTAL,
}					t_e_disp;

typedef enum		e_material {
	MATERIAL_CHECKERS,
	MATERIAL_MIRROR_COLORED,
	MATERIAL_MIRROR_IMPURE,
	MATERIAL_MIRROR_PURE,
	MATERIAL_NONE,
	MATERIAL_POLKADOT,
	MATERIAL_SOLID_COLOR,
	MATERIAL_STONE_0,
	MATERIAL_GLASS,
	__MATERIAL_TOTAL,
}					t_e_material;

typedef struct		s_ray {
	t_vec3f		origin;
	t_vec3f		direction;
}					t_ray;

typedef struct		s_cam{
	t_ray		posdata;
	float		fov;
	t_vec3f		focus;
}					t_cam;

typedef struct		s_lightpoint
{
	t_ray	light_data;
	char	*id;
}					t_lightpoint;

typedef	struct		s_lights{
	t_lightpoint		*lights;
	size_t				num;
}					t_lights;

typedef struct		s_intersect_data
{
	char			*id;
	int				bounce;
	t_e_sdf			type;
	t_e_material	material;
	float			dist;
	float			shininess;
	t_vec3f			intersect_pos;
	t_lights		*l;
	t_vec3f			normal;
	t_vec3f			origin;
	t_vec3f			dir;
	t_vec3f			color;

}					t_intersect_data;

typedef struct		s_def_data {
	float	k;
}					t_def_data;

struct				s_plane {
	t_vec3f orientation;
	float	h;
};

struct				s_ellipsoid {
	t_vec3f r;
};

struct				s_sphere {
	float rad;
};

struct				s_cube {
	t_vec3f b;
};

struct				s_octa {
	float s;
};

struct				s_cone {
	t_vec2f c;
	float	r;
	float	h;
};

struct				s_capsule {
	t_vec3f a;
	t_vec3f b;
	float	r;
};

struct				s_cylinder {
	t_vec3f a;
	t_vec3f b;
	float	r;
	float	heigth;
};

struct				s_torus {
	t_vec2f r;
};

union				u_data {
	struct s_plane		plane;
	struct s_ellipsoid	ellipsoid;
	struct s_sphere		sphere;
	struct s_cube		cube;
	struct s_octa		octa;
	struct s_cone		cone;
	struct s_capsule	capsule;
	struct s_cylinder	cylinder;
	struct s_torus		torus;
};

typedef struct		s_object
{
	t_e_sdf			type;
	t_e_def			deformation;
	t_e_disp		disp;
	t_e_material	material;
	t_vec3f			pos;
	t_vec3f			col;
	t_vec3f			rot_mat[3];
	float			disp_data[__DISP_TOTAL];
	float			shininess;
	char			*id;
	t_def_data		def_data;
	union u_data	data;
}					t_object;

typedef struct		s_surface_stuff
{
	t_vec3f				*color;
	t_object			*obj;
	t_intersect_data	*inter;
	SDL_Surface			**textures;
}					t_surface_stuff;

#endif

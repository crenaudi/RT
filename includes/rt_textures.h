/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/17 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEXTURES_H
# define RT_TEXTURES_H
# include "../minilibsdl/include/ft_minilibsdl.h"
# include "../BSVL/bsvl.h"

char		**return_texture_names(void);
SDL_Surface	*load_single_texture(char *filename);
void		destroy_all_loaded_textures(SDL_Surface **loaded_textures);
SDL_Surface	**load_textures(char **texture_names);
Uint32		get_texture_pixel_color(SDL_Surface *texture, int x_pos, int y_pos);
t_vec3f		get_rgb_from_uint32(uint32_t uint_vec3f);

#endif

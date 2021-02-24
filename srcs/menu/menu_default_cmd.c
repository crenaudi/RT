/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_dfltm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/07 19:17:22 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void	dfltm_change_attr(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[2];

	deflt[0] = "Nommez l element a modifier";
	deflt[1] = "Entrez les commandes a modifier";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	dfltm_focus(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[3];

	deflt[0] = "Change direction x";
	deflt[1] = "Change direction y";
	deflt[2] = "Change direction z";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	dfltm_fov(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	(void)step;
	writeonscreen(rdr, menu->ttf, "Enter new fov", pos);
}

void	dfltm_light(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[7];

	deflt[0] = "Nommez l element";
	deflt[1] = "Position x";
	deflt[2] = "Position y";
	deflt[3] = "Position z";
	deflt[4] = "Valeur d intensite rouge entre 0 et 255. Default : 255";
	deflt[5] = "Valeur d intensite vert entre 0 et 255. Default : 255";
	deflt[6] = "Valeur d intensite bleu entre 0 et 255. Default : 255";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	dfltm_cam(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];

	deflt[0] = "Nommez la camera";
	deflt[1] = "Position x";
	deflt[2] = "Position y";
	deflt[3] = "Position z";
	writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

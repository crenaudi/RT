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

void	sphere_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[2];
	int		max;

	max = 2;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Radius de la sphere (Default = attr{ r : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	cube_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];
	int		max;

	max = 4;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Valeur en x (Default = attr{ x : 1 })";
	deflt[2] = "Valeur en y (Default = attr{ y : 1 })";
	deflt[3] = "Valeur en z (Default = attr{ z : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	octa_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[2];
	int		max;

	max = 2;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Circonference de l octa (Default = attr{ s : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	plane_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];
	int		max;

	max = 4;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Valeur en x (Default = attr{ x : 1 })";
	deflt[2] = "Valeur en y (Default = attr{ y : 1 })";
	deflt[3] = "Valeur en z (Default = attr{ z : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	torus_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[2];
	int		max;

	max = 2;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Circonference de torus (Default = attr{ s : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

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

void	elli_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[4];
	int		max;

	max = 4;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Circonference x (Default = attr{ x : 1 })";
	deflt[2] = "Circonference y (Default = attr{ y : 1 })";
	deflt[3] = "Circonference z (Default = attr{ z : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	capsule_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[7];
	int		max;

	max = 7;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Valeur en x1 (Default = attr{ x1 : 1 })";
	deflt[2] = "Valeur en y1 (Default = attr{ y1 : 1 })";
	deflt[3] = "Valeur en z1 (Default = attr{ z1 : 1 })";
	deflt[4] = "Valeur en x2 (Default = attr{ x2 : 1 })";
	deflt[5] = "Valeur en y2 (Default = attr{ y2 : 1 })";
	deflt[6] = "Valeur en z2 (Default = attr{ z2 : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	cylindre_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[7];
	int		max;

	max = 7;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Valeur en x1 (Default = attr{ x1 : 1 })";
	deflt[2] = "Valeur en y1 (Default = attr{ y1 : 2 })";
	deflt[3] = "Valeur en z1 (Default = attr{ z1 : 2 })";
	deflt[4] = "Valeur en x2 (Default = attr{ x2 : 3 })";
	deflt[5] = "Valeur en y2 (Default = attr{ y2 : 3 })";
	deflt[6] = "Valeur en z2 (Default = attr{ z2 : 3 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void	cone_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[3];
	int		max;

	max = 3;
	deflt[0] = "Nommez le nouvel objet";
	deflt[1] = "Circonference du cone (Default = attr{ r : 1 })";
	deflt[2] = "Hauteur su commet du cone (Default = attr{ h : 1 })";
	if (step >= max)
		commom_dfltm(rdr, menu, pos, step - max);
	else
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

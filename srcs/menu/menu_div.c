/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:15:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rt_menu.h"

void		commom_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[8];

	deflt[0] = "Position x (Default = pos{ x : 0 })";
	deflt[1] = "Position y (Default = pos{ y : 1 })";
	deflt[2] = "Position z (Default = pos{ z : 0 })";
	deflt[3] = "Definissez une deformation.";
	deflt[4] = "Definissez une matiere.";
	deflt[5] = "Valeur rouge comprise entre 0 - 255 (Default = col{ r : 255 })";
	deflt[6] = "Valeur verte comprise entre 0 - 255 (Default = col{ g : 255 })";
	deflt[7] = "Valeur bleu comprise entre 0 e- 255 (Default = col{ b : 255 })";
	if (step >= 0 && step < 8)
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void		dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos, int step)
{
	char	*deflt[2];

	deflt[0] = "Nommer l element a modifier";
	deflt[1] = "Nommer le second element.";
	if (step >= 0 && step < 2)
		writeonscreen(rdr, menu->ttf, deflt[step], pos);
}

void		find_dfltm_create(SDL_Renderer *renderer, t_menu *menu,
	t_vec2 mddldiv)
{
	t_fptr	func[__SDF_TOTAL];

	func[NONE] = &dfltm;
	func[SDF_CUSTOM] = &dfltm;
	func[SDF_CAPSULE] = &capsule_dfltm;
	func[SDF_CONE] = &cone_dfltm;
	func[SDF_CUBE] = &cube_dfltm;
	func[SDF_CYLINDER] = &cylindre_dfltm;
	func[SDF_ELLI] = &elli_dfltm;
	func[SDF_OCTA] = &octa_dfltm;
	func[SDF_PLANE] = &plane_dfltm;
	func[SDF_SPHERE] = &sphere_dfltm;
	func[SDF_TORUS] = &torus_dfltm;
	if (menu->ncmd_create >= 0 && menu->ncmd_create < __SDF_TOTAL)
		func[menu->ncmd_create](renderer, menu, mddldiv, menu->iinput->step);
}

void		find_dfltm(SDL_Renderer *renderer, t_menu *menu, t_vec2 pos)
{
	t_fptr	func[BUILTIN_TOTAL];

	func[BUILTIN_CHANGE_ATTR] = &dfltm_change_attr;
	func[BUILTIN_CHANGE_FOCUS] = &dfltm_focus;
	func[BUILTIN_CHANGE_FOV] = &dfltm_fov;
	func[BUILTIN_CHANGE_ID] = &dfltm;
	func[BUILTIN_CHANGE_ORDER] = &dfltm;
	func[BUILTIN_CREATE_LIGHT] = &dfltm_light;
	func[BUILTIN_DELETE_LIGHT] = &dfltm;
	func[BUILTIN_DELETE_OBJECT] = &dfltm;
	func[BUILTIN_FOCUS_OBJ] = &dfltm;
	func[BUILTIN_MOVE_CAM] = &dfltm_cam;
	func[BUILTIN_PRINT_CAM] = &dfltm;
	func[BUILTIN_PRINT_LIGHT] = &dfltm;
	func[BUILTIN_ROTATE] = &dfltm_rotate;
	func[BUILTIN_TRANSLATE] = &dfltm_translate;
	if (menu->ncmd == BUILTIN_LOAD_SCENE)
		writeonscreen(renderer, menu->ttf, "Indiquer la scene a charger", pos);
	else if (menu->ncmd == BUILTIN_DUMP_BMP)
		writeonscreen(renderer, menu->ttf,
			"Nommer votre image. Vous retrouverez celle-ci dans ./BMP/", pos);
	else if (menu->ncmd == BUILTIN_CREATE)
		find_dfltm_create(renderer, menu, pos);
	else
		func[menu->ncmd](renderer, menu, pos, menu->iinput->step);
}

bool		fill_div(SDL_Renderer *renderer, t_menu *menu, int utils[3], char c)
{
	t_vec2		posdiv;
	t_vec2		postxt;

	posdiv = (t_vec2){(SCREEN_W - menu->txs[DIV]->size.x) / 2, SCREEN_H - 200};
	postxt = (t_vec2){posdiv.x + 20, posdiv.y + 20};
	if (show_input(menu, utils))
	{
		put_tx(menu, menu->txs[DIV], 0, posdiv);
		apply_surface_renderer(renderer, menu->screen);
		if (c == 'B')
			writeonscreen(renderer, menu->ttf,
				"Nomez votre fichier bmp. Il sera cree dans ./BMP/ .", postxt);
		else if (menu->ncmd == BUILTIN_CREATE)
			find_dfltm_create(renderer, menu, postxt);
		else
			find_dfltm(renderer, menu, postxt);
	}
	else
		return (false);
	return (true);
}

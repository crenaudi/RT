/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibsdl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 05:13:59 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/07 12:10:49 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINILIBSDL_H
# define FT_MINILIBSDL_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include "../../BSVL/bsvl.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# define NO_FLAGS 0

typedef	struct s_sdl_objs	t_sdl_objs;
typedef	struct s_sdl_font	t_sdl_font;

struct				s_sdl_objs
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Renderer	*renderer;
};

enum				e_err_codes
{
	SDL_ERROR,
	MISSING_WIN_SPEC,
	__ERR_CODE_NUMBER
};

struct				s_sdl_font
{
	TTF_Font		*font;
	SDL_Color		color;
};

bool				ft_sdl_full_init(t_sdl_objs *sdl_objs,
	const int dimentions[2], const char *win_title, const bool rendererp);
bool				window_init(SDL_Window **window,
	const char *win_name, const size_t width, const size_t height);
bool				renderer_init(SDL_Window *window,
	SDL_Renderer **renderer, const int dimentions[2]);
bool				surface_init(SDL_Window *window,
	SDL_Surface **win_surface);
void				ft_sdl_cleanup(t_sdl_objs *sdl_objs, bool surfacep);
void				ft_sdl_generic_event_loop(t_sdl_objs *sdl_objs,
	void *private);
bool				ft_sdl_check_quit(SDL_Event event);
void				sdl_error_handler(const char *err_source,
	const char *err_function, int err_code);
void				strcat_w_endl(char *stackstr, const char *txt,
	const char *endl_char);
bool				sdl_ttf_init();
void				sdl_ttf_quit();
t_sdl_font			*sdl_ttf_font_open(const char *font, int size);
void				sdl_ttf_font_close(t_sdl_font *ttf);
int					*renderer_int_tab(SDL_Renderer *renderer, int w, int h);
bool				apply_surface_renderer(SDL_Renderer *renderer,
	SDL_Surface *screen);
void				writeonscreen(SDL_Renderer *renderer, t_sdl_font *ttf,
	char *str, t_vec2 pos);

#endif

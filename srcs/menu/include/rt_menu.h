/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:59 by crenaudi          #+#    #+#             */
/*   Updated: 2020/12/11 13:31:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MENU_H
# define RT_MENU_H

# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../../../minilibsdl/include/ft_minilibsdl.h"
# include "../../../altlib/altlib.h"
# include "../../../BSVL/bsvl.h"
# include "../../shell_shit/shell.h"
# include "../../../includes/rt.h"
# include "../../../includes/rt_object.h"
# include "../../../includes/rt_event_loop.h"
# include "../../../includes/rt_lights.h"
# include "../../../includes/rt_materials.h"
# include "../../../includes/rt_math_utils.h"
# include "../../../includes/rt_operations.h"
# include "../../../includes/rt_sdf.h"
# include "../../../includes/rt_threads.h"
# include "../../../includes/rt_event_loop.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# define BUFF_INPUT		20
# define BUFF_STORAGE	10000
# define ERROR			-1
# define SUCCESS		0
# define ERR_SIZE		1
# define ERR_MALLOC		2
# define ERR_SDL		3
# define MENU_ACTIVE	0x01
# define MENU_INFO		0x02
# define MENU_COMD		0x04
# define IPTB_ACTIVE	0x08
# define PROCESS_ACTIVE	0x10
# define PROCESS_VALIDE	0x20
# define IPTB_VALIDE	0x40
# define CHATBOX_ACTIVE	0x80

typedef unsigned char		t_u16;
typedef unsigned int		t_u32;
typedef struct s_bmp_info	t_bmp_info;
typedef struct s_bmp_header	t_bmp_header;
typedef struct s_menu		t_menu;
typedef struct s_texture	t_texture;
typedef struct s_input		t_input;
typedef struct s_chatbox	t_chatbox;
typedef union u_rtcolor		t_rtcolor;
typedef void				(*t_fptr)(SDL_Renderer *rdr, t_menu *menu,
	t_vec2 pos, int step);

struct				s_bmp_info
{
	int				size;
	int				convert;
	int				isize;
	int				ncpalette;
	int				ncimportant;
	char			*palette;
	int				maskred;
	int				maskgreen;
	int				maskblue;
	int				maskalfa;
};

struct				s_bmp_header
{
	int				fsize;
	int				width;
	int				height;
	int				nframes;
	uint16_t		formats;
	t_bmp_info		bmpinfo;
	char			*data;
};

union				u_rtcolor
{
	unsigned char	bgra[4];
	unsigned int	color;
};

struct				s_texture
{
	int				**frames;
	int				*data;
	int				nframes;
	int				hitbox[4];
	t_vec2			size;
	t_vec2			pos;
	t_vec2			pad;
};

struct				s_input
{
	char			storage[BUFF_STORAGE];
	char			str[BUFF_INPUT];
	int				ip;
	int				is;
	int				step;
	t_vec2			padding;
	int				hitbox_cancel[4];
	int				hitbox_valide[4];
};

struct				s_chatbox
{
	char			storage[BUFF_STORAGE];
	int				i;
	t_vec2			padding;
};

typedef enum		e_texture
{
	NAVBAR,
	BTN,
	INPUT,
	DIV,
	INFO,
	CHATBOX,
	TOTAL_TEXTURE,
}					t_e_texture;

struct				s_menu
{
	uint8_t			state;
	SDL_Surface		*screen;
	t_sdl_font		*ttf;
	t_texture		**txs;
	t_input			*iinput;
	t_chatbox		*ichatbox;
	int				ncmd;
	int				ncmd_create;
	int				*bg;
};

void				ft_putendl(char const *s);
size_t				my_strlen(const char *str);
char				*my_strcat(char *dest, const char *src);
int					my_strcmp(const char *s1, const char *s2);
void				*my_memset(void *s, int c, size_t n);
void				my_bzero(void *s, size_t n);
void				*my_memalloc(size_t size);
size_t				my_strlcat(char *dest, const char *src, size_t size);
char				*my_strncpy(char *dest, const char *str, size_t n);
char				*my_strcpy(char *dest, const char *src);
int					fd_check_dest(const char *path);
bool				fd_check_param(const char *src, char *ext);
int					fd_check_open(const char *file);
void				*readncharacter(int fd, int len);
void				generatebmpfromsdl(SDL_Window *win, SDL_Renderer *rdrr,
	const char *path, const char *name);
void				generatebmp(const char *path, const char *name, int *px,
	t_vec2 s);
int					bmpcolorconvert(t_bmp_header bmp, int x, int y);
unsigned int		countbymask(unsigned int mask);
unsigned int		component_mask(unsigned int color, unsigned int mask);
unsigned int		convertcolor(unsigned int color, unsigned int frontbitcount,
	unsigned int tobitcount);
int					*generateimage(t_bmp_header bmp);
t_bmp_info			generateinfo(void *data);
bool				generateheader(int fd, t_bmp_header *bmpheader,
		void *data);
t_texture			**init_texture_tab(void);
void				destroy_texture_tab(t_texture **tab);
t_texture			*init_tx(int x, int y, int nframes);
bool				init_data(t_texture *tx, t_bmp_header *bmphdr);
t_texture			*add_tx(const char *file, t_vec2 pos, t_vec2 hit,
	t_vec2 pad);
void				destroy_tx(t_texture *tx);
int					lerp_color(t_rtcolor s, t_rtcolor e, float t);
void				put_tx(t_menu *menu, t_texture *tx, int frame, t_vec2 pos);
void				debugerror(unsigned int err, char *line);
void				rt_menu_loop(t_rt_utils *utils, t_menu *menu);
bool				init_menu(t_menu *menu);
void				clear_menu(t_menu *menu);
void				update_menu_screen(SDL_Renderer *renderer, t_menu *menu);
void				close_menu(t_menu *menu);
int					key_press(t_menu *menu, bool *loop);
bool				menu_state(t_rt_utils *rt, t_menu *menu, int utils[3],
	bool loop);
bool				command(t_rt_utils	*rt, t_menu *menu, int utils[3]);
void				clear_hitbox(t_texture *tx);
void				init_hitbox(t_texture *tx, t_vec2 pos, t_vec2 size,
	t_vec2 pad);
bool				hit_hitbox(int hitbox[4], int x, int y);
bool				fill_div(SDL_Renderer *renderer, t_menu *menu,
	int utils[3], char c);
void				fill_div_btn(SDL_Renderer *renderer, t_menu *menu, char c);
t_vec2				columns_btn(t_vec2 origin, t_vec2 margin, int nb, int i);
int					tx_btn(t_menu *menu, int mutils[3], t_vec2 margin, int nb);
void				txt_btncmd(SDL_Renderer *renderer, t_sdl_font *ttf,
	t_vec2 origin);
void				txt_btnobj(SDL_Renderer *renderer, t_sdl_font *ttf,
	t_vec2 origin);
void				txt_btnmat(SDL_Renderer *renderer, t_sdl_font *ttf,
	t_vec2 origin);
void				txt_btnopt(SDL_Renderer *renderer, t_sdl_font *ttf,
	t_vec2 origin);
void				sphere_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				cube_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				octa_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				plane_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				torus_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				capsule_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				elli_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				cylindre_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				cone_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				commom_dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				find_dfltm(SDL_Renderer *renderer, t_menu *menu,
	t_vec2 mddldiv);
t_input				*init_input(t_texture *tx);
void				fill_input(t_input *input, int i, int process);
void				valide_onprocess_input(t_menu *menu, char *str);
void				clear_input(t_input *input);
void				destroy_input(t_input *input);
bool				show_input(t_menu *menu, int utils[3]);
void				find_process(t_input *input, int process);
void				find_create_process(t_input *input, int process);
char				*ret_opt(int select);
char				*ret_mat(int select);
void				process(SDL_Renderer *renderer, t_menu *menu,
	int utils[3]);
void				copy_storage(t_input *input, char *src);
void				copy_twostorage(t_input *input, char *str1, char *str2);
void				key_press_letter(SDL_Event event, t_menu *menu);
void				key_press_num(SDL_Event event, t_menu *menu);
int					key_press_menu(t_menu *menu, int utils[3]);
t_chatbox			*init_chatbox(void);
void				clear_chatbox(t_chatbox *cb);
void				destroy_chatbox(t_chatbox *cb);
void				rt_chatbox_loop(t_rt_utils *rt, t_menu *menu);
void				key_press_chatbox(SDL_Event	e, t_chatbox *cb);
void				gestion_chatbox(SDL_Renderer *renderer, t_menu *menu,
	t_chatbox *cb);
bool				rt_shell(t_rt_utils *rt, t_menu *menu, char *storage);
bool				rt_shell_inputbox(t_rt_utils *rt, t_menu *menu);
bool				rt_shell_chatbox(t_rt_utils *rt, t_menu *menu);
void				render_chatbox(t_rt_utils *rt, t_menu *menu, bool loop);
void				dfltm_rotate(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm_translate(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm_change_attr(SDL_Renderer *rdr, t_menu *menu,
	t_vec2 pos, int step);
void				dfltm_focus(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm_fov(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm_light(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);
void				dfltm_cam(SDL_Renderer *rdr, t_menu *menu, t_vec2 pos,
	int step);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:44:13 by brjorgen          #+#    #+#              #
#    Updated: 2021/01/05 08:27:39 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
TUR			=	\033[36m
WHITE		=	\033[37m
END			=	\033[0m

UP 		=	\033[A
CUT 	=	\033[K

# project
NAME	=	RT

# compiler
CC		=	clang
CFLAGS 	=	-Wall -Werror -Wextra -O3 -g

# directories
SRC_PATH	=	./srcs/
OBJ_PATH	=	./objs/
SDL_PATH 	= ./usr/include/SDL2

# sources
SRC =	camera_move.c								\
		sdf_arg_setup_functions.c					\
		clear_rt_utils.c							\
		deformation_utils.c							\
		deformations.c								\
		function_tab.c								\
		get_contrib.c								\
		get_data.c									\
		get_pixel_data.c							\
		main.c										\
		march_ray.c									\
		metalic_surface_functions.c					\
		multithreading_utils.c						\
		rt_applied_materials.c						\
		rt_applied_textures.c						\
		rt_apply_displacements.c					\
		rt_displacement.c							\
		rt_event_loop.c								\
		rt_light.c									\
		rt_textures.c								\
		rt_textures_utils.c							\
		sdfunctions.c								\
		sdfunctions_utils.c							\
		menu/bmp_bitwase.c							\
		menu/bmp_parse.c							\
		menu/bmp_generate.c							\
		menu/fd_gestion.c							\
		menu/texture_init.c							\
		menu/texture_destroy.c						\
		menu/texture_print.c						\
		menu/libft.c								\
		menu/libft_suite.c							\
		menu/menu.c									\
		menu/menu_init.c							\
		menu/menu_chatbox.c							\
		menu/menu_destroy.c							\
		menu/menu_btn.c								\
		menu/menu_div.c								\
		menu/menu_event.c							\
		menu/menu_inputbox.c						\
		menu/menu_input.c							\
		menu/menu_key.c								\
		menu/menu_key_where.c						\
		menu/menu_process.c							\
		menu/menu_process_info.c					\
		menu/menu_default_cmd.c						\
		menu/menu_default_cmd_suite.c				\
		menu/menu_dfltm_create.c					\
		menu/menu_dfltm_create1.c					\
		menu/menu_shell.c							\
		menu/menu_hitbox.c							\
		shell_shit/lang/get_next_line.c				\
		shell_shit/lang/parse_source.c				\
		shell_shit/builtin_camera.c					\
		shell_shit/builtin_functions.c				\
		shell_shit/builtin_functions_print.c		\
		shell_shit/builtin_functions_change.c		\
		shell_shit/builtin_functions_objet.c		\
		shell_shit/builtin_change_attr.c			\
		shell_shit/builtin_light.c					\
		shell_shit/builtin_clear.c					\
		shell_shit/shell_utils.c					\
		shell_shit/light_utils_0.c					\
		shell_shit/light_init_utils.c				\
		shell_shit/light_init_utils_1.c				\
		shell_shit/mappable_functions.c				\
		shell_shit/init_disp.c						\
		shell_shit/object_init_functions.c			\
		shell_shit/object_init.c					\
		shell_shit/object_init_suite.c				\
		shell_shit/parse_input.c					\
		shell_shit/shell_change_attr.c				\
		shell_shit/shell_change_attr_suite.c		\
		shell_shit/shell_print_attr_suite.c			\
		shell_shit/message.c						\
		shell_shit/shell_print_attr.c				\
		shell_shit/shell_set_default.c				\
		shell_shit/shell_set_default_suite.c		\
		shell_shit/translate_rotate.c				\
		shell_shit/change_attr_utils.c				\
		shell_shit/set_default_utils.c				\
		shell_shit/parse_input_utils.c				\
		shell_shit/object_init_utils.c				\
		shell_shit/half_tab.c						\
		shell_shit/shell.c

# libraries set-up
INC					=	-I ./includes/ -I ./altlib/ -I ./BSVL/ -I ./minilibsdl/include
INC					+= -I ./srcs/menu/include -I ./srcs/shell_shit -I ./srcs/shell_shit/lang
LIB 				= ./altlib/altlib.a ./BSVL/BSVL.a ./minilibsdl/minilibsdl.a
LIB_DIR 		= ./libraries/lib/

export			LD_LIBRARY_PATH=/local/lib
SDL_FLAGS 	= `./libraries/SDL2-2.0.8/sdl2-config --cflags`
SDL 	= -lSDL2_ttf -lfreetype `./libraries/SDL2-2.0.8/sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_ttf -lfreetype
OBJS	=	$(SRC:.c=.o)
OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJS))

all: 		 lib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@echo "${TUR}compiling [$@] ...${END}"
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC) -I $(SDL_PATH)
		@printf "$(UP)$(CUT)"
$(OBJ_PATH):
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@mkdir $(OBJ_PATH)menu
		@mkdir $(OBJ_PATH)shell_shit
		@mkdir $(OBJ_PATH)shell_shit/lang

$(LIB):
		@echo "${GREEN}[DIRECTORIES CREATED]${END}"
		@make -C altlib
		@make -C BSVL
		@make -C minilibsdl
		@echo "${GREEN}[LIBRARY COMPILED]${END}"

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
		@$(CC) $(CFLAGS) $(SDL_FLAGS) $(OBJ_EXEC) -lm -lpthread -o $@ $(SDL) $(LIB) $(INC)
		@echo "${GREEN}[$@ COMPILED]${END}"

lib: sdl image

sdl:
		@if [ -d "./libraries/SDL2-2.0.8" ]; then \
			echo "${BLUE}SDL2 already installed ...${END}\r"; \
		else \
			echo "${BLUE}Installing SDL2 ...${END}\c" && \
			sudo apt-get install libsdl2-dev && \
			mkdir -p libraries && \
			curl -s https://www.libsdl.org/release/SDL2-2.0.8.tar.gz -o libraries/SDL2-2.0.8.tar.gz >> ./rt_log 2>&1 && \
			tar -xf libraries/SDL2-2.0.8.tar.gz -C libraries >> ./rt_log 2>&1 && \
			cd libraries/SDL2-2.0.8 && \
			./configure && \
			make && \
			sudo make install && \
			echo "${YELLOW}DONE${END}"; \
		fi

image: ttf
		@if [ -d "./libraries/SDL2_image-2.0.5/" ]; then \
			echo "${BLUE}SDL2 Image already installed ...${END}\r"; \
		else \
			echo "${BLUE}Installing SDL2_image ...${END}\c" && \
			mkdir -p libraries && \
			curl -s https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.tar.gz -o libraries/SDL2_image-2.0.5.tar.gz && \
			tar -xf libraries/SDL2_image-2.0.5.tar.gz -C libraries >> ./rt_log 2>&1 && \
			cd libraries/SDL2_image-2.0.5 && \
			./configure && \
			make all && \
			sudo make install && \
			echo "${YELLOW}DONE${END}"; \
		fi

ttf: freetype
		@if [ -d "./libraries/SDL2_ttf-2.0.15/" ]; then \
			echo "${BLUE}SDL2 Ttf already installed ...${END}\r"; \
		else \
			echo "${BLUE}Installing SDL2_ttf ...${END}\c" && \
			mkdir -p libraries && \
			curl -s https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz -o libraries/SDL2_ttf-2.0.15.tar.gz >>./rt_log 2>&1 && \
			tar -xf ./libraries/SDL2_ttf-2.0.15.tar.gz -C libraries >>./rt_log 2>&1 && \
			cd libraries/SDL2_ttf-2.0.15 && \
			./configure && \
			make all && \
			sudo make install && \
			echo "${YELLOW}DONE${END}"; \
		fi

freetype:
		@if [ -d "./libraries/freetype-2.4.11/" ]; then \
			echo "${BLUE}Freetype2 already installed ...${END}\r"; \
		else \
			echo "${BLUE}Installing freetype2 ...${END}\c" && \
			mkdir -p libraries && \
			curl -s https://download.savannah.gnu.org/releases/freetype/freetype-2.4.11.tar.gz -Lo libraries/freetype-2.4.11.tar.gz >>./rt_log 2>&1 && \
			tar -xf ./libraries/freetype-2.4.11.tar.gz -C libraries >>./rt_log 2>&1 && \
			cd libraries/freetype-2.4.11 && \
			./configure && \
			make all && \
			sudo make install && \
			echo "${YELLOW}DONE${END}"; \
		fi

clean:
			@make -C altlib clean
			@make -C BSVL clean
			@make -C minilibsdl clean
			@rm -rf $(OBJ_PATH)
			@echo "${RED}Omegart: deleting object files${END}"

fclean:		clean
			@make -C altlib fclean
			@make -C BSVL fclean
			@make -C minilibsdl fclean
			@rm -f $(NAME)
			@echo "${RED}Omegart: deleting executable file${END}"

re:			fclean all

fcleansdl:
			@rm -rf rt_log
			@rm -rf libraries
			@sudo apt-get remove libsdl2-dev
			@echo "${RED}[SDL files deleted]${END}"

resdl: fcleansdl all

.PHONY:		all clean fclean re sdl image resdl fcleansdl lib

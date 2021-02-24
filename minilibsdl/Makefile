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
YELLOW	=	\033[33m
BLUE		=	\033[34m
PURPLE	=	\033[35m
TUR			=	\033[36m
WHITE		=	\033[37m
END			=	\033[0m

CC     =	clang

CFLAGS =	-Wall -Werror -Wextra -g -I ./include

NAME   =	minilibsdl.a

SRCS   =	ft_sdl_error_handler.c 		\
			ft_sdl_renderer_init.c 		\
			ft_sdl_window_init.c		\
			ft_sdl_surface_init.c  		\
			ft_sdl_cleanup.c		\
			ft_sdl_full_init.c		\
			ft_sdl_generic_event_loop.c	\
			ft_sdl_ttf_init.c	\
			ft_sdl_ttf_quit.c	\
			ft_sdl_write_renderer.c	\
			ft_sdl_check_quit.c

ODIR	=	./objs/
SDIR 	= 	./src/

HEADER  =	./include/ft_minilibsdl.h

ABSOLUTE_DIR = $(shell pwd)

SRC		=	$(addprefix $(SDIR),$(SRCS))
OBJ     =	$(SRC:$(SDIR)%.c=$(ODIR)%.o)

OBJ_PATH	=	objs

$(ODIR)%.o : $(SDIR)%.c $(HEADER)
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@echo "${YELLOW}    Compiling :${END} $@"
		@$(CC) $(CFLAGS) $(SDL_FLAGS) -o $@ -c $< $(SDL)

all 	:	$(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "${BLUE}Minilibsdl: compiled static library.${END}"

clean	:
		@rm -rf $(OBJ)
		@echo "${RED}Minilibsdl: removed object files.${END}"

fclean  : 	clean
		@rm -rf $(NAME)
		@echo "${RED}Minilibsdl: removed static library.${END}"

re 	: 	fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:44:13 by brjorgen          #+#    #+#              #
#    Updated: 2020/11/25 08:27:39 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
TUR		=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m

CC	=	clang

INFILE  =	math_utils.c	\
			math_utils1.c	\
			vec2.c			\
			vec2suite.c		\
			vec2suite0.c	\
			vec3.c			\
			vec3matrix.c	\
			vec3suite.c		\
			vec3suite0.c	\
			vec3suite1.c	\
			vec3suite2.c	\
			vec4.c			\
			lerp.c			\
			reflect.c		\
			vec4matrix.c

OUTFILE = 	BSVL.a

FLAGS   = 	-Wall -Werror -Wextra -g3

OBJ     = 	$(INFILE:%.c=%.o)

HEADER  = 	bsvl.h

%.o: %.c	 $(HEADER)
		@echo "${YELLOW}    Compiling :${END} $@"
	 	@$(CC) -o $@ -c $< $(CFLAGS)

all :    	 $(OBJ)
	 	 @ar rc $(OUTFILE) $(OBJ)
	 	 @ranlib $(OUTFILE)
	 	 @echo "${BLUE}BSVL: compiled static library.${END}"

clean:
		@rm -f $(OBJ)
		@echo "${RED}BSVL: Removed object files.${END}"

fclean: 	clean
		@rm -f $(OUTFILE)
		@echo "${RED}BSVL: Removed static library.${END}"

re	:	fclean all

rebuild :	clean build

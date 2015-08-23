#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:28:17 by nidzik            #+#    #+#              #
#    Updated: 2015/08/22 19:37:23 by nidzik           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

# LIBFT
LFTPATH = libft/
LFTIPATH = -I $(LFTPATH)
LFT = -L $(LFTPATH) -lft


OBJPATH = obj
SRCPATH = .
INCLUDE = -I ./

# MLX
CC = gcc
#GRAPHLIB = -L/usr/X11/lib -lmlx -lXext -lX11 -framework openGl -framework AppKit
GRAPHLIB = -lmlx -framework openGl -framework AppKit


LIBS = $(LFT) $(GRAPHLIB)
INCLUDES = $(INCLUDE) $(LFTIPATH) $(GRAPHINC)


BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror -O2 -g


LFTCALL = all
LFTRE = re


SRCSFILES = draw.c \
			event.c \
			init.c \
			main.c \
			mlx_init.c \
			more_event.c \
			textures.c \
			next_draw.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

all: l $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(Y)[COMPILING WOLF] $(G) $(CC) -o $@ $(CFLAGS) objs.o $(LIBS) $(E)"
	@$(CC) -o $@ $(CFLAGS) -g $(OBJECTS) $(INCLUDES) $(LIBS)
	@echo "$(Y)[COMPILING WOLF DONE]$(E)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

l:
	@echo "$(Y)[COMPILING LIBFT] $(G) make -C $(LFTPATH) $(LFTCALL) $(E)"
	@make -C $(LFTPATH) $(LFTCALL)
	@echo "$(Y)[COMPILING LIBFT DONE]$(E)"

re: fclean all

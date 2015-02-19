# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/02/18 15:51:49 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fractol

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER =		fdf.h get_next_line.h math_structs.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR)

MLX_LIBS =		-L/usr/X11/lib -lmlx -lXext -lX11

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME) $(MLX_LIBS)

FT_LIB_NAME =	ft

FT_LIB =		lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				get_fractal.o \
				fractal_img.o \
				gen_fractal_color.o \
				fdf_error.o \
				check_malloc.o \
				gen_mlx_window.o \
				gen_default_camera.o \
				new_fdf_img.o \
				fdf_expose_hook.o \
				fdf_key_hook.o \
				fdf_mouse_hook.o \
				fdf_loop_hook.o \
				fdf_clear_img.o \
				fractal_hook.o

COMPILED =		$(SRC_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(SRC_COMPILED)
	$(CC) -o $(NAME) $(FLAGS) $(LIBRARIES) $(HEADER_DIR) $(SRC_COMPILED)

$(SRC_COMPILED): %.o: $(SRC_DIR)%.c
	$(CC) -c $(FLAGS) $(HEADER_DIR) $< -o $@

$(FT_LIB):
	@make -C $(FT_LIB_DIR);

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all

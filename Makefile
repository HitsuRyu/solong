CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	so_long
LIBFTPATH =	./libft
LIBFT	=	libft.a
MLXPATH	=	minilibx-linux
MLX		=	libmlx.a
SRC		=	src/initialization/draw_map.c \
			src/initialization/initialization.c \
			src/main/so_long.c \
			src/main/movement_manager.c \
			src/map_parser/map_parser.c \
			src/map_parser/config_checker.c
OBJ		=	$(SRC:.c=.o)
INCLUDES = ./includes/
HEADER	=	$(INCLUDES)mlx.h $(INCLUDES)libft.h $(INCLUDES)so_long.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDES) $< -c -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFTPATH)
	cp $(LIBFTPATH)/$(LIBFT) .
	$(MAKE) -C $(MLXPATH)
	cp $(MLXPATH)/$(MLX) .
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -L. -lmlx -lXext -lX11 -o $@

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	$(MAKE) -C $(MLXPATH) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	$(MAKE) -C $(MLXPATH) clean
	rm -f libmlx.dylib
	rm -f $(LIBFT)
	rm -f $(NAME)

re: clean fclean all
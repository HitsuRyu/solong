NAME	=	so_long
LIBFTPATH =	./src/libft
SRC		=	src/initialization/draw_map.c \
			src/initialization/initialization.c \
			src/main/so_long.c \
			src/main/movement_manager.c \
			src/map_parser/map_parser.c \
			src/map_parser/config_checker.c
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HEADER_DIR = ./includes
			
all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFTPATH)
	$(CC) $(OBJ) -L./src -lmlx -framework OpenGL -framework AppKit -L$(LIBFTPATH) -lft -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -c -I$(HEADER_DIR) -o $@

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re: clean fclean all
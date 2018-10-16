NAME =	fdf

FLG =	-Wall -Wextra -Werror

MLX = -lmlx -lXext -lX11 -L minilibx/ -I minilinx/

SRC =	fdf.c ft_read.c map.c fr_put_lines.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./libft/
	gcc $(FLG) $(OBJ) $(MLX) -L ./libft/ -lft -o $(NAME) -lm

%.o: %.c
	gcc -c $(FLG) -o $@ $<

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ)

fclean:	clean
	make -C ./libft fclean

re:	fclean all
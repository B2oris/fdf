NAME := fdf

SRC =  srcs/parser.c srcs/parser2.c srcs/parser3.c srcs/key.c srcs/key2.c srcs/tracing.c srcs/tracing2.c srcs/tracing3.c srcs/main.c

OBJ = $(SRC:.c=.o)

FLAGS := -Wall -Werror -Wextra 

INCLUDES := -I./libft/

MLX := -lmlx -framework OpenGL -framework AppKit

LIBS := -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C mlx/
	make -C libft/
	gcc $(INCLUDES) $(FLAGS) -g $(LIBS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c ./includes/fdf.h
	gcc -g $(INCLUDES) -o $@ -c $< 

clean :
	make -C libft/ clean
	make -C mlx/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all


.PHONY = $(NAME) all clean fclean re
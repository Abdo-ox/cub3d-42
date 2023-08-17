NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCPA = src/parsing
SRCRA = src/raycasting
LIBFT = src/libft/libft.a
LIB =  -lmlx -framework OpenGL -framework AppKit -O3
SRCP = $(wildcard $(SRCPA)/*.c)
SRCR = $(wildcard $(SRCRA)/*.c)

OBJ = $(SRCP:.c=.o) $(SRCR:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
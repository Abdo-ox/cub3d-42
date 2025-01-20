NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCPA = src/parsing
SRCRA = src/raycasting
LIBS = src/libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm 
SRCP = $(wildcard $(SRCPA)/*.c)
SRCR = $(wildcard $(SRCRA)/*.c)
OBJ = $(SRCP:.c=.o) $(SRCR:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBS)  -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
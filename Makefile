# >-+-+ directories dirs. -+-+<
NAME = fdf
SRC_DIR = ./src
LIBFT_DIR = ./libs/libft
LIBMLXDIR = ./libs/MLX42

# >-+-+ includes dirs. -+-+<

INCLUDES = -I ./includes \
			-I ./libs/libft/includes \
			-I ./libs/MLX42/include/MLX42

# >-+-+ compiler and flags -+-+<
CC = gcc
CFLAGS = -Wall -Wextra  -Werror
AR = ar rcs
RM = rm -rf

LIBFT = $(LIBFT_DIR)/libft.a \
		$(LIBMLXDIR)/build/libmlx42.a 

# >-+-+ srcs fdf -+-+<
SRC		= $(SRC_DIR)/fdf.c \

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ)
			cp 	$(LIBFT) $(NAME)
	 		$(AR) $(NAME) $(LIBFT) $(OBJ)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		make -C $(LIBFT_DIR) fclean
		$(RM) $(OBJ)

fclean: clean
		make -C $(LIBFT_DIR) fclean
		$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
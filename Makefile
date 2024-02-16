NAME := fdf
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
AR := ar rcs
RM := rm -rf

GREEN = \033[32m
BLUE = \033[0;34m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
FCOLOR = \033[0m

LIBMLX := ./libs/MLX42
LIBFT_DIR := ./libs/libft

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR)/includes

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_DIR)/libft.a
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

# Variável de controle para verificar se o Makefile já foi executado
FIRST_MAKE_EXECUTED := false

all: libmlx libft $(NAME)
ifeq ($(FIRST_MAKE_EXECUTED),false)
	@printf "$(GREEN)All files compiled successfully\n"
	@printf "Compiled with: $(BLUE)./$(NAME)\n"
	@printf "Instructions: $(WHITE)Run $(YELLOW)'./$(NAME)' $(WHITE)with map path\n"
	@printf "Thank you for using $(NAME) 👽\n"
endif

# Marca a execução do Makefile
	@$(eval FIRST_MAKE_EXECUTED=true)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1

libft:
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re libmlx libft

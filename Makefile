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
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst ./src/%.c,obj/%.o,$(SRCS))

# Variável de controle para verificar se o Makefile já foi executado
FIRST_MAKE := obj/.first_make

# Verifica se é a primeira execução do Makefile
ifneq ($(shell test -e $(FIRST_MAKE) && echo yes),yes)
FIRST_MAKE_EXECUTED := false
else
FIRST_MAKE_EXECUTED := true
endif

all: libmlx libft $(NAME)
ifeq ($(FIRST_MAKE_EXECUTED),false)
	@printf "$(GREEN)All files compiled successfully\n"
	@printf "Compiled with: $(BLUE)./$(NAME)\n"
	@printf "Instructions: $(WHITE)Run $(YELLOW)'./$(NAME)' $(WHITE)with map path\n"
	@printf "Thank you for using $(NAME)\n"
endif
	@touch $(FIRST_MAKE)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1

libft:
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

obj/%.o: src/%.c | obj
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

obj:
	@mkdir -p obj

clean:
	@$(RM) -rf obj
	@$(MAKE) -C $(LIBMLX)/build clean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(FIRST_MAKE) # Remove o arquivo de marcação
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re libmlx libft

# .*-*..*-*. DIRECTORIES .*-*..*-*..*-*.
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = includes

# .*-*..*-*. COLORS .*-*..*-*.

GREEN = \033[32m
BLUE = \033[0;34m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
FCOLOR = \033[0m

# .*-*..*-*..*-*. LIST ARCHIVES IN MODULES .*-*..*-*..*-*.

FT_PRINTF_SRCS := 	ft_printf.c \
					ft_putchar.c \
					ft_puthex_def.c \
					ft_puthex_pointer.c \
					ft_putpointer.c \
					ft_uputnbr.c \
					ft_putnbr.c \
					ft_putstr.c \
					ft_utoa.c 

GET_NEXT_LINE_SRCS := 	get_next_line_bonus.c \
						get_next_line_utils_bonus.c \

LIBFT_SRCS := 	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \

# .*-*..*-*..*-*..*-*..*-*..*-*..*-*..*-*..*-*..*-*..*-*..*-*.

# .*-*..*-*. LIST OBJECT GENERATED FOR EACH MODULES .*-*..*-*.

FT_PRINTF_OBJS = $(patsubst %.c, $(OBJ_DIR)/ft_printf/%.o, $(notdir $(FT_PRINTF_SRCS)))
GET_NEXT_LINE_OBJS = $(patsubst %.c, $(OBJ_DIR)/get_next_line/%.o, $(notdir $(GET_NEXT_LINE_SRCS)))
LIBFT_OBJS = $(patsubst %.c, $(OBJ_DIR)/libft/%.o, $(notdir $(LIBFT_SRCS)))

# .*-*..*-*. LIB NAME .*-*..*-*.
NAME = libft.a

# .*-*..*-*. FLAGS COMPILERS .*-*..*-*.
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

# .*-*..*-*. RULES SILENT .*-*..*-*.
.SILENT:

# .*-*..*-*. RULES DEFAULT .*-*..*-*.
all: $(NAME)
	@printf "\n$(GREEN)Arquivo Útil:$(PURPLE)$(PURPLE) $(NAME)$(PURPLE)\n"

# .*-*..*-*. RULES COMPILATION EACH MODELS .*-*..*-*.
$(OBJ_DIR)/ft_printf/%.o: ft_printf/%.c | $(OBJ_DIR)/ft_printf
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW)Compilando:$(PURPLE) $< [$(GREEN)OK$(PURPLE)]\n"

$(OBJ_DIR)/get_next_line/%.o: get_next_line/%.c | $(OBJ_DIR)/get_next_line
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW)Compilando:$(PURPLE) $< [$(GREEN)OK$(PURPLE)]\n"

$(OBJ_DIR)/libft/%.o: libft/%.c | $(OBJ_DIR)/libft
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW)Compilando:$(PURPLE) $< [$(GREEN)OK$(PURPLE)]\n"

# .*-*..*-*. CREATIONS DIRECTIONS OBJECTS FOR EACH MODELS .*-*..*-*.
$(OBJ_DIR)/ft_printf:
	mkdir -p $@

$(OBJ_DIR)/get_next_line:
	mkdir -p $@

$(OBJ_DIR)/libft:
	mkdir -p $@

# .*-*..*-*. RULES EACH CREATION FOR LIB STATIC .*-*..*-*.
$(NAME): $(FT_PRINTF_OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_OBJS)
	ar rcs $@ $^

# .*-*..*-*. CLEAN OBJECTS .*-*..*-*.
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean

#.*-*..*-*. endif .*-*..*-*.
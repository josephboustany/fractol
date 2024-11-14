# Compiler settings
CC = gcc
CFLAGS = -Ofast -flto -march=native -funroll-loops -fno-plt -fstrict-aliasing -Wall -Wextra -Werror -fPIC -I./minilibx-linux -I./libft -I./ft_printf -g
LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm -L./libft -lft -L./ft_printf -lftprintf

# Project information
FRACTOL_PROJECT := "Fractol Project"
AUTHOR := "Joseph Boustany"
NAME = fractol

# Source files
SRCS = main.c \
       event_handlers.c \
       fractal_rendering.c \
       graphics_utils.c \
       initialize_rendering.c \
       input_handler.c \
       view_movements.c \
       zoom_utils.c

OBJS = $(SRCS:.c=.o)

# ANSI color codes
GREEN := \033[0;32m
RESET := \033[0m

# Title function for Fractol
define title
	@echo "=========================================================================================="
	@echo "$(GREEN)                  		$(FRACTOL_PROJECT)$(RESET)"
	@echo "$(GREEN)                                   $(AUTHOR)$(RESET)"
	@echo "=========================================================================================="
endef

# Message function for consistent formatting
define message
	@echo "=================================================="
	@echo "$(GREEN)  $(1)$(RESET)"
	@echo "=================================================="
endef

# Default target
all: minilibx libft ft_printf $(NAME)

# Compile MiniLibX
minilibx:
	$(MAKE) -C minilibx-linux

# Compile libft (already handles its own name output)
libft:
	$(MAKE) -C libft

# Compile ft_printf (already handles its own name output)
ft_printf:
	$(MAKE) -C ft_printf

# Main target: Compile Fractol and show title only here
$(NAME): $(OBJS)
	$(call title)
	$(call message,"Creating executable $(NAME)...")
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(call message,"Executable $(NAME) created successfully.")

# Clean up object files
clean:
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(OBJS)

# Full clean up
fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Declare targets that are not files
.PHONY: all clean fclean re minilibx libft ft_printf title

# Compiler and archiver settings
CC := cc
AR := ar rcs
CFLAGS := -Wall -Wextra -Werror

# Project and library name
PROJECT := "Libftprintf Project"
AUTHOR := "Joseph Boustany"
NAME := libftprintf.a

# Source files
SRCS := ft_printf.c \
        ft_printf_part2.c

BONUS_SRCS := 

# Object files
OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

# ANSI color codes
BLUE := \033[0;34m
RESET := \033[0m

# Title function
define title
	@echo "=========================================================================================="
	@echo "$(BLUE)                  		$(PROJECT)$(RESET)"
	@echo "                                   $(AUTHOR)"
	@echo "=========================================================================================="
endef

# Message function for consistent formatting
define message
	@echo "=================================================="
	@echo "  $(1)"
	@echo "=================================================="
endef

# Default target
all: title $(NAME)

# Title target
title:
	$(title)

# Main target
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Bonus target
bonus: $(BONUS_OBJS)
	$(call message,"Creating bonus library $(NAME)...")
	@$(AR) $(NAME) $(BONUS_OBJS)
	$(call message,"Bonus library $(NAME) created successfully.")

# Pattern rule for object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	$(call message,"Cleaning object files...")
	@rm -f $(OBJS) $(BONUS_OBJS)
	$(call message,"Object files cleaned.")

# Full clean up
fclean: clean
	$(call message,"Removing library $(NAME)...")
	@rm -f $(NAME)
	$(call message,"Library $(NAME) removed.")

# Rebuild everything
re: fclean all

# Declare targets that are not files
.PHONY: all clean fclean re bonus title

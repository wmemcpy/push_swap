EXEC	= push_swap

# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #

SRCS	= ./src/
OBJS	= ./obj/

LIBFT	= ./libft/

# **************************************************************************** #

CFILE	= $(SRCS)main.c \
$(SRCS)check_args.c \
$(SRCS)big_sort.c \
$(SRCS)little_sort.c \
$(SRCS)push.c \
$(SRCS)swap.c \
$(SRCS)rotate.c \
$(SRCS)rev_rotate.c \
$(SRCS)utils.c \

OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

COUNTER = 0
TOTAL	= $(words $(CFILE))

# **************************************************************************** #

all: $(EXEC)

# **************************************************************************** #

$(EXEC): $(OFILE)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(EXEC) $(OFILE) $(LIBFT)/libft.a
	@echo -e "$(GREEN)----------------$(YELLOW)[$(NAME) created]$(GREEN)----------------$(RESET)"

# **************************************************************************** #

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@echo -e "$(YELLOW)[ $(GREEN)$(shell echo $$(($(COUNTER)*100/$(TOTAL))))%$(YELLOW) ]$(RESET) Building C object $(GREEN)$<$(RESET)"

# **************************************************************************** #

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS)
	@echo -e "$(RED)----------------$(YELLOW)[$(OBJS) deleted]$(RED)----------------$(RESET)"

# **************************************************************************** #

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(EXEC)
	@echo -e "$(RED)----------------$(YELLOW)[$(NAME) deleted]$(RED)----------------$(RESET)"

# **************************************************************************** #

re: fclean all

# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# **************************************************************************** #
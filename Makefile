CC = ar -rcs
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = printf.c funcionesprint.c
LIB_DIR = libft
LIBFT = libft/libft.a


# Do not change these
OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[0;34mBuilding $@\033[0m"
	@$(CC) $(NAME) $(OBJ)
	@echo "\033[0;33mFinished building $@\033[0m"

$(LIBFT):
	@make -C $(LIB_DIR)
	@cp $(LIBFT) .
	@mv $(LIBFT) $(NAME)

clean:
  #  @echo "\033[0;31mDeleting $(OBJ_DIR)\033[0m"
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ)
   # @rm -rf $(OBJ_DIR)

fclean: clean
   # @echo "\033[0;31mDeleting $(BUILD_DIR)\033[0m"
	@make -C $(LIB_DIR) fclean
	rm -f libft.a
	@rm -rf $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -I headers -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re







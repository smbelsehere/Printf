CC = ar -rcs
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = printf.c funcionesprint.c
#BUILD_DIR = build
INCLUDE_DIR = headers
INCLUDES = -I./$(INCLUDE_DIR)
LIB_DIR = libft
LIBS = -L./$(LIB_DIR)
LIBFT = libft/libft.a


# Do not change these
#SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
#OBJ_DIR = $(BUILD_DIR)/obj
OBJ = $(SRC:.c=.o)
#OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ))


all: $(NAME)

#-include $(OBJ:.o=.d)

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
 #   @echo "\033[0;32mCompiling $<\033[0m"
  #  @mkdir -p $(basename $@)
   # @$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[0;34mBuilding $@\033[0m"
#	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $(NAME) $(LIBFT)
	@$(CC) $(NAME) $(OBJ)
	@echo "\033[0;33mFinished building $@\033[0m"

$(LIBFT):
	@make -C libft/

clean:
  #  @echo "\033[0;31mDeleting $(OBJ_DIR)\033[0m"
	@make -C libft/ clean
	@rm -rf $(OBJ)
   # @rm -rf $(OBJ_DIR)

fclean: clean
   # @echo "\033[0;31mDeleting $(BUILD_DIR)\033[0m"
	@make -C libft/ fclean
  #  @rm -rf $(BUILD_DIR)
	@rm -rf $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -I headers -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re







NAME = push_swap
CC= cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC= push_swap.c push_swap_utils.c ft_split.c
OBJ = $(SRC:.c=.o)

# The default rule that builds the library.
all: $(NAME)

# '$^' represents the object files (dependencies), and '$@' represents the target (executable).
$(NAME): ${OBJ}
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ):	
	$(CC) $(CFLAGS) -c $(SRC)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
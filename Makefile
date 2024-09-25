NAME=philo
CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address 
LT = -lpthread

SRC=main.c strings.c structs.c check.c using.c ft_free.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $^ $(LT) -o $@ 
	rm -rf $(OBJ)

%.o: %.c
	cc $(CFLAGS)  $< -c -o $@

clean:

fclean: clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)

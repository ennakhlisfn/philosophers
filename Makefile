NAME=philo
CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address 
LT = -lpthread

SRC=main.c strings.c structs.c check.c using.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $^ $(LT) -o $@ 

%.o: %.c
	cc $(CFLAGS)  $< -c -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)

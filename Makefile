NAME = pion-more
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
HDR = -I./includes
LIBLINK = ./libft
RM = rm -f

SRC = pion-more.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBLINK)
	@$(CC) $(CFLAG) $(SRC) $(HDR)
	@$(CC) $(OBJ) -o $(NAME) $(HDR) -L$(LIBLINK) -lft

clean:
	@make clean -C $(LIBLINK)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBLINK)
	@$(RM) $(NAME)

re: fclean all
	@make re -C $(LIBLINK)
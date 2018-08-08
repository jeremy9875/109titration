##
## Makefile for Makefile in /home/VSridhar78/109titration
## 
## Made by Sridhar Vengadesan
## Login   <VSridhar78@epitech.net>
## 
## Started on  Wed Mar 29 08:24:24 2017 Sridhar Vengadesan
## Last update Wed Mar 29 08:30:08 2017 Sridhar Vengadesan
##

NAME    =       109titration

SRC     =       109titration.c              \

OBJ     =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc $(OBJ) -W -Wall -Werror -Wextra -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:         all clean fclean re

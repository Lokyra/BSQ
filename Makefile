##
## EPITECH PROJECT, 2022
## my_hunter
## File description:
## makefile
##

CC	=	gcc
CFLAGS = -W -Wall -Wextra


SRC = 	./src/algo.c \
		./src/main.c \
		./src/compil.c \
		./src/compil_second.c \
		./src/display.c \
		./src/compilation.c \
		./src/generated.c \
		./src/generation.c \
		./src/function.c \
		./src/logic.c \

OBJ	=	$(SRC:.c=.o)

TARGET	=	bsq

RM	=	rm -f

all:	$(TARGET)

$(TARGET):	$(OBJ)
	$(CC) -o $@ $^ -I../includes

clean:
	cd ./src
	$(RM) $(OBJ)

fclean: clean
	cd ./src
	$(RM) $(TARGET)

re:	fclean all

.PHONY: all clean fclean re

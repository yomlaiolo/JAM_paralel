##
## EPITECH PROJECT, 2023
## JAM_paralel
## File description:
## Makefile
##

FILES	=	main.cpp \

SRC		=	$(FILES:%=src/%)

OBJ		=	$(SRC:.cpp=.o)

NAME	=	DoubleVision

CFLAGS	=	-Wall -Wextra -I./include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ljsoncpp

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f vg*

fclean: clean
	rm -f $(NAME)
	rm -f coding-style*

re: fclean all

debug: CFLAGS += -g3
debug: re

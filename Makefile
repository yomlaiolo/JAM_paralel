##
## EPITECH PROJECT, 2023
## JAM_paralel
## File description:
## Makefile
##

FILES	=	main.cpp \
			Core/Block.cpp \
			Core/Player.cpp \
			Core/Core.cpp \
			Core/Map.cpp \
			Core/Parallax.cpp \

SRC		=	$(FILES:%=src/%)

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

NAME	=	DoubleVision

CFLAGS	=	-Wall -Wextra -I./src/Core -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vg*

fclean: clean
	rm -f $(NAME)
	rm -f coding-style*

re: fclean all

debug: CFLAGS += -g3
debug: re

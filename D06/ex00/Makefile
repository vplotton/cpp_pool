# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbres <sbres@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 20:53:45 by sbres             #+#    #+#              #
#    Updated: 2015/01/13 21:01:20 by sbres            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= g++
FLAGS=-Wall -Wextra -Werror
LIBS=-lncurses
SRC=main.cpp \
	Scalar.cpp

OBJ= $(SRC:.cpp=.o)
NAME= convert

.PHONY: clean fclean re all
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIBS)
		echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"

%.o: %.cpp
		echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		echo "\t\xF0\x9F\x92\xA3   Cleaning"
		rm -rf $(OBJ)

fclean: clean
		echo "\t\xF0\x9F\x9A\xBD   Full Clean"
		rm -rf $(NAME)

re: fclean all



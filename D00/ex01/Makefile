# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:27:45 by vplotton          #+#    #+#              #
#    Updated: 2015/01/05 10:35:23 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = g++
RM  = rm -rf
NAME    = phonebook
CFLAGS  = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC = main.cpp \
	  phonebook.cpp

all:        $(NAME)

$(NAME):    $(OBJ)
		    $(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	        $(RM) $(OBJ)

fclean:     clean
	        $(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re

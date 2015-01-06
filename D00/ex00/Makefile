# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:27:45 by vplotton          #+#    #+#              #
#    Updated: 2015/01/05 09:58:26 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = g++
RM  = rm -rf
NAME    = megaphone
CFLAGS  = -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)
SRC = megaphone.cpp

all:        $(NAME)

$(NAME):    $(OBJ)
	        $(L_MAKE)
		    $(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	        $(RM) $(OBJ)

fclean:     clean
	        $(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re

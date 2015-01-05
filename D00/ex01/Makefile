# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:27:45 by vplotton          #+#    #+#              #
#    Updated: 2015/01/05 09:50:39 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = g++
RM  = rm -rf
NAME    = megaphone
HEADER  = ./inc/
CFLAGS  = -Wall -Wextra -Werror -I$(HEADER)
OBJ = $(SRC:.c=.o)
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

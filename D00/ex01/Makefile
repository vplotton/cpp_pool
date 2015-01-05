# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:27:45 by vplotton          #+#    #+#              #
#    Updated: 2015/01/05 15:29:18 by vplotton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = g++
RM  = rm -rf
NAME    = phonebook
CFLAGS  = -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)
SRC = main.cpp		\
	  contact.cpp	\
	  phonebook.cpp

all:        $(NAME)

$(NAME):    $(OBJ)
		    $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.cpp.o:
	    $(CC) $(CFLAGS) -c $<

clean:
	        $(RM) $(OBJ)

fclean:     clean
	        $(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re

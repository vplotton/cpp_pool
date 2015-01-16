CXX		= g++
RM		= rm -rf
NAME	= GKrellM
HEADER	= ./inc/
SRCDIR	= ./src/
OBJDIR	= ./obj/
CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)
SRC			= $(SRCDIR)main.cpp
OBJ			= $(addprefix $(OBJDIR),$(notdir $(SRC:.cpp=.o)))

all:			$(NAME)

$(OBJDIR)%.o:  		$(SRCDIR)%.cpp
		@$(CXX) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

$(NAME):	$(OBJ)
		@$(CXX) -o $(NAME) $(OBJ)
		@echo "Linking complete!"

clean:
		@$(RM) $(OBJ)
		@echo "Objects removed successfully"

fclean:		clean
		$(RM) $(NAME)
		@echo "$(NAME) removed successfully"

re:		fclean all

.PHONY: all clean fclean re

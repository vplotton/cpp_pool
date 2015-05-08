CXX		= g++ -std=c++11
RM		= rm -rf
NAME	= gomoku
HEADER	= ./inc/
SRCDIR	= ./src/
OBJDIR	= ./obj/
CFLAGS	= -Wall -Wextra -Werror -g3 -I$(HEADER)
SRC			= $(SRCDIR)main.cpp
OBJ			= $(addprefix $(OBJDIR),$(notdir $(SRC:.cpp=.o)))

all:			$(NAME)

$(OBJDIR)%.o:  		$(SRCDIR)%.cpp
		@mkdir -p obj
		@$(CXX) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

$(NAME):	$(OBJ)
		@$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)
		@echo "Linking complete!"

clean:
		@$(RM) $(OBJDIR)
		@echo "Objects removed successfully"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed successfully"

re:		fclean all

.PHONY: all clean fclean re

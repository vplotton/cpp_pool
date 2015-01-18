CXX		= g++
RM		= rm -rf
NAME	= ft_gkrellm
HEADER	= ./inc/
SRCDIR	= ./src/
OBJDIR	= ./obj/
CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)
SRC			= $(SRCDIR)main.cpp				\
			  $(SRCDIR)Cpu.cpp				\
			  $(SRCDIR)User.cpp				\
			  $(SRCDIR)Clock.cpp			\
			  $(SRCDIR)OSInfo.cpp			\
			  $(SRCDIR)Memory.cpp			\
			  $(SRCDIR)Network.cpp			\
			  $(SRCDIR)SwapMemory.cpp		\
			  $(SRCDIR)ModuleFactory.cpp	\
			  $(SRCDIR)AbstractModule.cpp
OBJ			= $(addprefix $(OBJDIR),$(notdir $(SRC:.cpp=.o)))

all:			$(NAME)

$(OBJDIR)%.o:  		$(SRCDIR)%.cpp
		@mkdir -p obj
		@$(CXX) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

$(NAME):	$(OBJ)
		@$(CXX) -o $(NAME) $(OBJ)
		@echo "Linking complete!"

clean:
		@$(RM) $(OBJDIR)
		@echo "Objects removed successfully"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed successfully"

re:		fclean all

.PHONY: all clean fclean re

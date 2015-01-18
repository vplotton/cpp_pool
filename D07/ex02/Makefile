RM				= rm -rf
CXX         	= g++
NAME			= array
NAME_INLINE		= inline
NAME_NO_INLINE	= noInline
CFLAGS			= -Wall -Wextra -Werror
DEFINE			= -D
TEST_NO_INLINE	= TEST_NO_INLINE
OBJ				= $(SRC:.cpp=.o)
SRC 			= main.cpp

.PHONY: clean fclean re all
	    .SILENT:

all: $(NAME)

$(NAME_INLINE): CXX += -D_TEST_INLINE
$(NAME_INLINE): CFLAGS += -Winline -O2 -finline-functions -Wconversion 
$(NAME_INLINE): fclean
$(NAME_INLINE): $(NAME)
$(NAME_INLINE):
		@time ./$(NAME)


$(NAME_NO_INLINE): CXX += -D_TEST_NO_INLINE
$(NAME_NO_INLINE): fclean
$(NAME_NO_INLINE): $(NAME)
$(NAME_NO_INLINE):
		@time ./$(NAME)


$(NAME): $(OBJ)
		@$(CXX) -o $(NAME) $(OBJ)
		@echo "--- Compiled executable ---"


%.o: %.cpp
			@$(CXX) -c $(CFLAGS) -o $@ $<


clean:
		@$(RM) $(OBJ)
		@echo "--- rm .o ---"


fclean: clean
		@$(RM) $(NAME)
		@echo "--- rm executable ---"


re: fclean all

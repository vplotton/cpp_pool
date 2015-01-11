C= g++
FLAGS=-Wall -Wextra -Werror
LIBS=-lncurses
SRC=
	mergeMain.cpp \
	AbstractObject.cpp \
	Controller.cpp \
	Display.cpp \
	Enemy.cpp \
	Game.cpp \
	Interact.cpp \
	Menu.cpp\
	Movement.cpp \
	Projectile.cpp\
	SpaceShip.cpp \
	Weapon.cpp\

OBJ= $(SRC:.cpp=.o)
	NAME= ft_retro

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

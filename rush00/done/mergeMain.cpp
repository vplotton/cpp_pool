#include "Display.hpp"
#include "Controller.hpp"
#include "AbstractObject.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Movement.hpp"
#include "Game.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Menu.hpp"

int main()
{
	Display *d = new Display();
	Controller *ctrl = new Controller();
	
	int		ch;
	Menu	*menu = new Menu();
	initscr();			/* Start curses mode 		*/
	d->set_win(d->ft_init_win());
	menu->set_menu(menu->init_menu());
	start_color();			/* Start the color functionality */
	raw(); 					// pour les ctrl truc
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	noecho();
	curs_set(0);				// desactive le curseur
	nodelay(stdscr, TRUE);		//desactive l attente dune touche pour continuer
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	refresh();
	printw("appuyer sur  une touche pour commencer");

	Game		*game = new Game;
	SpaceShip	*ship = (SpaceShip*)game->getSpaceObject(0); 
	ship->getMovement()->setX(20);
	ship->getMovement()->setY(20);
	ship->setLife(3);

	AbstractObject *newProjectile;
	int		createTime = 0;
	while((ch = getch()) != KEY_F(1))
	{
		if (game->checkCollision() == true)
		{
			break ;
		}
		newProjectile = NULL;
		AbstractObject  **spaceObjects = game->getSpaceObjects();
	//	menu->destroy_menu(menu->get_menu());
		d->destroy_win(d->get_win());
		d->set_win(d->ft_init_win());
		box(d->get_win(), 0 , 0);
		box(menu->get_menu(), 0 , 0);

		newProjectile = ctrl->ft_get_input(ch, d, ship);
		d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
		
		if (newProjectile != NULL)
		{
			game->pushSpaceObject(newProjectile);
		}

		if (createTime++ % game->getSpawnRate() == 0)
		{
			AbstractObject *enemy = new Enemy(1,50, 20);
			game->pushSpaceObject(enemy);
		}
		for (int i = 1; i < 100 ; ++i)
		{
			if (spaceObjects[i])
			{
				if (spaceObjects[i]->getType() == AbstractObject::PROJECTILE)
				{
					spaceObjects[i]->getMovement()->goForward();
				}
				else if (spaceObjects[i]->getType() == AbstractObject::ENEMY
						&& (createTime % game->getSpawnRate() == 0))
				{
					spaceObjects[i]->getMovement()->goForward();
				}
				if (spaceObjects[i]->getMovement()->checkLimits())
				{
					game->deleteSpaceObject(i);
				}
				else
				{
					d->print_obj(d->get_win(), spaceObjects[i]->getMovement()->getX(), spaceObjects[i]->getMovement()->getY(), 0);
				}
			}
		}
		menu->print_life(ship);
		wrefresh(d->get_win());
		wrefresh(menu->get_menu());
		usleep(100000);
	}
	endwin();
	delete d;
	delete ctrl;
	delete menu;
	delete game;
}

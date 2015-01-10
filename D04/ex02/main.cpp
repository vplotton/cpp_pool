#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"


int main()
{
	std::cout << "==== MY MAIN ====" << std::endl;
	ISpaceMarine	*tacticalMarine = new TacticalMarine;
	ISpaceMarine	*assaultTerminator = new AssaultTerminator;
	
	
	ISquad			*squad = new Squad;

	std::cout << "tests: getUnit(-1) & getUnit(0)" << std::endl;
	squad->getUnit(-1);
	squad->getUnit(0);

	std::cout << std::endl;
	std::cout << "tests: add tacticalMarine & assaultTerminator" << std::endl;
	squad->push(tacticalMarine);
	squad->push(assaultTerminator);
	std::cout << "squad->getCount() = " << squad->getCount() << std::endl;
	std::cout << std::endl;

	std::cout << "tests: Copy squad into newSquad" << std::endl;
	ISquad	*newSquad = new Squad(*(Squad*)squad);
	std::cout << std::endl;
	std::cout << "newSquad->getCount() = " << newSquad->getCount() << std::endl;


	std::cout << std::endl;
	std::cout << "tests: delete newSquad & squad" << std::endl;
	delete squad;
	delete newSquad;
	std::cout << std::endl;

	std::cout <<"== DEFAULT MAIN ==" << std::endl;
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}

#include "Pony.hpp"

Pony	ponyOnTheHeap()
{
	Pony heapPony;

	heapPony.setName("heapPony");
	return (heapPony);
}

Pony	*ponyOnTheStack()
{
	Pony *stackPony = new Pony();

	stackPony->setName("stackPony");
	return (stackPony);
}

int		main()
{
	Pony heapPony = ponyOnTheHeap();
	Pony *stackPony = ponyOnTheStack();

	delete stackPony;
	return (0);
}

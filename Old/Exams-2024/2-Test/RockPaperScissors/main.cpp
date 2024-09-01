#include <iostream>
#include "GameSequence.h"
#include "GameObjectsFactory.h"

int main()
{
	std::ifstream ifs("players.txt");
	if (!ifs.is_open())
	{
		std::cout << "Cannot open game file";
		return -1;
	}

	size_t players;
	ifs >> players;
	GameSequence game(players);

	for (size_t i = 0; i < players; i++)
	{
		game.addGameObject(gameObjectFactory(ifs));
	}

	std::cout << game.playTournament();
	return 0;
}
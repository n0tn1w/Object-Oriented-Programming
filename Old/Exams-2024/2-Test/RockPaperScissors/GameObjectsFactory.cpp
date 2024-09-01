#include "GameObjectsFactory.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"


Scissors* createScissors(std::ifstream& ifs)
{
	int value;
	ifs >> value;
	return new Scissors(value);
}

Rock* createRock(std::ifstream& ifs)
{
	bool value;
	ifs >> value;
	return new Rock(value);
}

Paper* createPaper(std::ifstream& ifs)
{
	// Reading could be improved and further validated
	char str[1024];
	ifs >> str;
	return new Paper(str);
}

GameObject* gameObjectFactory(std::ifstream& ifs)
{
	int moveCode;
	ifs >> moveCode;

	switch (moveCode)
	{
	case 0:
		return createScissors(ifs);
	case 1:
		return createRock(ifs);
	case 2:
		return createScissors(ifs);
	}

	throw std::runtime_error("File data not in correct format");
}

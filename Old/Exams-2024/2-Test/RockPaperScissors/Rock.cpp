#include "Rock.h"
Rock::Rock(bool value) : value(value)
{

}

int Rock::duelAgainst(const GameObject* other) const
{
	return -(other->duelAgainstRock(this));
}

int Rock::duelAgainstRock(const Rock* other) const
{
	if (value < other->value)
	{
		return 1;
	}

	if (value > other->value)
	{
		return -1;
	}

	return 0;
}

int Rock::duelAgainstPaper(const Paper* other) const
{
	return -1;
}

int Rock::duelAgainstScissors(const Scissors* other) const
{
	return 1;
}

GameObject* Rock::clone() const
{
	return new Rock(*this);
}

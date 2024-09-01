#pragma once
#include "GameObject.h"

class Rock : public GameObject
{
	bool value;

public:
	Rock(bool value);

	int duelAgainst(const GameObject* other) const override;

	int duelAgainstRock(const Rock* other) const override;
	int duelAgainstPaper(const Paper* other) const override;
	int duelAgainstScissors(const Scissors* other) const override;

	GameObject* clone() const override;
};


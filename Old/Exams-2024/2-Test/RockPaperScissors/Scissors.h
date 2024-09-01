#pragma once
#include "GameObject.h"

class Scissors : public GameObject
{
	int value;

public:
	Scissors(int value);

	int duelAgainst(const GameObject* other) const override;

	int duelAgainstRock(const Rock* other) const override;
	int duelAgainstPaper(const Paper* other) const override;
	int duelAgainstScissors(const Scissors* other) const override;

	GameObject* clone() const override;
};


#pragma once

class Rock;
class Paper;
class Scissors;

class GameObject
{
public:
	virtual int duelAgainst(const GameObject* other) const = 0;
	virtual int duelAgainstRock(const Rock* other) const = 0;
	virtual int duelAgainstPaper(const Paper* other) const = 0;
	virtual int duelAgainstScissors(const Scissors* other) const = 0;

	virtual ~GameObject() = default;

	virtual GameObject* clone() const = 0;
};


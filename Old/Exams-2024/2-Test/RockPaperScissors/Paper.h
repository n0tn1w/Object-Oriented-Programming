#pragma once
#include "GameObject.h"

class Paper : public GameObject
{
	char* message;

	void free();
	void copyFrom(const Paper& other);
	void moveFrom(Paper&& other);
public:
	Paper(const char* str);

	Paper(const Paper& other);
	Paper(Paper&& other) noexcept;
	Paper& operator=(const Paper& other);
	Paper& operator=(Paper&& other) noexcept;
	~Paper();

	int duelAgainst(const GameObject* other) const override;

	int duelAgainstRock(const Rock* other) const override;
	int duelAgainstPaper(const Paper* other) const override;
	int duelAgainstScissors(const Scissors* other) const override;

	GameObject* clone() const override;
};


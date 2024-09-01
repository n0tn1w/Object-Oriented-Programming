#include "Paper.h"
#pragma warning(disable:4996)
#include <cstring>
#include <stdexcept>

static bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

static bool isValidMessage(const char* str)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++)
	{
		if (!isLower(str[i]))
		{
			return false;
		}
	}

	return true;
}

Paper::Paper(const char* str)
{
	if (str == nullptr || !isValidMessage(str))
	{
		throw std::invalid_argument("Cannot create Paper object with invalid message");
	}

	message = new char[strlen(str) + 1];
	strcpy(message, str);
}

void Paper::free()
{
	delete[] message;
}

void Paper::copyFrom(const Paper& other)
{
	message = new char[strlen(other.message) + 1];
	strcpy(message, other.message);
}

void Paper::moveFrom(Paper&& other)
{
	message = other.message;
	other.message = nullptr;
}

Paper::Paper(const Paper& other) : GameObject(other)
{
	copyFrom(other);
}

Paper::Paper(Paper&& other) noexcept : GameObject(std::move(other))
{
	moveFrom(std::move(other));
}

Paper& Paper::operator=(const Paper& other)
{
	if (this != &other)
	{
		GameObject::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Paper& Paper::operator=(Paper&& other) noexcept
{
	if (this != &other)
	{
		GameObject::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Paper::~Paper()
{
	free();
}

int Paper::duelAgainst(const GameObject* other) const
{
	return -(other->duelAgainstPaper(this));
}

int Paper::duelAgainstRock(const Rock* other) const
{
	return 1;
}

int Paper::duelAgainstPaper(const Paper* other) const
{
	int compResult = strcmp(message, other->message);

	if (compResult < 0)
	{
		return -1;
	}

	if (compResult > 0)
	{
		return 1;
	}

	return 0;
}

int Paper::duelAgainstScissors(const Scissors* other) const
{
	return -1;
}

GameObject* Paper::clone() const
{
	return new Paper(*this);
}

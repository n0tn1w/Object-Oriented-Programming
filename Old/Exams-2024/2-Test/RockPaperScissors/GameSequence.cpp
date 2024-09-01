#include "GameSequence.h"
#include <stdexcept>

GameSequence::GameSequence(size_t playersCount)
{
	capacity = playersCount;
	data = new GameObject * [capacity];
}

bool GameSequence::isValidIndex(size_t index) const
{
	return index < size;
}

void GameSequence::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete data[i];
	}

	delete[] data;
}

void GameSequence::copyFrom(const GameSequence& other)
{
	capacity = other.capacity;
	size = other.size;
	data = new GameObject * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void GameSequence::moveFrom(GameSequence&& other)
{
	capacity = other.capacity;
	data = other.data;
	size = other.size;

	other.data = nullptr;
	other.capacity = 0;
	other.size = 0;
}

GameSequence::GameSequence(const GameSequence& other)
{
	copyFrom(other);
}

GameSequence::GameSequence(GameSequence&& other) noexcept
{
	moveFrom(std::move(other));
}

GameSequence& GameSequence::operator=(const GameSequence& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
GameSequence& GameSequence::operator=(GameSequence&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

GameSequence::~GameSequence()
{
	free();
}

void GameSequence::addGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
	{
		throw std::invalid_argument("Cannot add empty game object");
	}

	if (size == capacity)
	{
		throw std::runtime_error("Cannot add any more players to game");
	}

	data[size++] = gameObject;
}

size_t GameSequence::getSize() const
{
	return capacity;
}

int GameSequence::duelTwoPlayers(size_t firstIndex, size_t secondIndex) const
{
	if (!isValidIndex(firstIndex) || !isValidIndex(secondIndex))
	{
		throw std::invalid_argument("Cannot duel invalid player indecies");
	}

	if (firstIndex == secondIndex)
	{
		return 0;
	}

	return data[firstIndex]->duelAgainst(data[secondIndex]) == 1 ? 1 : 0;
}

size_t GameSequence::playTournament() const
{
	int maxResult = INT32_MIN;
	size_t winnerId = 0;
	for (size_t i = 0; i < size; i++)
	{
		int currResult = 0;
		for (size_t j = 0; j < size; j++)
		{
			currResult += duelTwoPlayers(i, j);
		}

		if (currResult > maxResult)
		{
			winnerId = i;
			maxResult = currResult;
		}
	}

	return winnerId;
}

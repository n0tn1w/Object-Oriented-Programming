#pragma once
#include "GameObject.h"
#include <fstream>

class GameSequence
{
	GameObject** data;
	size_t capacity;
	size_t size = 0;

	bool isValidIndex(size_t index) const;

	void free();
	void copyFrom(const GameSequence& other);
	void moveFrom(GameSequence&& other);
public:
	GameSequence(size_t playersCount);

	GameSequence(const GameSequence& other);
	GameSequence(GameSequence&& other) noexcept;
	GameSequence& operator=(const GameSequence& other);
	GameSequence& operator=(GameSequence&& other) noexcept;
	~GameSequence();

	void addGameObject(GameObject* gameObject);

	size_t getSize() const;
	int duelTwoPlayers(size_t firstIndex, size_t secondIndex) const;
	size_t playTournament() const;
};


#pragma once
#include "HelpingFunctions.h"
#include <fstream>

class BannedList {
private:
	size_t capacity;
	size_t size;
	int16_t* values;

	void free();
	void resize(size_t);
	void copy(const BannedList&);
public:
	BannedList();
	BannedList(const BannedList&);
	BannedList& operator=(const BannedList&);
	~BannedList();

	void add(int16_t);

	size_t getSize() const;

	int16_t getValue(size_t) const;

	bool isBanned(int16_t) const;

	bool isEmpty() const;

	void serealize(std::ofstream&) const;
	void deserealize(std::ifstream&);

};
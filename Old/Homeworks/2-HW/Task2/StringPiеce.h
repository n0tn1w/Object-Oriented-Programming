#pragma once
#include <iostream>
#include "stringHelper.h"

using namespace std;

const int STR_SIZE = 16;
enum class Position { begin, end };

class StringPiece {
	char str[STR_SIZE];
	size_t size;

	//start and end index are inclusive
	size_t start, end;

public:

	StringPiece();
	StringPiece(const char*);

	void setPiece(const char*);

	const char* getPiece() const;
	const size_t getSize() const;

	char& operator[](size_t);
	char operator[](size_t) const;

	void remove(const Position&, size_t);
	void changeByIndex(const char, size_t);

	StringPiece& operator<<(const char*);
	StringPiece& operator<<(int);

	friend StringPiece& operator>>(const char*, StringPiece&);
	friend StringPiece& operator>>(int, StringPiece&);
	friend StringPiece& operator>>(istream&, StringPiece&);


private:
	void checkIfIndexIsValid(size_t) const;
	void nullify();
};

StringPiece& operator>>(const char*, StringPiece&);
StringPiece& operator>>(int, StringPiece&); 
StringPiece& operator>>(istream&, StringPiece&);

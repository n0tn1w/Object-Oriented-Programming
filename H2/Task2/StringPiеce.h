#pragma once
#include <iostream>

using namespace std;

class StringPiece {
	char str[17];
	//size_t size;

public:


	StringPiece();
	StringPiece(const char*);

	void setPiece(const char*);
	const char* getPiece() const;

	const size_t getSize() const;

	char& operator[](size_t);
	char operator[](size_t) const;

	bool remove(int, size_t);
	// test__________  insert inside (2 4)

	void changeByIndex(const char, size_t);

	// test__________  insert inside (g 10)
};

ostream operator<<(ostream&, const StringPiece&);
istream operator>>(istream&, StringPiece&);

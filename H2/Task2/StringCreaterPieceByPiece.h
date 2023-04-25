#pragma once
#include <iostream>
#include "StringPiåce.h"
#include "MyString.h"

using namespace std;

class StringCreaterPieceByPiece {

	StringPiece** pieces;
	size_t size;
	size_t capacity;

public:

	StringCreaterPieceByPiece();
	StringCreaterPieceByPiece(size_t);
	StringCreaterPieceByPiece(const StringCreaterPieceByPiece&);
	StringCreaterPieceByPiece& operator=(const StringCreaterPieceByPiece&);
	~StringCreaterPieceByPiece();

	void addPiece(const char*);
	void addPiece(const char*, size_t);
	void remove(size_t);
	void swap(size_t, size_t);
	size_t getLen() const;

	MyString& getString() const;

private:
	void free();
	void copy(const StringCreaterPieceByPiece&);

};
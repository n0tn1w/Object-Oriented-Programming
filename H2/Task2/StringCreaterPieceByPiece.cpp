#include "StringCreaterPieceByPiece.h"

StringCreaterPieceByPiece::StringCreaterPieceByPiece() : StringCreaterPieceByPiece(0) {}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(size_t index) {

	this->capacity = index;
	this->size = 0;

	this->pieces = nullptr;
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other) {

	copy(other);

}

StringCreaterPieceByPiece& StringCreaterPieceByPiece::operator=(const StringCreaterPieceByPiece& other) {
	
	if (this != &other) {

		free();
		copy(other);

	}

	return *this;
}
StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {
	free();
}

void StringCreaterPieceByPiece::free() {

}

void StringCreaterPieceByPiece::copy(const StringCreaterPieceByPiece& other) {

}

void StringCreaterPieceByPiece::addPiece(const char* str) {
	StringPiece* sp = new StringPiece(str);

	//Validation size
	this->pieces[size] = sp;
	size++;
}

void StringCreaterPieceByPiece::addPiece(const char* str, size_t index) {

	//Validate if piece exists
	remove(index);

	//Create new piece
	StringPiece* sp = new StringPiece(str);
	this->pieces[index] = sp;
}

void StringCreaterPieceByPiece::remove(size_t index) {
	//Validate index
	this->pieces[index] = nullptr;

}
void StringCreaterPieceByPiece::swap(size_t index1, size_t index2) {
	//Validate index1 index2
	StringPiece* temp = this->pieces[index1];
	this->pieces[index1] = this->pieces[index2];
	this->pieces[index2] = temp;
}


size_t StringCreaterPieceByPiece::getLen() const {
	size_t totalSize = 0;
	
	for (size_t i = 0; i < size; i++) {
		totalSize += this->pieces[i]->getSize();
	}

	return totalSize;
}

MyString& StringCreaterPieceByPiece::getString() const {
	MyString str("");

	for (size_t i = 0; i < size; i++) {
		if (size - 2 >= 0 && i == size - 2) {
			if (this->pieces[i] == nullptr) {
				str += "          ";
			}
		}

		str += MyString(this->pieces[i]->getPiece());
	}

	return str;
}
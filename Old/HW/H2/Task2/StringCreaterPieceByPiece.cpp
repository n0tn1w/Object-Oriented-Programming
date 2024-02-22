#include "StringCreaterPieceByPiece.h"

StringCreaterPieceByPiece::StringCreaterPieceByPiece() : StringCreaterPieceByPiece(0) {}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(size_t index) {

	this->capacity = index;
	this->count = 0;

	this->pieces = new StringPiece* [capacity] {nullptr};
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

StringCreaterPieceByPiece::StringCreaterPieceByPiece(StringCreaterPieceByPiece&& other) {
	pieces = other.pieces;
	other.pieces = nullptr;
	count = other.count;
	capacity = other.capacity;

}

StringCreaterPieceByPiece& StringCreaterPieceByPiece::operator=(StringCreaterPieceByPiece&& other) {
	if (this != &other)
	{
		free();
		pieces = other.pieces;
		other.pieces = nullptr;
		count = other.count;
		capacity = other.capacity;
	}
	return *this;
}


StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {

	free();
}

void StringCreaterPieceByPiece::free() {

	for (size_t i = 0; i < this->count; i++)
		delete pieces[i];
	delete[] pieces;

}

void StringCreaterPieceByPiece::copy(const StringCreaterPieceByPiece& other) {
	this->count = other.count;
	this->capacity = other.capacity;

	this->pieces = new StringPiece* [this->capacity];
	for (size_t i = 0; i < this->count; i++)
	{
		if (other.pieces[i] == nullptr) {
			pieces[i] = nullptr;
		}
		else {
			pieces[i] = new StringPiece(*other.pieces[i]);
		}
	}
}

void StringCreaterPieceByPiece::resize(size_t newCapacity) {

	StringPiece** newPieces = new StringPiece* [newCapacity] {nullptr};

	for (int i = 0; i < this->count; i++) {
		newPieces[i] = this->pieces[i];
	}

	delete[] this->pieces;
	this->pieces = newPieces;

	this->capacity = newCapacity;

}

void StringCreaterPieceByPiece::addPiece() {
	//Init an empty piece
	addPiece("");
}

void StringCreaterPieceByPiece::addPiece(const char* str) {

	//Resize in case of overflow
	if (this->count >= this->capacity) {
		resize(this->capacity * 2);
	}

	this->pieces[this->count] = new StringPiece(str);
	this->count++;
}

void StringCreaterPieceByPiece::addPiece(const char* str, size_t index) {

	//Remove current piece in this place 
	remove(index);

	//Replace pointer
	this->pieces[index] = new StringPiece(str);
}

void StringCreaterPieceByPiece::remove(size_t index) {
	checkIfIndexIsValid(index);

	delete this->pieces[index];
	//Set the index to nullptr and when you need to add string to this index you need addPiece(str, index)
	this->pieces[index] = nullptr;

}
void StringCreaterPieceByPiece::swap(size_t index1, size_t index2) {
	checkIfIndexIsValid(index1);
	checkIfIndexIsValid(index2);

	StringPiece* temp = this->pieces[index1];
	this->pieces[index1] = this->pieces[index2];
	this->pieces[index2] = temp;
}


size_t StringCreaterPieceByPiece::getLen() const {
	size_t totalSize = 0;

	for (size_t i = 0; i < count; i++) {
		totalSize += this->pieces[i]->getSize();
	}

	return totalSize;
}

void StringCreaterPieceByPiece::checkIfIndexIsValid(size_t index) const {
	if (index < 0 || index > this->count) {
		throw out_of_range("Index of range!");
	}
}

MyString StringCreaterPieceByPiece::getString() const {
	MyString str("");

	for (size_t i = 0; i < this->count; i++) {
		if (this->count > 1 && i == this->count - 2) {
			//If the piece is nullptr or empty should add \s{20}
			if (this->pieces[i] == nullptr || this->pieces[i]->getSize() == 0) {
				str += "                      ";
			}
			else {
				str += MyString(this->pieces[i]->getPiece());
			}
			continue;
		}
		if (this->pieces[i] != nullptr) {
			str += MyString(this->pieces[i]->getPiece());
		}
	}

	return str;
}

const StringPiece& StringCreaterPieceByPiece::operator[](size_t index) const {
	checkIfIndexIsValid(index);
	return *this->pieces[index];
}
StringPiece& StringCreaterPieceByPiece::operator[](size_t index) {
	checkIfIndexIsValid(index);

	//Replace the empty pointer with a piece
	if (this->pieces[index] == nullptr) {
		//It could return a nullptr but in my implementation i choose not to
		//addPiece("", index);
		this->pieces[index] = new StringPiece("");
	
	}

	return *this->pieces[index];
}
#include "StringPiåce.h"

StringPiece::StringPiece(): StringPiece("") {}

StringPiece::StringPiece(const char* str) {

	setPiece(str);
}

void StringPiece::setPiece(const char* str) {
	if (strLenght(str) > 16) {
		return;
	}

	strCopy(this->str, str);
}

const char* StringPiece::getPiece() const {
	return this->str;
}

char& StringPiece::operator[](size_t index) {
	return this->str[index];
}

char StringPiece::operator[] (size_t index) const {
	return this->str[index];
}

bool StringPiece::remove(int type, size_t index) {
	//type: 1 - from the front, 2 - form the back
	if (type != 1 || type != 2) {
		return false;
	}

	//Validations
	if (strLenght(str) < index) {
		return false;
	}

	//Remove
}

void StringPiece::changeByIndex(const char ch, size_t index) {
	//Validations
	this->str[index] = ch;
}

const size_t StringPiece::getSize() const {
	return strLenght(str);
}

ostream operator<<(ostream& out, const StringPiece& from) {

}

istream operator>>(istream& in, StringPiece& to) {

}
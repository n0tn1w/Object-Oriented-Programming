#include "StringPiåce.h"

StringPiece::StringPiece() : StringPiece("") {}

StringPiece::StringPiece(const char* str) {

	setPiece(str);
}

void StringPiece::setPiece(const char* str) {
	size_t strSize = strLength(str);

	//Str abcdabcdabcdabcd\0
	if (strSize >= STR_SIZE) {
		throw length_error("Str size too big!");
	}


	// 1 and not zero because of "" has \0 only
	if (strSize == 1) {
		nullify();
	}
	else {
		strCopy(this->str, str);
		this->size = strSize;
		this->start = 0;
		this->end = strSize - 1;
	}
}

const char* StringPiece::getPiece() const {

	char* res = new char[this->size + 1];

	for (size_t i = 0; i < this->size; i++) {
		size_t index = (this->start + i) % STR_SIZE;
		res[i] = this->str[index];
	}
	res[this->size] = '\0';

	return res;
}

char& StringPiece::operator[](size_t index) {
	checkIfIndexIsValid(index);
	size_t atIndex = (index + this->start) % STR_SIZE;
	return this->str[atIndex];
}

char StringPiece::operator[] (size_t index) const {
	checkIfIndexIsValid(index);
	size_t atIndex = (index + this->start) % STR_SIZE;
	return this->str[atIndex];
}

void StringPiece::remove(const Position& position, size_t k) {

	//Validations for k
	if (k > size || k < 0) {
		throw logic_error("K value too big!");
	}

	//Set start or end (% is done in case of overflow)
	if (position == Position::begin) {
		this->start = (this->start + k) % STR_SIZE;
	}
	else if (position == Position::end) {
		this->end = (this->end + STR_SIZE - k) % STR_SIZE;
	}
	else {
		throw invalid_argument("Invalid position!");
	}

	if (this->start > this->end) {
		//in case k == this->size
		nullify();
	}
	else {
		this->size -= k;
	}

}

void StringPiece::changeByIndex(const char ch, size_t index) {
	checkIfIndexIsValid(index);
	this->str[this->start + index] = ch;
}

const size_t StringPiece::getSize() const {
	return this->size;
}

StringPiece& StringPiece::operator<<(const char* str) {
	size_t strSize = strLength(str);
	
	//Validate if the new string can fit inside
	if ( ( strSize + this->size ) >= STR_SIZE) {
		throw length_error("Str size too big!");
	}
	
	//Append to the end
	for (size_t i = 0; i < strSize; i++) {
		this->end = (this->end + 1) % STR_SIZE;
		this->str[this->end] = str[i];
	}
	this->size += strSize;

	return *this;
}

StringPiece& StringPiece::operator<<(int num) {
	//Use already existing operator
	return operator<<(convertIntToStr(num));
}

StringPiece& operator>>(const char* str, StringPiece& other)
{
	size_t strSize = strLength(str);

	//Validate if the new string can fit inside
	if ((strSize + other.size) >= STR_SIZE) {
		throw length_error("Str size too big!");
	}

	//Append to the end
	for (size_t i = 0; i < strSize; i++) {
		size_t index = (other.start + STR_SIZE - strSize + i) % STR_SIZE;
		other.str[index] = str[i];
	}

	other.size += strSize;
	other.start = (other.start + STR_SIZE - strSize) % STR_SIZE;

	return other;
}

StringPiece& operator>>(int num, StringPiece& other)
{
	return convertIntToStr(num) >> other;
}

StringPiece& operator>>(istream& is, StringPiece& other) {
	char buff[1024];
	is >> buff;

	//Reset other because we doenst want >> to append but to clear
	other.size = 0;
	return buff >> other;
}

void StringPiece::checkIfIndexIsValid(size_t index) const {
	if (index + 1 > this->size || index < 0) {
		throw out_of_range("Index of range!");
	}
}

void StringPiece::nullify() {
	this->size = 0;
	this->start = 0;
	this->end = 0;
}
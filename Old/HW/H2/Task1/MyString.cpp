#include "MyString.h"

MyString::MyString(size_t capacity)
{
	_length = capacity - 1;
	if (_length > STR_SIZE) {
		_dynamicArray = new char[capacity];
		_isDynamic = true;
	}
	else {
		_fixedArray;
		_isDynamic = false;
	}
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs._length + rhs._length + 1);

	if (result._isDynamic) {
		result[0] = '\0';
		strcat(result._dynamicArray, lhs.c_str());
		strcat(result._dynamicArray, rhs.c_str());
	}
	else {
		result[0] = '\0';
		strcat(result._fixedArray, lhs.c_str());
		strcat(result._fixedArray, rhs.c_str());
	}

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[(_length += other._length) + 1];
	result[0] = '\0';
	strcat(result, this->c_str());
	strcat(result, other.c_str());

	//len is dynamic
	if (_length > STR_SIZE) {
		delete[] _dynamicArray;
		_dynamicArray = result;
		_isDynamic = true;
	}
	else {
		strcpy(_fixedArray, result);
		_isDynamic = false;
	}

	return *this;
}

MyString::MyString() : MyString(1)
{
	_fixedArray[0] = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	if (_isDynamic) {
		strcpy(_dynamicArray, data);
	}
	else {
		strcpy(_fixedArray, data);
	}
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
	if (_isDynamic) {
		delete[] _dynamicArray;
		_dynamicArray = nullptr;
	}
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return _length;
}

void MyString::copyFrom(const MyString& other)
{
	_length = other._length;
	_isDynamic = other._isDynamic;

	if (other._isDynamic) {
		_dynamicArray = new char[_length + 1];
		strcpy(_dynamicArray, other.c_str());
		_isDynamic = true;
	}
	else {
		strcpy(_fixedArray, other.c_str());
		_isDynamic = false;
	}
}

MyString::MyString(MyString&& other)
{
	_length = other._length;
	_isDynamic = other._isDynamic;

	if (other._isDynamic) {
		_dynamicArray = other._dynamicArray;
		other._dynamicArray = nullptr;
	}
	else {
		strcpy(_fixedArray, other._fixedArray);
	}
}

MyString& MyString::operator=(MyString&& other)
{
	if (this != &other)
	{
		free();
		_length = other._length;
		_isDynamic = other._isDynamic;

		if (other._isDynamic) {
			_dynamicArray = other._dynamicArray;
			other._dynamicArray = nullptr;
		}
		else {
			strcpy(_fixedArray, other._fixedArray);
		}
	}
	return *this;
}

char& MyString::operator[](size_t index)
{
	if (_isDynamic) {
		return _dynamicArray[index];
	}
	else {
		return _fixedArray[index];
	}
}

char MyString::operator[](size_t index) const
{
	if (_isDynamic) {
		return _dynamicArray[index];
	}
	else {
		return _fixedArray[index];
	}
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > _length)
		throw std::length_error("Error, Substr out of range");


	MyString res(howMany + 1);
	for (int i = 0; i < howMany; i++)
		if (res._isDynamic) {
			res._dynamicArray[i] = _dynamicArray[begin + i];
		}
		else {
			res._fixedArray[i] = _fixedArray[begin + i];
		}
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
	if (_isDynamic) {
		return _dynamicArray;
	}
	else {
		char* res = new char[_length + 1];

		for (size_t i = 0; i < this->_length; i++) {
			res[i] = this->_fixedArray[i];
		}
		res[this->_length] = '\0';

		return res;
	}
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff;

	str._length = strlen(buff);
		
	if (str._length > STR_SIZE) {
		delete[] str._dynamicArray;
		str._dynamicArray = new char[str._length + 1];
		strcpy(str._dynamicArray, buff);
		str._isDynamic = true;
	}
	else {
		strcpy(str._fixedArray, buff);
		str._isDynamic = false;
	}

	return is;
}


bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
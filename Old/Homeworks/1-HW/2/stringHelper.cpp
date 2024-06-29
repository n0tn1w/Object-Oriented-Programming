#include "stringHelper.h"

int indexOfFirstChar(const char* row, int from) {
	int index = from;

	while (row[index] != '\0') {
		if (isCurrCharFromWord(row[index]))
		{
			return index;
		}
		index++;
	}

	return -1;
}

int indexOfLastChar(const char* row, int from) {
	int index = from;

	if (from == -1) {
		return -1;
	}

	while (row[index] != '\0') {
		if (!isCurrCharFromWord(row[index]))
		{
			return index - 1;
		}
		index++;
	}

	return index-1;

}


bool isCurrCharFromWord(const char& c) {
	if (c == '\t' || c == ' ' || c == '|') {
		return false;
	}
	return true;
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { 
		size++;
	}

	return size;
}

char* subStr(const char* str, int from, int to) {
	int resultSize = to - from + 2;
	char* result = new char[resultSize];

	int length = strLength(str);
	if (from > to || to >= length)
	{
		return result;
	}

	for (size_t i = 0; i < resultSize - 1; i++)
	{
		result[i] = str[from + i];
	}

	result[resultSize - 1] = '\0';

	return result;
}

void strcopy(char* destination, const char* source) {
	size_t i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

bool strCmp(const char* left, const char* rigth) {
	if (strLength(left) != strLength(rigth)) {
		return false;
	}

	for (int i = 0; i < strLength(left); i++) {
		if (left[i] != rigth[i]) {
			return false;
		}
	}

	return true;
}

int convertToInt(const char* str) {

	int stringLength = strLength(str);
	if (stringLength < 1) {
		return 0;
	}

	int index = str[0] == '-' ? 1 : 0;

	int result = 0;
	for (; index < stringLength; index++) {
		result = result * 10 + (str[index] - '0');
	}

	return str[0] == '0' ? -result : result;

}

bool checkIfInt(const char* str) {
	int length = strLength(str);
	if (length < 1) {
		return false;
	}

	int index = str[0] == '-' ? 1 : 0;

	// input is "-"
	if (index == length) {
		return false;
	}

	for (; index < length; index++) {
		if (str[index] < '0' || str[index] > '9') {
			return false;
		}
	}

	return true;
}
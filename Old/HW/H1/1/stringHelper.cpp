#include "stringHelper.h"

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

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}

	return size;
}

bool compareStrings(const char* a, const char* b) {
	while (*a && *b && *a == *b) {
		++a;
		++b;
	}
	return *a < *b;
}
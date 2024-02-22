#include "stringHelper.h"

void strCopy(char* dest, const char* source)
{
	size_t index = 0;
	while (source[index] != '\0')
	{
		dest[index] = source[index];
		index++;
	}
	dest[index] = '\0';
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

const char* convertIntToStr(int num) {

	size_t numDigits = floor(log10(num)) + 1;
	//cout << numDigits<< endl;
	char* buffer = new char[numDigits + 1];

	int i = 0;
	bool isNegative = false;

	if (num < 0) {
		isNegative = true;
		//buffer[i] = '-';
		i++;
		num = -num;
	}

	do {
		buffer[i++] = num % 10 + '0';
		num /= 10;
	} while (num);

	// Reverse the string and exclude "-" if negative 
	for (size_t k = isNegative ? 1 : 0; k < numDigits / 2; k++) {
		char temp = buffer[k];
		buffer[k] = buffer[numDigits - k - 1];
		buffer[numDigits - k - 1] = temp;
	}

	buffer[numDigits] = '\0';
	// Use buffer as char*
	//cout << buffer;
	return buffer;
}
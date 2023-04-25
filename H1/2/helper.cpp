#include "helper.h"

void printInputCharacter() {
	cout << '>';
}
void printTableCharacter() {
	cout << '|';
}
void printNewline() {
	cout << '\n';
}

size_t extractColumnData(const char* row, char** currentRowValues) {
	size_t wordsCnt = 0;

	for (int i = 0; row[i] != '\0' || i >= strLength(row);) {

		int indexFirst = indexOfFirstChar(row, i);
		int indexLast = indexOfLastChar(row, indexFirst);

		if (indexFirst == -1 || indexLast == -1) {
			break;
		}
		char* word = subStr(row, indexFirst, indexLast);

		currentRowValues[wordsCnt] = word;
		wordsCnt++;

		i = indexLast + 1;

	}

	return wordsCnt;
}

size_t readCommand(char** cmds) {

	char input[INPUT_BUFFER_SIZE];
	cin.getline(input, INPUT_BUFFER_SIZE);

	input[strLength(input)] = '\0';
	size_t cmdsCnt = extractColumnData(input, cmds);

	return cmdsCnt;
}

void freeCommands(char** cmds, size_t cmdCnt) {
	for (int i = 0; i < cmdCnt; i++) {
		delete[] cmds[i];
	}
	delete[] cmds;
}

Field* convertCmdIntoFields(char** cmds, const size_t& cmdsCnt) {
	Field* fields = new Field[cmdsCnt];

	for(int i = 1; i < cmdsCnt; i++) {
		fields[i - 1];
		strcopy(fields[i -1 ].value, cmds[i]);
	}

	return fields;
}

int getOrder(char* str) {
	int indexOfFirst = -1;

	for (int i = 0; i < strLength(str); i++) {
		if (str[i] == ':') {
			if (indexOfFirst != -1) {
				return 3;
			}
			indexOfFirst = i;
		}
	
	}
	if (indexOfFirst == -1) {
		return 0;
	}


	if (str[indexOfFirst + 1] == '-') {
		return 1;
	}
	else {
		return 2;
	}
}

void printOrderFile(ofstream& file ,size_t lengthField, int order) {
	file << ' ';
	if (order == 0) {
		for (size_t k = 0; k < lengthField - 1; k++) {
			file << '-';
		}
	}
	else if (order == 1) {
		file << ':';
		for (size_t k = 0; k < lengthField - 2; k++) {
			file << '-';
		}
	}
	else if (order == 2) {
		for (size_t k = 0; k < lengthField - 2; k++) {
			file << '-';
		}
		file << ':';
	}
	else if (order == 3) {
		file << ':';
		for (size_t k = 0; k < lengthField - 4; k++) {
			file << '-';
		}
		file << ':';
	}
	file << ' ';
}

void printOrder(size_t lengthField, int order) {
	cout  << ' ';
	if (order == 0) {
		for (size_t k = 0; k < lengthField - 1; k++) {
			cout << '-';
		}
	}
	else if (order == 1) {
		cout << ':';
		for (size_t k = 0; k < lengthField - 2; k++) {
			cout << '-';
		}
	}
	else if (order == 2) {
		for (size_t k = 0; k < lengthField - 2; k++) {
			cout << '-';
		}
		cout << ':';
	}
	else if (order == 3) {
		cout << ':';
		for (size_t k = 0; k < lengthField - 4; k++) {
			cout << '-';
		}
		cout << ':';
	}
	cout << ' ';
}
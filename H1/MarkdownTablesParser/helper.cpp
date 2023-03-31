#include "helper.h"
#include "TableContainer.h"
#include "constants.h"
#include "stringHelper.h"
#include <iostream>
#include <fstream>

using namespace std;

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

bool readFile(const char* fileName, TableContainer& table) {
	ifstream file(fileName);

	if (!file.is_open()) {
		return false;
	}

	char fileBuffer[FIELDS_MAX_COUNT + 2][TABLE_ROW_LENGTH];
	//For the top 2 rows
	int len = 0;

	for (; !file.eof(); len++) {
		file.getline(fileBuffer[len], TABLE_ROW_LENGTH);
	}

	file.close();

	table.setColNumber(0);

	for (size_t i = 0; i < len; i++) {
		char** currentRowValues = new char*[COLUMN_MAX_COUNT];
		size_t wordsCnt = extractColumnData(fileBuffer[i], currentRowValues);

		if (i == 0) {
			//header
			for (size_t k = 0; k < wordsCnt; k++) {
				Column column;
				Field columnTitle;
				strcopy(columnTitle.value, currentRowValues[k]);

				column.setName(columnTitle);
				column.setFieldsNumber(0);

				table.addColumn(column);
			}

		} else if (i == 1) {
			for (size_t k = 0; k < wordsCnt; k++) {
				int order = getOrder(currentRowValues[k]);

				Column* cls = table.getColumns(k);
				cls->setOrder(order);
			}
		} else {
			//table data
			for (size_t k = 0; k < wordsCnt; k++) {
				Field tableField;
				strcopy(tableField.value, currentRowValues[k]);

				Column* cls = table.getColumns(k);
				cls->addField(tableField);
			}
		}

		for (int i = 0; i < wordsCnt; i++) {
			delete[] currentRowValues[i];
		}
		delete[] currentRowValues;

	}
	return true;
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
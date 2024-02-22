#include "fileUtilites.h"


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
		char** currentRowValues = new char* [COLUMN_MAX_COUNT];
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

		}
		else if (i == 1) {
			for (size_t k = 0; k < wordsCnt; k++) {
				int order = getOrder(currentRowValues[k]);

				table.getColumn(k).setOrder(order);
			}
		}
		else {
			//table data
			for (size_t k = 0; k < wordsCnt; k++) {
				Field tableField;
				strcopy(tableField.value, currentRowValues[k]);

				table.getColumn(k).addField(tableField);
			}
		}

		for (int i = 0; i < wordsCnt; i++) {
			delete[] currentRowValues[i];
		}
		delete[] currentRowValues;

	}
	return true;
}

bool saveFile(const char* fileName, TableContainer& table) {
	ofstream file(fileName);

	if (!file.is_open()) {
		return false;
	}

	size_t rowCnt = 0;
	if (table.getColNumber() > 0) {
		rowCnt = table.getColumn(0).getFieldsNumber();
	}
	else {
		return false;
	}
	file << "| ";
	for (size_t i = 0; i < table.getColNumber(); i++) {
		file << table.getColumn(i).getName().value;
		file << " |";
	}
	file << '\n';

	//print --- line
	file << "| ";
	for (size_t i = 0; i < table.getColNumber(); i++) {
		printOrderFile(file ,7, table.getColumn(i).getOrder());
		file << " |";
	}
	file << '\n';

	//print body
	for (size_t k = 0; k < rowCnt; k++) {
		file << "| ";
		for (size_t i = 0; i < table.getColNumber(); i++) {
			file << table.getColumn(i).getFieldRow(k).value;
			file << " |";
		}
		file << '\n';
	}
	file.close();

	return true;
}
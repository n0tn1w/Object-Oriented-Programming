#include "TableContainer.h"

void TableContainer::addColumn(const Column& column) {
	this->columns[colNumber] = column;
	setColNumber(getColNumber() + 1);
}

void TableContainer::setColNumber(const size_t colNumber) {
	this->colNumber = colNumber;
}

size_t TableContainer::getColNumber() const {
	return this->colNumber;
}

Column& TableContainer::getColumn(size_t i) {
	return this->columns[i];
}

bool TableContainer::changeColumnName(Field& from, Field& to) {
	size_t indexFrom = findColIndexByName(from);

	if (indexFrom == -1) {
		return false;
	}

	getColumn(indexFrom).setName(to);

	return true;
}

bool TableContainer::changeRow(int row, Field& colName, Field& to) {
	int index = findColIndexByName(colName);
	if (index == -1) {
		return false;
	}
	Column& cls = getColumn(findColIndexByName(colName));

	if(!cls.changeField(row - 1,to)) {
		return false;
	}
	return true;
}


size_t TableContainer::findColIndexByName(Field& name) {
	for(size_t i =0; i < getColNumber(); i++) {
		if(strCmp(getColumn(i).getName().value, name.value)) {
		
			getColumn(i).setName(name);
			return i;
		} 
	}
	return -1;
}

bool TableContainer::addRow(Field* fields, size_t cmdCnt) {

	for(size_t i = 0; i< getColNumber(); i++) {
		Column& cls = getColumn(i);
		if(!cls.addRow(cls.getFieldsNumber(), fields[i])) {
			return false;
		}
	}
	return true;
}

bool TableContainer::changeOneRow(Field& colName, Field& from, Field& to) {
	size_t index = findColIndexByName(colName);
	if (index == -1) {
		return false;
	}

	Column& cls = getColumn(index);
	if (cls.replaceField(from, to)) {
		return true;
	}
	return false;
}

bool TableContainer::selectWhere(Field& colName, Field& fieldName) {
	size_t index = findColIndexByName(colName);
	if (index == -1) {
		return false;
	}
	if (!checkIfFieldExistsInACol(fieldName, index)) {
		return false;
	}

	printSelect(fieldName, index);
}

bool TableContainer::checkIfFieldExistsInACol(Field& fieldName, size_t index) {
	Column& cls = getColumn(index);
	for (size_t k = 0; k < cls.getFieldsNumber(); k++) {
		if (strCmp(cls.getFieldRow(k).value, fieldName.value)) {
			return true;
		}
	}
	return false;
}

void TableContainer::printSelect(Field& fieldName, size_t index) {

	size_t lengthField = getLongestFieldLength() + 2;
	if (lengthField % 2 == 1) {
		lengthField++;
	}

	size_t rowCnt = 0;
	if (getColNumber() > 0) {
		rowCnt = getColumn(0).getFieldsNumber();
	}
	else {
		return;
	}

	printTableHeader(lengthField);

	//print body
	for (size_t k = 0; k < rowCnt; k++) {
		Column& cls = getColumn(index);
		if (strCmp(cls.getFieldRow(k).value, fieldName.value)) {
			printTableCharacter();
			for (size_t i = 0; i < getColNumber(); i++) {
				pritnFieldWithLength(getColumn(i).getFieldRow(k), lengthField, getColumn(i).getOrder());
				printTableCharacter();
			}
			printNewline();
		}
	}

}


void TableContainer::print() {
	size_t lengthField = getLongestFieldLength() + 2;
	if (lengthField % 2 == 1) {
		lengthField++;
	}

	size_t rowCnt = 0;
	if (getColNumber() > 0) {
		Column& colums = getColumn(0);
		rowCnt = columns[0].getFieldsNumber();
	}
	else {
		return;
	}
	printTableHeader(lengthField);
	//print body
	for (size_t k = 0; k < rowCnt; k++) {
		printTableCharacter();
		for (size_t i = 0; i < getColNumber(); i++) {
			Column& cls = getColumn(i);
			pritnFieldWithLength(cls.getFieldRow(k), lengthField, cls.getOrder());
			printTableCharacter();
		}
		printNewline();
	}

}

void TableContainer::printTableHeader(size_t lengthField) {
	//print header
	printTableCharacter();
	for (size_t i = 0; i < getColNumber(); i++) {
		pritnFieldWithLength(getColumn(i).getName(), lengthField, getColumn(i).getOrder());
		printTableCharacter();
	}
	printNewline();

	//print --- line
	printTableCharacter();
	for (size_t i = 0; i < getColNumber(); i++) {
		printOrder(lengthField, getColumn(i).getOrder());
		printTableCharacter();
	}
	printNewline();
}

void TableContainer::pritnFieldWithLength(Field& field, const size_t& totalLen, int order) {
	if (order == 0 || order == 1) {
		cout << " " << field.value;
		for (size_t i = 0; i < totalLen - strLength(field.value); i++) {
			cout << " ";
		}
	}
	else if (order == 3) {
		size_t padding = totalLen - strLength(field.value);
		for (size_t i = 0; i < padding/2; i++) {
			cout << " ";
		}
		cout << field.value;
		int value = padding % 2 == 0 ? padding / 2 : (padding / 2) + 1;
		for (size_t i = 0; i < value; i++) {
			cout << " ";
		}

	}
	else if (order == 2) {
		for (size_t i = 0; i < totalLen - strLength(field.value); i++) {
			cout << " ";
		}
		cout << field.value << " ";
	}
}

size_t TableContainer::getLongestFieldLength() {
	size_t len = 0;
	for (size_t i = 0; i < getColNumber(); i++) {
		Column& cls = getColumn(i);
		size_t crr = cls.getLongestFieldLength();
		if (crr > len) {
			len = crr;
		}
	}
	return len;
}
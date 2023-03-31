#include "Column.h"
#include "stringHelper.h"
#include <iostream>

Field& Column::getName() {
	return this->name;
}

void Column::setName(Field& name) {
	this->name = name;
}

void Column::addField(Field& field) {
	this->fields[fieldsNumber] = field;
	setFieldsNumber(getFieldsNumber() + 1);
}

void Column::setFieldsNumber(const size_t fieldsNumber) {
	this->fieldsNumber = fieldsNumber;
}

size_t Column::getFieldsNumber() const {
	return this->fieldsNumber;
}

Field* Column::getFieldRow(const size_t row) {
	return &this->fields[row];
}

bool Column::changeField(int row, Field& field) {
	std::cout << row << " " << getFieldsNumber() << std::endl;
	if (row >= getFieldsNumber() || row <= 0) {
		return false;
	}

	Field* crr = getFieldRow(row);
	strcopy(crr->value, field.value);

	return true;
}

bool Column::addRow(size_t row, Field& field) {
	if(row != getFieldsNumber()) {
		return false;
	}
	setFieldsNumber(getFieldsNumber() + 1);

	Field* crr = getFieldRow(row);
	strcopy(crr->value, field.value);

	return true;
}

bool Column::replaceField(Field& from, Field& to) {

	for (size_t i = 0; i < getFieldsNumber(); i++) {
		Field* crr = getFieldRow(i);
		if (strCmp(crr->value, from.value)) {
			strcopy(crr->value, to.value);
			return true;
		}

	}
	return false;
	
}

void Column::print() {
	//cout << "gelo";
}

size_t Column::getLongestFieldLength() {
	size_t len = 0;

	for (size_t i = 0; i < getFieldsNumber(); i++) {
		Field* crr = getFieldRow(i);
		size_t crrLen = strLength(crr->value);
		if (crrLen > len) {
			len = crrLen;
		}
	}

	size_t titleLen = strLength(getName().value);
	if (titleLen > len) {
		len = titleLen;
	}

	return len;
};

void Column::setOrder(int order) {
	this->order = order;
}

int Column::getOrder() const {
	return this->order;
}
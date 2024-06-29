#pragma once
#include "Column.h"
#include "constants.h"
#include "helper.h"
#include "stringHelper.h"
#include <iostream>

using namespace std;

class TableContainer {

	size_t colNumber;
	Column columns[COLUMN_MAX_COUNT];

public:
	TableContainer() = default;

	void addColumn(const Column&);

	Column& getColumn(size_t i);

	void setColNumber(const size_t);
	size_t getColNumber() const;

	bool changeColumnName(Field&, Field&);

	bool changeRow(int, Field&, Field&);

	bool addRow(Field*, size_t);

	bool changeOneRow(Field& colName, Field& from, Field& to);

	void print();
	void printSelect(Field&, size_t);
	bool selectWhere(Field&, Field&);

private:
	void printTableHeader(size_t);

	size_t findColIndexByName(Field&);

	size_t getLongestFieldLength();
	
	void pritnFieldWithLength(Field&, const size_t&, int);

	bool checkIfFieldExistsInACol(Field&, size_t);
};
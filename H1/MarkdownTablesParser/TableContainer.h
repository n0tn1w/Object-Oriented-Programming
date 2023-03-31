#pragma once
#include "Column.h"
#include "constants.h"

class TableContainer {

	size_t colNumber;
	Column columns[COLUMN_MAX_COUNT];

public:
	TableContainer() = default;

	void addColumn(const Column&);

	Column* getColumns(size_t i);

	void setColNumber(const size_t);
	size_t getColNumber() const;

	bool changeColumnName(Field&, Field&);

	bool changeRow(int, Field&, Field&);

	bool addRow(Field*, size_t);

	bool changeOneRow(Field& colName, Field& from, Field& to);

	void print();
	void print2(Field&, size_t);
	bool selectWhere(Field&, Field&);

private:
	size_t findColIndexByName(Field&);

	size_t getLongestFieldLength();
	
	void pritnFieldWithLength(Field*, const size_t&, int);
	void printOrder(size_t, int);

	bool checkIfFieldExistsInACol(Field&, size_t);
};
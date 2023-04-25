#pragma once
#include "constants.h"
#include "Field.h"
#include "stringHelper.h"
#include <iostream>

class Column {

	Field name;

	size_t fieldsNumber;
	Field fields[FIELDS_MAX_COUNT];

	int order;
	//0 default ( --- )
	//1 left	( :-- )
	//2 mid		( :-: )
	//3 right	( --: )

public:
	Column() = default;

	Field& getName();
	void setName(Field&);

	
	size_t getFieldsNumber() const;
	void setFieldsNumber(const size_t);

	int getOrder() const;
	void setOrder(int);

	Field& getFieldRow(const size_t);

	void addField(Field&);
	bool changeField(const int, Field&);
	bool addRow(size_t, Field&);
	bool replaceField(Field&, Field&);

	size_t getLongestFieldLength();

};
#pragma once
#include "constants.h"
#include "Field.h"

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

	void addField(Field&);

	void setFieldsNumber(const size_t);
	size_t getFieldsNumber() const;

	void setOrder(int);
	int getOrder() const;

	bool changeField(const int, Field&);
	Field* getFieldRow(const size_t); 

	bool addRow(size_t, Field&);

	bool replaceField(Field&, Field&);

	void print();

	size_t getLongestFieldLength();

};
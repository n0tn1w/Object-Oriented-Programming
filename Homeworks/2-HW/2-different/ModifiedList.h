#pragma once
#include <fstream>
#include "HelpingFunctions.h"


//can resize to be reusable
class ModifiedList {
private:
	size_t capacity;
	size_t size;
	//emulates map(thought of making them a struct too late)
	int16_t *xvalues;
	int16_t *results;

	void copy(const ModifiedList&);
	void free();
	void resize(size_t);
public:
	ModifiedList();
	ModifiedList(const ModifiedList&);
	ModifiedList& operator=(const ModifiedList&);
	~ModifiedList();

	void add(int16_t, int16_t);

	void change(int16_t, int16_t);

	bool isNumberPresent(int16_t) const;

	size_t getSize() const;
	//I don't redefine [] becasue I have two arrays
	int16_t getResult(int16_t) const;
	
	int16_t getRsultByIndex(size_t) const;

	void setResultByIndex(size_t, int16_t);

	size_t getIndexOfValue(int16_t) const;

	int16_t getXvalueByIndex(size_t) const;

	void setXvalueByIndex(size_t, int16_t);

	void serealize(std::ofstream&) const;
	void deserealize(std::ifstream&);

	friend ModifiedList operator+(const ModifiedList&, const ModifiedList&);

	friend ModifiedList operator-(const ModifiedList&, const ModifiedList&);

};
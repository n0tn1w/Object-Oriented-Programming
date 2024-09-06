#include "ModifiedList.h"
#include <iostream>//REMOVE

void ModifiedList::copy(const ModifiedList& other)
{
	size = other.size;
	capacity = other.capacity;
	xvalues = new int16_t[capacity];
	results = new int16_t[capacity];
	for (size_t i = 0; i < size; i++) {
		xvalues[i] = other.xvalues[i];
		results[i] = other.results[i];
	}
}

void ModifiedList::free()
{
	delete[] xvalues;
	delete[] results;
	xvalues = results = nullptr;
	size = capacity = 0;
}

void ModifiedList::resize(size_t lengthToFit)
{
	capacity = size < 16 ? 15 : getNextPowerOfTwo(lengthToFit + 1) - 1;
	//std::cout << "new capacity " << capacity << '\n';
	int16_t* newXvalues = new int16_t[capacity];
	copyShortArray(newXvalues, xvalues, size);
	delete[] xvalues;
	xvalues = newXvalues;

	int16_t* newResults = new int16_t[capacity];
	copyShortArray(newResults, results, size);
	delete[] results;
	results = newResults;
}

ModifiedList::ModifiedList(): size(0)
{
	capacity = (INT16_MAX + INT16_MIN * (-1)) + 1;
	xvalues = new int16_t[capacity];
	results = new int16_t[capacity];
}

ModifiedList::ModifiedList(const ModifiedList& other)
{
	copy(other);
}

ModifiedList& ModifiedList::operator=(const ModifiedList& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

ModifiedList::~ModifiedList()
{
	free();
}

void ModifiedList::add(int16_t newVal, int16_t newRes)
{
	//std::cout << size << "\n";//REMOVE
	/*if (size > capacity) {
		resize(size+1);
	}*/
	xvalues[size] = newVal;
	results[size] = newRes;
	size++;
}

void ModifiedList::change(int16_t xVal, int16_t newVal)
{
	size_t index = getIndexOfValue(xVal);
	/*for (size_t i = 0; i < size; i++) {
		if (xVal == xvalues[i]) {
			index = i;
			break;
		}
	}*/
	results[index] = newVal;
}

bool ModifiedList::isNumberPresent(int16_t val) const
{
	for (size_t i = 0; i < size; i++) {
		if (val == xvalues[i]) {
			return true;
		}
	}
	return false;
}

size_t ModifiedList::getSize() const
{
	return size;
}

int16_t ModifiedList::getResult(int16_t val) const
{
	size_t index = getIndexOfValue(val);
	return results[index];
}

int16_t ModifiedList::getRsultByIndex(size_t index) const
{
	return results[index];
}

void ModifiedList::setResultByIndex(size_t index, int16_t result)
{
	results[index] = result;
}

size_t ModifiedList::getIndexOfValue(int16_t val) const
{
	for (size_t i = 0; i < size; i++) {
		if (val == xvalues[i]) {
			return i;
		}
	}
	//std::cout << "val " << val;
	throw  "Number not found";//deal with these throws at some point? maybe?
}

int16_t ModifiedList::getXvalueByIndex(size_t index) const
{
	return xvalues[index];
}

void ModifiedList::setXvalueByIndex(size_t index, int16_t xval)
{
	xvalues[index] = xval;
}

void ModifiedList::serealize(std::ofstream& ofs) const
{
	ofs.write((const char*)size, sizeof(size));
	ofs.write((const char*)capacity, sizeof(capacity));
	ofs.write((const char*)xvalues, capacity * sizeof(int16_t));
	ofs.write((const char*)results, capacity * sizeof(int16_t));
}

void ModifiedList::deserealize(std::ifstream& ifs)
{
	ifs.read((char*)size, sizeof(size));
	ifs.read((char*)capacity, sizeof(capacity));
	//make sure it is empty before using
	if (xvalues) {
		delete[] xvalues;
	}
	xvalues = new int16_t[capacity];
	if (results) {
		delete[] results;
	}
	results = new int16_t[capacity];
	ifs.read((char*)xvalues, capacity * sizeof(int16_t));
	ifs.read((char*)results, capacity * sizeof(int16_t));
}

ModifiedList operator+(const ModifiedList& lhs, const ModifiedList& rhs)
{
	ModifiedList result;
	//we assume they have the same size as this is how they will be used. They are allso ordered the same
	for (size_t i = 0; i < lhs.size; i++) {
		result.add(lhs.xvalues[i], lhs.results[i]+rhs.results[i]);
	}
	return result;
}

ModifiedList operator-(const ModifiedList& lhs, const ModifiedList& rhs)
{
	ModifiedList result;
	//we assume they have the same size as this is how they will be used. They are allso ordered the same
	for (size_t i = 0; i < lhs.size; i++) {
		result.add(lhs.xvalues[i], lhs.results[i] - rhs.results[i]);
	}
	return result;
}

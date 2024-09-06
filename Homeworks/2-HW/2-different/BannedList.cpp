#include "BannedList.h"

void BannedList::free() {
	delete[] values;
	values = nullptr;
	size = capacity = 0;
}

void BannedList::resize(size_t lengthToFit)
{
	capacity = size < 16 ? 15 : getNextPowerOfTwo(lengthToFit + 1) - 1;

	int16_t* newValues = new int16_t[capacity];
	copyShortArray(newValues, values, size);
	delete[] values;
	values = newValues;
}

void BannedList::copy(const BannedList& other)
{
	size = other.size;
	capacity = other.capacity;
	values = new int16_t[capacity];
	for (size_t i = 0; i < size; i++) {
		values[i] = other.values[i];
	}
}

BannedList::BannedList(): size(0), capacity(8)
{
	values = new int16_t[capacity];
}

BannedList::BannedList(const BannedList& other)
{
	copy(other);
}

BannedList& BannedList::operator=(const BannedList& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

BannedList::~BannedList()
{
	free();
}

void BannedList::add(int16_t value)
{
	if (isBanned(value)) {
		return;
	}
	if (size >= capacity) {
		resize(size+1);
	}
	values[size] = value;
	size++;
}

size_t BannedList::getSize() const
{
	return size;
}

int16_t BannedList::getValue(size_t index) const
{
	return values[index];
}

bool BannedList::isBanned(int16_t val) const
{
	for (size_t i = 0; i < size; i++) {
		if (val == values[i]) {
			return true;
		}
	}
	return false;
}

bool BannedList::isEmpty() const
{
	return size == 0;
}

void BannedList::serealize(std::ofstream& ofs) const
{
	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)&capacity, sizeof(capacity));
	ofs.write((const char*)values, sizeof(int16_t) * capacity);
}

void BannedList::deserealize(std::ifstream& ifs)
{
	ifs.read((char*)size, sizeof(size));
	ifs.read((char*)capacity, sizeof(capacity));
	//make sure it is empty before using
	if (values) {
		delete[] values;
	}
	values = new int16_t[capacity];
	ifs.read((char*)values, sizeof(values));
}

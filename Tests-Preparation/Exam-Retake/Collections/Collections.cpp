#include "Sets.h"
#include <cstring>

DynamicCollection::DynamicCollection() {
	_size = 0;
	_capacity = 8;
	_data = new int[_capacity];
}
DynamicCollection::DynamicCollection(int size) {
	_size = size;
	_capacity = size;
	_data = new int[_capacity] {0};
}

void DynamicCollection::resize() {
	_capacity *= 2;
	int* newData = new int[_capacity];
	for (size_t i = 0; i < _size; i++) {
		newData[i] = _data[i];
	}
	delete[] _data;
	_data = newData;
}

FiniteCollection::FiniteCollection() : DynamicCollection() {}
FiniteCollection::FiniteCollection(int size) : DynamicCollection(size) {}

NormalCollection::NormalCollection() : InfiniteCollection() { }

void NormalCollection::add(int i) {
	if (_size == _capacity)
		resize();
	
	_data[_size++] = i;
}
bool NormalCollection::remove(int i) {
	for (size_t i = 0; i < _size; i++) {
		if (_data[i] == i) {
			_data[i] = _data[_size--];
			return true;
		}
	}
	return false;
}
size_t NormalCollection::count(int i) const {
	size_t cnt = 0;
	for (size_t i = 0; i < _size; i++) {
		if (_data[i] == i) {
			cnt++;
		}
	}
	return cnt;
}
bool NormalCollection::contains(int i) const {
	for (size_t i = 0; i < _size; i++) {
		if (_data[i] == i) {
			return true;
		}
	}

	return false;
}

Collection* NormalCollection::clone() const {
	return new NormalCollection(*this);
}

SortedCollection::SortedCollection() : InfiniteCollection() {}

int SortedCollection::lowerBound(int n) const {
	int left = 0;
	int right = _size - 1;
	int indexToReturn = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (_data[mid] == n) {
			indexToReturn = mid;
			right = mid - 1;
		}
		else if (_data[mid] < n) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return indexToReturn;
}

int SortedCollection::upperBound(int n) const {
	int left = 0;
	int right = _size - 1;
	int indexToReturn = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (_data[mid] == n) {
			indexToReturn == mid;
			left = mid + 1;
		}
		else if (_data[mid] > n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int n) {
	if (_size == _capacity) {
		resize();
	}

	int index = _size;

	while (index != 0 && _data[index - 1] > n) {
		_data[index] = _data[index - 1];
		index--;
	}

	_data[index] = n;
	_size++;
}

bool SortedCollection::remove(int n) {
	int index = lowerBound(n);
	if (index == -1) {
		return false;
	}

	for (size_t i = index; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	--_size;
	return true;
}

size_t SortedCollection::count(int n) const {
	int leftIndex = lowerBound(n);
	if (leftIndex == -1) {
		return 0;
	}

	int rightIndex = upperBound(n);
	return rightIndex - leftIndex + 1;
}

bool SortedCollection::contains(int n) const {
	return lowerBound(n) != -1;
}

Collection* SortedCollection::clone() const {
	return new SortedCollection(*this);
}

IntervalCollection::IntervalCollection(int a, int b) : FiniteCollection(b-a), a(a), b(b) { }

void IntervalCollection::add(int i) {
	if (i > b || a > i) {
		return;
	}
	_data[i - a]++;
}

bool IntervalCollection::remove(int i) {
	if (i > b || a > i) {
		return false;
	}

	if (_data[i - a] == 0) {
		return false;
	}
	else {
		_data[i - a]--;
		return true;
	}
}

size_t IntervalCollection::count(int i) const {
	if (i > b || a > i) {
		return false;
	}

	return _data[i - a];
}

bool IntervalCollection::contains(int i) const {
	if (i > b || a > i) {
		return false;
	}

	return _data[i - a] > 0;
}

Collection* IntervalCollection::clone() const {
	return new IntervalCollection(*this);
}

Set::Set(int s) {
	if (s == 0) {
		_collection = new SortedCollection();
	}
	else if(s == 1) {
		_collection = new NormalCollection();

	}
}

Collection* Set::clone() const {
	return new Set(*this);
}

void Set::add(int i) {
	if (!_collection->contains(i))
		_collection->add(i);
}

bool Set::remove(int i) {
	return _collection->remove(i);
}
size_t Set::count(int i) const {
	return _collection->count(i);
}
bool Set::contains(int i) const {
	return _collection->contains(i);
}

Set::~Set() {
	delete _collection;
}
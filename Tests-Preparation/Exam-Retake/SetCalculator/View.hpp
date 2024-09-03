#pragma once

template <class T>
class View {

public:

	View(const T* begin, size_t size) {
		_begin = begin;
		_size = size;
	}

	View(const char* begin) {
		_begin = begin;
		_size = strlen(begin);
	}

	View<T> substr(size_t indexBegin, size_t size) {
		return View<T>(_begin + indexBegin, size);
	}

	size_t getSize() const {
		return _size;
	}

	const T& operator[](size_t ind) const {
		return _begin[ind];
	}

private:
	const T* _begin;
	size_t _size;
};
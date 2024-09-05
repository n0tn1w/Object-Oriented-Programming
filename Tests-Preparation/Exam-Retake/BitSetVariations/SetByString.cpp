#pragma once

#include "sstream"
#include "Bitset.cpp"

class SetByString : public Bitset{

	char* _str;

	void map() {
		Bitset::reset();
		std::stringstream ss(_str);

		while (true) {
			size_t n;
			ss >> n;
			Bitset::add(n);

			if (ss.eof())
				break;
		}
	}

public:
	SetByString(size_t n, const char* str) : Bitset(n) {
		size_t len = strlen(str);
		_str = new char[len + 1];
		strcpy_s(_str, len + 1, str);
		map();

	}
	// Big 6
	~SetByString() {
		delete[] _str;
	}

	void setAt(size_t idx, char n) {
		_str[idx] = n;
		map();
	}

	void print() const {
		Bitset::print();
	}

};
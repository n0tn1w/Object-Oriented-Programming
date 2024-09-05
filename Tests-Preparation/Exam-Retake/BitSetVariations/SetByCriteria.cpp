#include "Bitset.cpp"

typedef bool(*fPtr)(int);

class SetByCriteria : public Bitset {
	
	fPtr _f, _s;

	void map() {
		for (size_t i = 1; i < _size; i++) {
			if (_f(i) && !_s(i)) {
				Bitset::add(i);
			}
		}
	}

public:

	SetByCriteria(size_t n, fPtr f, fPtr s) : Bitset(n) {
		_f = f;
		_s = s;

		map();
	}

	void print() const {
		Bitset::print();
	}
};
#pragma once
#include <iostream>
using std::cout;

class SigmaAlgebra {
public:
	
	void setAt(char ch, bool val) {
		_algebra[ch - 'A'] = val;
	}
	
	bool getAt(char ch) const {
		return _algebra[ch - 'A'];
	}

	const char* getData() const {
		return _algebra;
	}

	friend SigmaAlgebra compliment(const SigmaAlgebra& el) {
		SigmaAlgebra sa;

		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			sa.setAt(let, !el.getAt(let));
		}

		return sa;
	}

	friend SigmaAlgebra operator+(const SigmaAlgebra& l, const SigmaAlgebra& r) {
		SigmaAlgebra sa;
		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			sa.setAt(let, l.getAt(let) || r.getAt(let));
		}

		return sa;
	}

	friend SigmaAlgebra intersect(const SigmaAlgebra& l, const SigmaAlgebra& r) {
		SigmaAlgebra sa;
		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			sa.setAt(let, l.getAt(let) && r.getAt(let));
		}

		return sa;
	}

	friend SigmaAlgebra operator/(const SigmaAlgebra& l, const SigmaAlgebra& r) {
		SigmaAlgebra sa = l;
		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			if (r.getAt(let)) {
				sa.setAt(let, false);
			}
		}

		return sa;
	}

	friend bool operator==(const SigmaAlgebra& l, const SigmaAlgebra& r) {
		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			if (l.getAt(let) != r.getAt(let) ){
				return false;
			}
		}

		return true;
	}

	bool isElementIn(const SigmaAlgebra& sa) {
		for (int i = 0; i < 26; i++) {
			char let = i + 'A';
			if (sa.getAt(let) && !getAt(let)) {
				return false;
			}
		}

		return true;
	}

	void print() const {
		for (int i = 0; i < 26; i++) {
			cout << (_algebra[i] ? 't' : 'f') << ' ';
		}
	}

private:

	char _algebra[26]{ false };

};

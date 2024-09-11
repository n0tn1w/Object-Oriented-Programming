#include <iostream>
#include <algorithm>
using namespace std;

// Collecting numbers from [0 ... 31] from 0 to 3 times
class TinyMultiset {

	// We need only this variable to store the values because
	// 0 to 3 times can be stored with only 2bites
	//bits- number that represent
	// 00 - 0
	// 01 - 1
	// 10 - 2
	// 11 - 3
	const size_t NUMBER_OF_BITS_NEEDED_TO_REPRESNET_A = 2;
	const size_t MIN_NUMBER_STORED = 0;
	const size_t MAX_NUMBER_STORED = 31;


	uint64_t _data = 0; // uint8_t _data[8] is valid

	size_t getBitIndex(int i) const {
		return i * NUMBER_OF_BITS_NEEDED_TO_REPRESNET_A;
	}

	bool isValid(int i) const {
		return i >= MIN_NUMBER_STORED && i <= MAX_NUMBER_STORED;
	}

	size_t count(int i) const {

		size_t bitIdx = getBitIndex(i);
		uint64_t mask = 0;

		mask += ((1 << bitIdx) + (1 << bitIdx + 1));
		mask &= _data;
		mask >>= bitIdx;

		return mask;
	}

	void setTo(size_t idx, int value) {
		size_t bitIdx = getBitIndex(idx);
		uint64_t mask = INT64_MAX;

		uint64_t f = value / 2;
		uint64_t s = value % 2;

		// _data = 10 01 [10] 00
		mask -= ((1 << bitIdx) +  (1 << bitIdx + 1)); 
		// mask = 11 11 [00] 11
 		_data &= mask;
		// _data = 10 01 [00] 11

		mask = 0;
		mask += ((f << bitIdx + 1) + (s << bitIdx));
		// mask = 00 00 [11] 00
		_data |= mask;
		// _data = 10 01 [11] 11

	}

public:

	void add(int i) {
		if (!isValid(i)) {
			return;
		}

		int cnt = count(i);
		cnt++;
		if (cnt > 3) {
			return;
		}
		//cout << "@" << cnt << endl;
		setTo(i, cnt);
	}
	
	void remove(int i) {
		if (!isValid(i)) {
			return;
		}

		int cnt = count(i);
		cnt--;
		if (cnt < 0) { 
			return;
		}

		setTo(i, cnt);
	}

	int operator()(int i) const {
		return count(i);
	}

};


template <class T, class V>
class MultisetIntersection {
	// Aggregation
	// Outside changes to the obejcts will be shown in the class
	const T* _multiset1;
	const V* _multiset2;

public:

	// Only 1 constructor that accepts const T* and const V*
	MultisetIntersection(const T* m1, const V* m2) {
		setMultiset1(m1);
		setMultiset2(m2);
	}

	void setMultiset1(const T* m1) {
		_multiset1 = m1;
	}

	void setMultiset2(const V* m2) {
		_multiset2 = m2;
	}

	int operator()(int i) const {
		if (_multiset1 != nullptr && _multiset2 != nullptr) {
			return std::min(_multiset1->operator()(i), _multiset2->operator()(i));
		}
		throw std::runtime_error("A multiset is nullptr!");
	}
};

int main() {

	TinyMultiset a;
	cout << a(1);
	a.add(1);
	cout << a(1);
	a.add(1);
	cout << a(1);
	a.add(1);
	cout << a(1);
	a.add(1);
	cout << a(1);
	a.add(1);
	cout << a(1);
	a.add(1);
	cout << a(1) << endl;
	a.add(2);

	TinyMultiset b;
	b.add(1);
	b.add(1);
	b.add(2);

	MultisetIntersection<TinyMultiset, TinyMultiset> mi(&a, &b);
	cout << mi(1) << endl;
	cout << mi(2);
}
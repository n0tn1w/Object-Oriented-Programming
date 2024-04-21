#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

namespace ConstMultiSet {
	const size_t BUCKET_SIZE = sizeof(uint8_t) * 8;
};

namespace HelperFunctionsMultiSet {
	int power(int, int);
};

class MultiSet {
		
	size_t _n = 0, _k = 0;
	uint8_t* _data = nullptr;
	size_t _bucketCount = 0;

	size_t getBucketCount() const;
	size_t getBucketIndex(size_t) const;
	size_t getBitIndex(size_t) const;
	void addMultiple(size_t, size_t);

	bool validateNumber(size_t) const;
	bool validateCountAddition(uint8_t) const;
	bool validateCountSubtraction(uint8_t) const;
	bool validateCountAdditionTwoNumbers(uint8_t, uint8_t) const;

	// Will make the counter of the number the correct value
	bool setCounter(size_t, uint8_t); 
public:

	MultiSet() = default;
	MultiSet(size_t, size_t);
	MultiSet(const MultiSet&);
	MultiSet(MultiSet&&) noexcept;
	MultiSet& operator=(const MultiSet&);
	MultiSet& operator=(MultiSet&&) noexcept;
	~MultiSet();

	uint8_t check(size_t) const;
	bool add(size_t);
	bool remove(size_t);
	void print() const;
	void printMemory() const;

	friend std::ifstream& operator>>(std::ifstream&, MultiSet&);
	friend std::ofstream& operator<<(std::ofstream&, const MultiSet&);

	friend MultiSet unification(const MultiSet&, const MultiSet&);
	friend MultiSet section(const MultiSet&, const MultiSet&);
	friend MultiSet addition(const MultiSet&);

private:

	void free();
	void copyFrom(const MultiSet&);	
	void moveFrom(MultiSet&&) noexcept;

};
#pragma once
#include <cstdint>
#include <vector>
#include <fstream>
#include <iostream>

typedef int16_t(*FuncPtr)(int16_t);

// MIF == ModifiableIntegersFunction
namespace ConstsMIF { 
	const int16_t MAX_VALUE = INT16_MAX;
	const int16_t MIN_VALUE = INT16_MIN;
	const size_t TOTAL_CAPACITY_RESULTS = MAX_VALUE - MIN_VALUE + 1;
	const size_t BUCKET_SIZE = sizeof(uint8_t) * 8;
	const size_t TOTAL_CAPACITY_REMOVED = TOTAL_CAPACITY_RESULTS / BUCKET_SIZE;
}; 

namespace ResultsOpreationsMIF {
	typedef int(*ResultOperation)(int16_t, int16_t);
	int add(int16_t, int16_t);
	int subtract(int16_t, int16_t);
};

struct Point {
	int x, y;
};

class ModifiableIntegersFunction {

	// These field are with dynamic memory because big data should be stored in the heap
	// Because the stack size is finite and a lot smaller than heap (in the most cases)
	// The memory for the stack is prepared on start of the program so with 15 _results the program wont load
	// On the other side if the memory is allocated in the heap the running the process will be slower but 
	// at least the program will load with more ModifiableIntegersFunction
	int16_t* _results = nullptr;
	uint8_t* _removed = nullptr;
	bool _isSet = false;

	void generateValues(FuncPtr);
	void setResultByNumber(int number, int16_t value);
	bool validateNumberInRange(int index) const;
	size_t getRemovedBucketIndex(int index) const;
	size_t getRemovedBitIndex(int index) const;

	void unifyRemoved(const ModifiableIntegersFunction&);
	bool validateOperation(int16_t, int16_t, ResultsOpreationsMIF::ResultOperation) const;

public:
	// Those are public because the < and |= cannot be friend functions!!!
	bool isRemoved(int index) const;
	int16_t getResultByNumber(int number) const;
	size_t getIndexByNumber(int index) const;

public:
	bool good() const;

	ModifiableIntegersFunction(); // So it could make arr out of it
	void setFunction(FuncPtr); // To populate the func in the aforementioned arr
	
	ModifiableIntegersFunction(FuncPtr);
	ModifiableIntegersFunction(const ModifiableIntegersFunction&);
	ModifiableIntegersFunction(ModifiableIntegersFunction&&) noexcept;
	ModifiableIntegersFunction& operator=(const ModifiableIntegersFunction&);
	ModifiableIntegersFunction& operator=(ModifiableIntegersFunction&&) noexcept;
	~ModifiableIntegersFunction();

	void presetResult(int index, int16_t value);
	void removeResult(int index);

	ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction&);
	ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction&);

	bool isInjection() const;
	bool isSurection() const;
	bool isBijection() const;

	friend std::ofstream& operator<<(std::ofstream&, const ModifiableIntegersFunction&);
	friend std::ifstream& operator>>(std::ifstream&, ModifiableIntegersFunction&);

	void draw(Point, Point) const;

private:
	void copyFrom(const ModifiableIntegersFunction&);
	void moveFrom(ModifiableIntegersFunction&&) noexcept;
	void free();
};

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
ModifiableIntegersFunction operator-(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);

bool operator<(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
bool operator|=(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction&, int);
#pragma once
#include "ModifiedList.h"
#include "BannedList.h"
#include <iostream>

namespace MIFConstants {
	constexpr int DRAW_MATRIX_SIZE = 20;//the instructions are vague it will be in -20 to 20 standart
}


class ModifiableIntegersFunction {
private:
	ModifiedList ml;
	BannedList bl;

	int16_t getKResult(int16_t) const;

public:
	ModifiableIntegersFunction() = default;

	ModifiableIntegersFunction(int16_t (*func)(int16_t));

	void adoptBannedList(const ModifiableIntegersFunction&);
	
	//adds a new entry
	void addToML(int16_t, int16_t);
	//modifies an exsiting f(x)
	void changeResult(int16_t, int16_t);

	void addToBL(int16_t);

	int16_t calculate(int16_t) const;
	
	size_t getMlSize() const;

	size_t getBlSize() const;

	int16_t getMlXvalueByIndex(size_t) const;

	int16_t getMlRsultByIndex(size_t) const;

	const ModifiedList& getML() const;

	void setML(const ModifiedList&);

	//this is how these are spelled in english
	bool isInjective() const;

	bool isSurjective() const;

	bool isBijective() const;

	bool isBanned(int16_t) const;
	
	void serialize(const char*) const;

	void deserialize(const char*);
	
	//takes in only one parameter the graph is nxn requirments were vaguensticking with this
	void drawFunction(int) const;

	ModifiableIntegersFunction operator^(int16_t) const;

	//generates the oposite function
	ModifiableIntegersFunction operator!() const;
};

 ModifiableIntegersFunction operator+(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
 ModifiableIntegersFunction operator-(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
//composition of functions goes here
 ModifiableIntegersFunction operator*(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);

 bool operator<(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
//paralelisim
 bool operator|(const ModifiableIntegersFunction&, const ModifiableIntegersFunction&);
#pragma once
#include "Set.h"
#include <iostream>
#include "Vector.hpp"

using namespace std;
//class Set;

class UnionSet : public Set {

	Vector<Set*> elms;

public:

	UnionSet(Vector<Set*>);
	bool contains(const int) const override;
	void printSet(const int a, const int b, const int mode) const override;

	~UnionSet();

};
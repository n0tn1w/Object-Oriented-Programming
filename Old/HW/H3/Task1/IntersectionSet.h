#pragma once
#include "Set.h"
#include <iostream>
#include "Vector.hpp"

using namespace std;
//class Set;

class IntersectionSet : public Set {

	Vector<Set*> elms;

public:

	IntersectionSet(Vector<Set*>);
	bool contains(const int) const override;
	void printSet(const int a, const int b, const int mode) const override;

	~IntersectionSet();
};

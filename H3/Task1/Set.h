#pragma once
#include "MyString.h"
#include <iostream>
#include <fstream>

using namespace std;

class Set {

public:
	virtual bool contains(const int) const = 0;
	virtual void printSet(const int a, const int b, const int mode) const  = 0;

	bool printOneMoreElement() const;

	virtual ~Set() = default;
};
#pragma once
#include "MyString.h"
#include "SetFactory.h"
#include <iostream>
#include <fstream>

using namespace std;

class Solver {
private:
	MyString fileName;

public:

	Solver(MyString& str);
	void run();


};
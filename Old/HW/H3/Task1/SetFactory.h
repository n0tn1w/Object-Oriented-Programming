#pragma once
#include "Set.h"
#include "CriteriaSet.h"
#include "IntersectionSet.h"
#include "UnionSet.h"
#include "MyString.h" 
#include "CriteriaFactory.h"
#include <iostream>

using namespace std;

Set* setFactory(const MyString& fileName);

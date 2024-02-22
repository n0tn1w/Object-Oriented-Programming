#pragma once
#include "Criteria.h"
#include "CriteriaDivisibleNone.h"
#include "CriteriaDivisibleOne.h"
#include "CriteriaFull.h"
#include "CriteriaDivisibleNone.h"
#include <iostream>
using namespace std;


Criteria* criteriaFactory(short, const int*, short);
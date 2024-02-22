#pragma once
#include "Set.h"
#include <iostream>
#include "Criteria.h"

using namespace std;

class CriteriaSet : public Set {
	Criteria* criteria;

public:
	CriteriaSet(Criteria*);
	bool contains(const int) const override;
	void printSet(const int a, const int b, const int mode) const override;

	~CriteriaSet();
};
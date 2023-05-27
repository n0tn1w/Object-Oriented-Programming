#pragma once
#include "Criteria.h"

class CriteriaDivisibleOne : public Criteria {

public:
	CriteriaDivisibleOne(const int*, short);
	bool contains(const int) const override;

};

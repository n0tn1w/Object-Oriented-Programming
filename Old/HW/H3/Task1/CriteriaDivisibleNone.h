#pragma once
#include "Criteria.h"

class CriteriaDivisibleNone : public Criteria {

public:
	CriteriaDivisibleNone(const int*, short);

	bool contains(const int) const override;
};

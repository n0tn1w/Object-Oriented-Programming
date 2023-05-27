#pragma once
#include "Criteria.h"

class CriteriaFull : public Criteria {

public:
	CriteriaFull(const int*, short);

	bool contains(const int) const override;
};
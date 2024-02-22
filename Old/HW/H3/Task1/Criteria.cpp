#include "Criteria.h"

Criteria::Criteria(const int* elms, short n)
{
	this->n = n;

	for (int i = 0; i < n; ++i) {
		   elements[i] = elms[i];
	}
}

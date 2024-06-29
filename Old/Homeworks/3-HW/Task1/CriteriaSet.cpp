#include "CriteriaSet.h"
#include "CriteriaFull.h"

CriteriaSet::CriteriaSet(Criteria* criteria) {
	this->criteria = criteria;
}

bool CriteriaSet::contains(const int el) const {
	return this->criteria->contains(el);
}

void CriteriaSet::printSet(const int a, const int b, const int mode) const {
	bool empty = true;
	for (int i = a; i <= b; i++) {
		if (contains(i)) {
			empty = false;
			if (mode == 2) {
				if (!printOneMoreElement()) {
					return;
				}
				cout << i << endl;
			}
			else {
				cout << i << ' ';
			}
		}
	}
	if (empty) {
		cout << "{ }";
	}
	cout << endl;
}

CriteriaSet::~CriteriaSet()
{
	delete criteria;
	criteria = nullptr;
}

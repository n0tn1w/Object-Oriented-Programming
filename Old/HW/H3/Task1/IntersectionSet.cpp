#include "IntersectionSet.h"

IntersectionSet::IntersectionSet(Vector<Set*> sets)
{
	this->elms = sets;
}

bool IntersectionSet::contains(const int el) const
{
	size_t size = elms.getSize();
	for (size_t i = 0; i < size; i++) {
		if (!elms[i]->contains(el)) {
			return false;
		}
	}
	return true;
}

void IntersectionSet::printSet(const int a, const int b, const int mode) const
{
	size_t size = elms.getSize();
	bool empty = true;
	for (int i = a; i <= b; i++) {
		bool exist = true;
		for (size_t k = 0; k < size; k++) {
			if (!elms[k]->contains(i)) {
				exist = false;
				break;
			}
		}
		if (exist) {
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

IntersectionSet::~IntersectionSet()
{
	int size = elms.getSize();
	for (int i = 0; i < size; i++) {
		delete elms[i];
	}
}

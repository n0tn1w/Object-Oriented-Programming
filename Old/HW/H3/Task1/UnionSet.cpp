#include "UnionSet.h"

UnionSet::UnionSet(Vector<Set*> sets)
{
	this->elms = sets;
}

bool UnionSet::contains(const int el) const
{
	size_t size = elms.getSize();
	for (size_t i = 0; i < size; i++) {
		if (elms[i]->contains(el)) {
			return true;
		}
	}
	return false;
}

void UnionSet::printSet(const int a, const int b, const int mode) const
{
	size_t size = elms.getSize();
	bool empty = true;
	for (int i = a; i <= b; i++) {
		bool exist = false;
		for (size_t k = 0; k < size; k++) {
			if (elms[k]->contains(i)) {
				exist = true;
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

UnionSet::~UnionSet()
{
	int size = elms.getSize();
	for (int i = 0; i < size; i++) {
		delete elms[i];
	}
}

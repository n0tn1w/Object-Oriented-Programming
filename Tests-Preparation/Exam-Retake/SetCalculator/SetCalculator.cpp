#pragma once
#include "SetExpression.cpp"
#include "Var.cpp"
#include "Union.cpp"
#include "Intersection.cpp"
#include "Minus.cpp"
#include "Complement.cpp"
#include <string_view>
#include "View.hpp"

class SetCalculator {

public:

	SetCalculator(const char* str) {
		View<char> view(str);
		_root = createSets(view);
	}
		
	SetExpression* createSets(View<char> view) {

		if (view.getSize() == 1) {
			return new Var(view[0]);
		}
		view = view.substr(1, view.getSize() - 2);
		int bracketsCnt = 0;

		for (size_t i = 0; i < view.getSize(); i++) {
			if (view[i] == '(') {
				bracketsCnt++;
			}
			else if (view[i] == ')') {
				bracketsCnt--;
			}
			else if (bracketsCnt == 0) {
				if (view[i] == 'v') {
					return new Union(createSets(view.substr(0, i)), createSets(view.substr(i + 1, view.getSize() - i - 1)));
				}
				else if (view[i] == '^') {
					return new Intersection(createSets(view.substr(0, i)), createSets(view.substr(i + 1, view.getSize() - i - 1)));
				}
				else if (view[i] == '\\') {
					return new Minus(createSets(view.substr(0, i)), createSets(view.substr(i + 1, view.getSize() - i - 1)));
				}
				else if (view[i] == '!') {
					return new Complement(createSets(view.substr(1, view.getSize() -1)));
				}
			}
		}
	}

	friend bool operator==(const SetCalculator& l, const SetCalculator& r) {
		SigmaAlgebra l1;
		SigmaAlgebra l2;

		l._root->eval(l1);
		r._root->eval(l2);

		return l1 == l2;
	}

	bool isElementIn(const SigmaAlgebra& el) {
		SigmaAlgebra l1;
		_root->eval(l1);

		return l1.isElementIn(el);
	}

private:
	SetExpression* _root;
};
#pragma once
#include "BinarySetExpression.cpp"


class Intersection : public BinarySetExpression {

public:

	Intersection(SetExpression* l, SetExpression* r) : BinarySetExpression(l, r) {}

	SetExpression* clone() const override {
		return new Intersection(*this);
	}

	void eval(SigmaAlgebra& sa) const override {
		SigmaAlgebra l1;
		SigmaAlgebra l2;

		_left->eval(l1);
		_right->eval(l2);

		sa = intersect(l1, l2);
	}
};
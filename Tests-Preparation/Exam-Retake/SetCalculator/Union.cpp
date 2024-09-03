#pragma once
#include "BinarySetExpression.cpp"

class Union : public BinarySetExpression {

public:

	Union(SetExpression* left, SetExpression* right) : BinarySetExpression(left, right) {}

	SetExpression* clone() const override {
		return new Union(*this);
	}

	void eval(SigmaAlgebra& sa) const override {
		SigmaAlgebra l1;
		SigmaAlgebra l2;

		_left->eval(l1);
		_right->eval(l2);

		sa = l1 + l2;
	}

};
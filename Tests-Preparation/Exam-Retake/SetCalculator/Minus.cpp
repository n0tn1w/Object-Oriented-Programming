#pragma once 
#include "BinarySetExpression.cpp"

class Minus : public BinarySetExpression {

public: 
	Minus(SetExpression* l, SetExpression* r) : BinarySetExpression(l, r) {}

	SetExpression* clone() const override {
		return new Minus(*this);
	}

	void eval(SigmaAlgebra& sa) const override {
		SigmaAlgebra l1;
		SigmaAlgebra l2;

		_left->eval(l1);
		_right->eval(l2);

		sa = l1 / l2;
	}
};
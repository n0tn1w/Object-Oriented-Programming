#pragma once

#include "UnarySetExpression.cpp"


class Complement : public UnarySetExpression {

public:

	Complement(SetExpression* expr) : UnarySetExpression(expr) {}

	SetExpression* clone() const override {
		return new Complement(*this);
	}

	void eval(SigmaAlgebra& sa) const override {
		SigmaAlgebra l1;
		_expr->eval(l1);

		sa = compliment(l1);
	}
};
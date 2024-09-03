#pragma once
#include "SetExpression.cpp"

class Var : public SetExpression {

public:

	Var(char ch) {
		_ch = ch;
	}

	void eval(SigmaAlgebra& sa) const override {
		sa.setAt(_ch, true);
	}

	SetExpression* clone() const override {
		return new Var(_ch);
	}

private:

	char _ch;

};
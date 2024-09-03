#pragma once
#include "SetExpression.cpp"

class UnarySetExpression : public SetExpression {

public:
		
	UnarySetExpression(SetExpression* expr) : _expr(expr) {}

	virtual ~UnarySetExpression() {
		delete _expr;
	}

protected:
	SetExpression* _expr;
};
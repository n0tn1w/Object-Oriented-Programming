#pragma once
#include "SetExpression.cpp"

class BinarySetExpression : public SetExpression {

public:

	BinarySetExpression(SetExpression* left, SetExpression* right) : _left(left), _right(right) {}

	virtual ~BinarySetExpression() {
		delete _left;
		delete _right;
	}

protected:

	SetExpression* _left;
	SetExpression* _right;

};
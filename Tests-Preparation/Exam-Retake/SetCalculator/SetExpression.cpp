#pragma once
#include "SigmaAlgebra.cpp"

class SetExpression {

public:

	virtual void eval(SigmaAlgebra&) const = 0;

	virtual SetExpression* clone() const = 0;
	
	virtual ~SetExpression() = default;

};
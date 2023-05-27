#pragma once

class Criteria {

protected:

	int elements[32];
	short n; //size

public:

	Criteria(const int*, short);
	
	virtual bool contains(const int) const = 0;
};
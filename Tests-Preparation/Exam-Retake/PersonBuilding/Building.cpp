#pragma once
#include "Person.cpp"

class Building {
public:
	virtual Building* clone() const = 0;
	virtual void accepts(Person*) const = 0;
	virtual ~Building() = default;
};

class Bank : public Building {
private:
	double money;
public:
	Bank(double money) : money(money) {}
	Building* clone() const override {
		return new Bank(*this);
	}
	void accepts(Person* p) const override {
		p->visit(this);
	}
};

class School : public Building {
private:
	int people;
public:
	School(int people) : people(people) { }
	Building* clone() const override {
		return new School(*this);
	}
	void accepts(Person* p) const override {
		p->visit(this);
	}
};
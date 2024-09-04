#pragma once
#include <iostream>

class Bank;
class School;

class Person {

public:

	virtual Person* clone() const = 0;
	virtual ~Person() = default;

	virtual void visit(const Bank*) const = 0;
	virtual void visit(const School*) const = 0;

};

class Student : public Person {
private:
	int grade;
public:
	Student(int grade) : grade(grade) {}
	Person* clone() const override {
		return new Student(*this);
	}

	void visit(const Bank* bank) const override {
		std::cout << "Student in the bank!" << std::endl;
	}
	void visit(const School* school) const override {
		std::cout << "Student in the bank!" << std::endl;
	}
};

class Professor : public Person {
private:
	int age;
public:
	Professor(int age) : age(age) {}
	Person* clone() const override {
		return new Professor(*this);
	}

	void visit(const Bank* bank) const override {
		std::cout << "Professor in the bank!" << std::endl;
	}
	void visit(const School* school) const override {
		std::cout << "Professor in the bank!" << std::endl;
	}
};
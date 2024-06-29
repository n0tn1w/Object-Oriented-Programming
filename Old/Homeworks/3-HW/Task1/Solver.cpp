#include "Solver.h"

Solver::Solver(MyString& str)
{
	this->fileName = str;
}

void Solver::run()
{
	int mode;
	cout << "1 to enter a, b || 2 to view element by element" << endl;
	cin >> mode;

	int a, b;
	if (mode == 1) {

		cout << "Enter a and b" << endl;
		cin >> a >> b;
		if (a < 0 || b < 0 || b < a) {
			throw out_of_range("Invalid a, b!");
		}

		setFactory(this->fileName)->printSet(a, b, mode);
	}
	else if(mode == 2){
		a = 0;
		b = INT_MAX;

		setFactory(this->fileName)->printSet(a, b, mode);
	}
	else {
		throw out_of_range("Invalid mode!");
	}
}
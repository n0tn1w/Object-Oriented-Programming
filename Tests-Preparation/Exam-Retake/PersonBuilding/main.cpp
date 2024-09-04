#include "Building.cpp"

class BuildingFactory {
public:
	static Building* create(int n) {
		if (n == 0) {
			return new Bank(1'000);
		}
		else if (n == 1) {
			return new School(30);
		}
	};
};

class PersonFactory {
public:
	static Person* create(int k) {
		if (k == 0) {
			return new Student(2);
		}
		else if (k == 1) {
			return new Professor(65);
		}
	}
};



int main() {

	Building* b = BuildingFactory::create(0);
	Person* p = PersonFactory::create(1);
	b->accepts(p);
}
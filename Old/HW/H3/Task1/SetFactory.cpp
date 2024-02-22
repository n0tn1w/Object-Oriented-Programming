#include "SetFactory.h"

Set* setFactory(const MyString& fileName)
{
	ifstream file(fileName.c_str(), std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		throw logic_error("Error!File cannot open!");
	}

	short n, t;
	file.read((char*)&n, 2);
	file.read((char*)&t, 2);

	Set* s = nullptr;
	if (t == 3 || t == 4) {
		Vector<Set*> vect;
		MyString newFileName("");

		char curr;
		char* arr = new char[2];
		for (int i = 0; i < n;) {

			file.read((char*)&curr, sizeof(curr));
			arr[0] = curr;
			arr[1] = '\0';
			newFileName += arr;

			if (curr == '\0') {
				vect.pushBack(setFactory(newFileName));
				i++;
				newFileName = "";
			}		
		}

		delete[] arr;
		if (t == 3) {
			s = new UnionSet(vect);
		}
		else {
			s = new IntersectionSet(vect);
		}
	}
	else if (t == 0 || t == 1 || t == 2) {
		int* arr = new int[n];
		
		for (int i = 0; i < n; i++) {
			file.read((char*)&arr[i], sizeof(int));
		}
		s = new CriteriaSet(criteriaFactory(t, arr, n));
		delete[] arr;
	}
	else {
		throw logic_error("Error! Invalid T!");
	}

	file.close();

	return s;
}

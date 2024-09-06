#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class String {

	char* _data;
	size_t _size;
	size_t _capacity;

	void free() {
		delete[] _data;
	}
	void copyFrom(const String& oth) {
		_size = oth._size;
		_capacity = oth._capacity;
		_data = new char[_capacity + 1];
		memcpy(_data, oth._data, _size + 1);
	}
	void moveFrom(String&& oth) {
		_size = oth._size;
		_capacity = oth._capacity;
		_data = oth._data;
		oth._data = nullptr;
		oth._size = oth._capacity = 0;
	}
	void resize() {
		_capacity *= 2;
		char* newData = new char[_capacity];
		memcpy(newData, _data, _size + 1);
		delete[] _data;
		_data = newData;
	}


public:
	
	String(const char* str) {
		_size = strlen(str);
		_capacity = _size;
		_data = new char[_capacity + 1];

		strcpy_s(_data, _capacity + 1, str);
	}
	// Big 6
	
	explicit String(size_t alloc) {
		_capacity = alloc;
		_size = 0;
		_data = new char[_capacity];
	}

	const char* c_str() const {
		return _data;
	}

	char& operator[] (size_t idx) { 
		return _data[idx];
	}

	const char& operator[] (size_t idx) const{
		return _data[idx];
	}

	size_t getSize() const {
		return _size;
	}

	String& operator+=(const String& st) {
		size_t newSize = _size + st._size; 
		if (newSize >= _capacity) {
			resize();
		}

		memcpy(_data + _size, st._data, st._size + 1);

		_size += st._size;

		return *this;
	}

	friend ostream& operator<<(ostream& os, const String& st) {
		return os << st.c_str();
	}

	friend istream& operator>>(istream& is, String& st) {
		char buff[1024];
		is >> buff;

		delete[] st._data;
		size_t len = strlen(buff);
		st._capacity = std::max(16, (int)len);
		st._data = new char[st._capacity + 1];
		memcpy(st._data, buff, len + 1);

		return is;
	}

	//StringView getView(size_t begin, size_t size) {
	//	return StringView{ _data + begin, size };
	//}
};
bool operator>(const String& l, const String& r) {
	return (strcmp(l.c_str(), r.c_str()) > 0);
}

bool operator==(const String& l, const String& r) {
	return !(l > r) && !(r > l);
}

String operator+(const String& l, const String& r) {
	String s(l.getSize() + r.getSize());
	s += l;
	s += r;

	return s;
}

#include <sstream>
int main() {

	//const char* str = "[12]]]";
	//std::stringstream ss(str);
	//ss.ignore();
	//int i;
	//ss >> i;
	//cout << i;

	String s1("aab");
	String s2("ccd");
	cin >> s1;
	cin >> s2;

	cout << (s1 == s2);
	cout << std::endl;

	String d = s1 + s2;
	std::cout << d;
}
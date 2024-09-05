#include <cstring>

class StringPool {

private:
	
	class StoredString {
	public:
		char* _str;
		int _refCount;
	};

	StoredString* _data;
	size_t _size;
	size_t _capacity;

	int findIndex(const char* str) {
		for (size_t i = 0; i < _size; i++) {
			if (strcmp(_data[i]._str, str) == 0) {
				return i;
			}
		}
		return -1;
	}

public:

	//Big 6
	StringPool() {
		_size = 0;
		_capacity = 8;
		_data = new StoredString[_capacity];
	}
	~StringPool() {
		for (size_t i = 0; i < _size; i++) {
			delete[] _data[i]._str;
		}
		delete[] _data;
	}

	const char* get(const char* str) {
		int index = findIndex(str);
		if (index != -1) {
			// Found
			_data[index]._refCount++;
			return _data[index]._str;
		}

		_data[_size]._str = new char[strlen(str) + 1];
		strcpy_s(_data[_size]._str, strlen(str) + 1, str);
		_data[_size]._refCount = 1;

		return _data[_size++]._str;
	}
	void release(const char* str) {
		int index = findIndex(str);
		if (index == -1) {
			// Not Found
			return;
		}

		_data[index]._refCount--;
		if (_data[index]._refCount == 0) {
			delete[] _data[index]._str;
		}
	}

};

int main() {}
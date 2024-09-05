#include "StringPool.cpp"

class ImmutableString {
	
	static StringPool pool;

	const char* _str;
	size_t _size;

public:

	ImmutableString(const char* str) {
		_str = pool.get(str);
		_size = strlen(str);
	}

	size_t getSize() const {
		return _size;
	}

	const char* c_str() const {
		return _str;
	}

	~ImmutableString() {
		pool.release(_str);
	}
	
};
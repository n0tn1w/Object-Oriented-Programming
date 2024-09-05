#include <vector>

template <class T>
class PolyContainer {
	std::vector<PolyPointer<T>> _arr;
public:

	void add(T* data) {
		_arr.push_back(PolyPointer(data));
	}

};


template <class T>
class PolyPointer{
	T* _data;

	void copyFrom(const PolyPointer& oth) {
		_data = oth._data->clone();
	}

	void free() {
		delete _data;
	}
public:
	PolyPointer() {
		_data = nullptr;
	}

	PolyPointer(T* data) {
		_data = data;
	}
	PolyPointer(const PolyPointer& oth) {
		copyFrom(oth);
	}
	PolyPointer<T>& operator=(const PolyPointer& oth) {
		if (this != other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	T* get() {
		return _data;
	}

	const T* get() const {
		return _data;
	}
	const T& operator*() const {
		return _data;
	}
	T& operator*() {
		return _data;
	}

	const T* operator->() const {
		return _data;
	}
	T* operator->() {
		return _data;
	}


	~PolyPointer() {
		free();
	}
};

struct Base { };
struct A : Base { };
struct B : Base { };
struct C : Base { };

int main() {
	PolyPointer<Base> f = new A();
	f.get();	
}

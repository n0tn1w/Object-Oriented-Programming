template <class T>
class Function {

public:

    Function(const T& data) {
        _data = data;
    }

    void operator()(int val) {
        _data(val);
    }

private:

    T _data;

};
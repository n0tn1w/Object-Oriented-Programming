#define TT template<class T>
#define Q Queue<T>

TT
class Queue {

public:

    Queue();
    Queue(const Queue<T>&);
    Queue(Queue<T>&&);
    Queue<T>& operator=(const Queue<T>&);
    Queue<T>& operator=(Queue<T>&&);
    ~Queue();

    bool isEmpty() const;
    const T& peek() const;
    void pop();
    void push_back(const T&);
    void push_back(T&&);

private:

    void copyFrom(const Queue<T>&);
    void moveFrom(Queue<T>&&);
    void free();
    void resize();

    size_t _get = 0, _put = 0;

    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

};

TT
void Q::copyFrom(const Queue<T>& oth) {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = new T[_capacity];
    for(size_t i = 0; i < _size; i++) {
        _data = oth._data[i];
    }
    _get = oth._get;
    _put = oth._put;
}


TT
void Q::moveFrom(Queue<T>&& oth) {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = oth._data;
    _get = oth._get;
    _put = oth._put;

    oth._size = 0;
    oth._capacity = 0;
    oth._data = nullptr;
    oth._get = 0;
    oth._put = 0;

}

TT
void Q::free() {
    delete[] _data;
}

TT
void Q::resize() {
    T* newData = new T[_capacity * 2];

    for(size_t i = 0; i < _size; i++) {
        newData[i] = _data[_get++ % _capacity];
    }
    _get = 0;
    _put = _size;
}

TT
bool Q::isEmpty() const {
    return _size == 0;
}


TT
const T& Q::peek() const {
    if(isEmpty())
        throw std::logic_error("Queue is empty!");
    
    return _data[_get];
}

TT
void Q::pop() {
    if(isEmpty())
        throw std::logic_error("Queue is empty!");
    
    _size--;
    _get = (++_get % _capacity);
}

TT
void Q::push_back(const T& elt) {
    if(_size == _capacity)
        resize();

    _data[_put] = elt;
    _put = (++_put % _capacity);
    _size++;
}

TT
void Q::push_back(T&& elt) {
    if(_size == _capacity)
        resize();

    _data[_put] = std::move(elt);
    
    _put = (++_put % _capacity);
    _size++;
}

TT
Q::Queue() {
    _size = 0;
    _capacity = 16;
    _data = new T[_capacity];
}
TT
Q::Queue(const Queue<T>& oth) {
    copyFrom(oth);
}
TT
Q::Queue(Queue<T>&& oth) {
    moveFrom(std::move(oth));
}
TT
Queue<T>& Q::operator=(const Queue<T>& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}
TT
Queue<T>& Q::operator=(Queue<T>&& oth) {

    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }
    return *this;
}
TT
Q::~Queue() {
    free();
}
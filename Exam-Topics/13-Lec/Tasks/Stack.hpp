template <class T, unsigned N>
class Stack {

public:

    void push(const T&);
    void push(T&&);

    void pop();
    const T& peek() const;
    bool isEmpty() const;

private:

    T arr[N];
    unsigned size = 0;

};

template <class T, unsigned N>
void Stack<T, N>::push(const T& el) {
    if(size >= N)
        throw;

    arr[size++] = el;
}

template <class T, unsigned N>
void Stack<T, N>::push(T&& el) {
    if(size >= N)
        throw;

    arr[size++] = std::move(el);
} 

template <class T, unsigned N>
void Stack<T, N>::pop() {
    if(size <= 0)
        throw;

    size--;
} 

template <class T, unsigned N>
const T& Stack<T, N>::peek() const {
    return arr[size - 1];
} 

template <class T, unsigned N>
bool Stack<T, N>::isEmpty() const {
    return size == 0;
} 

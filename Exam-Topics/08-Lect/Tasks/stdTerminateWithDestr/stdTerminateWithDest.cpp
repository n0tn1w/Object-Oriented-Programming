struct B {
    ~B() {
        throw 420;
    }
};

struct A : B {  
    A() : B() {
       // throw 42;
    }
};

int main () {
    try {
        A a;
    } catch (int a) {
    
    }
}
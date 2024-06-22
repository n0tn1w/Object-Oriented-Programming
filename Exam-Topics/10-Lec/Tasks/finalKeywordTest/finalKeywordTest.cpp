
struct A {
    virtual void f() {};
};

struct B : A{
    void f() override {};
};

struct C : B {
    void f() final {};
};

// struct D : C { 
//     void f() {};
// };
// Compile time


struct A {
    virtual void f() {};
};

struct D final : A{
    void f() override {};
};

// struct E : D {
//     void f() final {};
// }; 
// Compile time

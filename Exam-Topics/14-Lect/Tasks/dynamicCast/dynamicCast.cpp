struct Base {
    virtual void f() { }
};

struct Der1 : Base {
    void f() override { }
};

struct Der2 : Der1 {
    void f() override { }
};

int main() {
    Der2* d2 = new Der2();

    Der1* d1 = dynamic_cast<Der1*>(d2);
}
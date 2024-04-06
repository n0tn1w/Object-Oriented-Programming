struct A {};

// Theoretical example of which func can call which

void f1(A obj) {
    f1(obj); f2(obj); f3(obj); f4(obj); f5(&obj); f6(&obj);
}
void f2(const A obj) {
    f1(obj); f2(obj); f4(obj); f6(&obj);
}
void f3(A& obj) {
    f1(obj); f2(obj); f3(obj); f4(obj); f5(&obj); f6(&obj);
}
void f4(const A& obj) {
    f1(obj); f2(obj); f4(obj); f6(&obj);
}
void f5(A* obj) {
    f1(*obj); f2(*obj); f3(*obj); f4(*obj); f5(obj); f6(obj);
}
void f6(const A* obj) {
        f1(*obj); f2(*obj); f4(*obj); f6(obj);
}
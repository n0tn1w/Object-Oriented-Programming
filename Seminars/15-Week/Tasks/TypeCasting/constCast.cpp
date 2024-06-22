

void f(const int* val) {
    int* n = const_cast<int*>(val);

    ;
}

int main() {
    const int x = 4;
    f(&x);
}
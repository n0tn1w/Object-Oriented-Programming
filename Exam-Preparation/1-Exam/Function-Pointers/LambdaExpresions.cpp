#include <iostream>
using std::cout;
using std::endl;

typedef void(*FuncPtr)(const char*, double);

class Command {
    FuncPtr _funcPtr; 
public:
    Command() = default;

    Command(FuncPtr funcPtr) {
        setFuncPtr(funcPtr);
    }

    void setFuncPtr(FuncPtr funcPtr) {
        _funcPtr = funcPtr;
    }

    void execute(const char* f, int s) {
        _funcPtr(f, s);
    } 
};

int main() {

    Command lambda;
    lambda.setFuncPtr([](const char* a, double b){ cout << a << b << endl;});
    lambda.execute("Ph: ", 10);
}
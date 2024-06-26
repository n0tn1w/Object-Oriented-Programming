#include <iostream>
using std::cout;
using std::endl;

// Dont use references here no need
// Function pointers are low cost so no need to overcomplicate it
typedef void(*FuncPtr)(int, int);

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

    FuncPtr getFuncPtr() const {
        return _funcPtr;
    }

    void execute(int f, int s) {
        _funcPtr(f, s);
    } 
};

void print(int a, int b) {
    cout << a << ' ' << b << endl;
}

void sum(int a, int b) {
    cout << "Sum: " << a + b << endl;
}

int main() {
    Command cmd;
    cmd.setFuncPtr(print);
    cmd.execute(1, 2);

    cmd.setFuncPtr(sum);
    cmd.execute(1, 2);

    // I prefer execute to be my only getter
    cmd.getFuncPtr()(10, 11);

    cout << sizeof(FuncPtr) << endl; // 8 bytes for x64 and 4 bytes for x32
    FuncPtr forDeletion = sum;
    // Compile time error
    // you cannot delete it be because it was saved somewhere in memory and you cannot delete this data
    //delete forDeletion; 
}
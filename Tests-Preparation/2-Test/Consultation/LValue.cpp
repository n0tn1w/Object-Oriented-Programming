#include <utility>
using namespace std;

void f(int&) {

}

int main() {

    int a = 3;
    // f(std::move(a)); ERROR 
}
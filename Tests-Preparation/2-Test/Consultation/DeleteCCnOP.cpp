#include <utility>

class A {
 
public:
	A();
	//A(const A&) = delete;
	//A(const A&) = default;
    //A(A&&) = delete;
	//A(A&&) = default;
};
 
int main() {
 
	A a;
	A b(a);
	A c(std::move(b));
 
	A d;
	d = a;
 
	A g;
	g = std::move(g);
}
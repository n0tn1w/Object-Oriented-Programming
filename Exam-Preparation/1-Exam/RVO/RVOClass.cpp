// RVO - return value optimization for class

#include <iostream>
using namespace std;

class RVO {
private:
    int toyota; // koq godina e 


public:
    RVO() {
        cout << "RVO()" << endl;
    }
    RVO(const RVO&) {
        cout << "RVO CC()" << endl;
    }
    RVO& operator=(const RVO&) {
        cout << "RVO op=" << endl;
    }
    ~RVO() {
        cout << "~RVO()" << endl;
    }

    RVO optimize() {
        RVO inRvo;
        return inRvo;
    }
};

class Containter {
    RVO rvo;

public:
    Containter(RVO& rvo): rvo(rvo) {
        cout << "Containter()" << endl;
    }

    ~Containter() {
        cout << "~Container()" << endl;
    }
};


int main() {
    RVO rvo;
    Containter cont(rvo);
    // RVO(), CC of RVO(), Container(), ~Container(), ~RVO(), ~RVO()
}
// RVO - return value optimization for fucntion

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


int main() {
    RVO ovr;
    RVO newOvr = ovr.optimize();
    // RVO(), RVO(), ~RVO(), ~RVO();
    // this is done by constructing the the rv
}
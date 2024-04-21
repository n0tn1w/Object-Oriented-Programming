#include <iostream>
#include "ModifiableIntegersFunction.h"
using std::cout;
using std::endl;

typedef uint16_t(*FP)(uint16_t);

int16_t still(int16_t x) {
    return x;
}

int16_t ones(int16_t x) {
    return 1;
}
int16_t twos(int16_t x) {
    return 2;
}

int16_t reverse(int16_t x) {
    return -x + 1;
}

int16_t addOne(int16_t x) {
    if (x == INT16_MAX)
        return x;
    return x + 1;
}


int16_t addOneBijection(int16_t x) {
    if (x == INT16_MAX)
        return INT16_MIN;
    return x + 1;
}


int main()
{
    std::cout << "Hello World!\n";

    int16_t a = -12;
    size_t c = 13;
    size_t b = a + c;
    //cout << b;

    ModifiableIntegersFunction mifs(still);
    cout << mifs.getResultByNumber(1) << endl;
    cout << mifs.getResultByNumber(1000) << endl;
    mifs.presetResult(1, 0); //32769
    cout << mifs.getResultByNumber(-1) << endl;
    cout << mifs.getResultByNumber(0) << endl;
    cout << mifs.getResultByNumber(1) << endl;
    cout << mifs.getResultByNumber(2) << endl;
    cout << mifs.getResultByNumber(3) << endl;

    //cout << "addition" << endl;
    ModifiableIntegersFunction onesF(ones);
    ModifiableIntegersFunction twosF(twos);
    ModifiableIntegersFunction threeHopefully = onesF + twosF;
    //cout << threeHopefully.getResultByNumber(1) << endl;
    //cout << threeHopefully.getResultByNumber(1000) << endl;
    //cout << threeHopefully.getResultByNumber(10000) << endl;

    cout << "subtaction" << endl;
    ModifiableIntegersFunction newOnes = twosF - onesF;
    newOnes.removeResult(1);
    cout << "isremoed: " << twosF.isRemoved(1) << endl;
    try {
        newOnes.presetResult(1, 1000);
        cout << newOnes.getResultByNumber(1) << endl;

    }
    catch (std::logic_error& e) {
        cout << e.what();
    }
    cout << newOnes.getResultByNumber(1000) << endl;
    cout << newOnes.getResultByNumber(10000) << endl;

    ModifiableIntegersFunction smaller(ones);
    ModifiableIntegersFunction biiger(twos);
    biiger.removeResult(1);
    smaller.removeResult(1);

    smaller.draw({ 0, 0 }, { 20, 20 });
    smaller.draw({ 0, 0 }, { 20, 0 });

    cout << "comp " << true << " " << (smaller < biiger) << endl;
    cout << "par " << true << " " << (smaller |= biiger) << endl;

    cout << "bj: " << biiger.isBijection() << endl;

    ModifiableIntegersFunction bijects(still);
    cout << "bj: " << bijects.isBijection() << endl;

    ModifiableIntegersFunction reversed(reverse);
    cout << reversed.getResultByNumber(1000) << endl;
    cout << reversed.getResultByNumber(0) << endl;
    cout << reversed.getResultByNumber(1) << endl;
    cout << reversed.getResultByNumber(INT16_MAX) << endl;

    ModifiableIntegersFunction normal = reversed ^ -1;
    cout << reversed.getResultByNumber(1000) << endl;
    cout << reversed.getResultByNumber(0) << endl;
    cout << reversed.getResultByNumber(1) << endl;
    cout << reversed.getResultByNumber(INT16_MAX) << endl;

    cout << "Bijection fail test ^: " << endl;
    ModifiableIntegersFunction stillz(addOne);
    cout << stillz.getResultByNumber(1000) << endl;
    cout << stillz.getResultByNumber(0) << endl;
    cout << stillz.getResultByNumber(1) << endl;
    cout << stillz.getResultByNumber(INT16_MAX) << endl;
    try {
        ModifiableIntegersFunction reversedStillz = stillz ^ -1;
        cout << reversedStillz.getResultByNumber(1000) << endl;
        cout << reversedStillz.getResultByNumber(0) << endl;
        cout << reversedStillz.getResultByNumber(1) << endl;
        cout << reversedStillz.getResultByNumber(INT16_MAX) << endl;
    }
    catch (std::logic_error& e) {
        cout << "skill issue";
    }

    cout << "Wokring ^: " << endl;
    ModifiableIntegersFunction onesBijection(addOneBijection);
    try {
        ModifiableIntegersFunction onesBijectionRe = onesBijection ^ -1;
        cout << onesBijectionRe.getResultByNumber(1000) << endl;
        cout << onesBijectionRe.getResultByNumber(0) << endl;
        cout << onesBijectionRe.getResultByNumber(1) << endl;
        cout << onesBijectionRe.getResultByNumber(INT16_MAX) << endl;
    }
    catch (std::logic_error& e) {
        cout << "skill issue";
    }
}

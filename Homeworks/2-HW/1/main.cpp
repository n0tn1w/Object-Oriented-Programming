#include <iostream>
#include <fstream>
#include "MultiSet.h"
using std::cout;
using std::endl;

int main()
{
    std::cout << "Hello World!\n";

    uint8_t a = 255;
    // 255 = 1 1 1 1 1 1 1 1

    uint8_t b = 128;  // 1 0 0 0 0 0 0 0 = 128
    //cout << (b >> 5); // 0 0 0 0 0 1 0 0 = 4
    //cout << (int)b;

    cout << 2 * 1 + 1;

    MultiSet ms(5, 5);
    cout << (int) ms.check(4) << endl;
    ms.add(4);
    ms.add(4);
    ms.add(4);
    ms.add(4);
    ms.add(4);
    ms.add(4);
    cout << (int)ms.check(4) << endl;
    ms.add(0);
    ms.add(0);
    ms.add(1);
    cout << (int)ms.check(1) << endl;
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.add(1);
    cout << "1: " << (int)ms.check(1) << endl;
    cout << "4: " << (int)ms.check(4) << endl;
    ms.print();

    ms.remove(1);
    cout << "1: " << (int)ms.check(1) << endl;
    ms.remove(1);
    ms.remove(1);
    ms.remove(1);
    ms.remove(1);
    ms.remove(1);
    ms.remove(1);
    ms.remove(1);
    cout << "1: " << (int)ms.check(1) << endl;
    ms.remove(1);
    ms.remove(1);
    cout << "1: " << (int)ms.check(1) << endl;
    ms.add(1);
    ms.add(1);
    ms.add(1);
    ms.remove(1);
    cout << "1: " << (int)ms.check(1) << endl;
    cout << "ms: ";
    ms.print();

    MultiSet multi(5, 2);
    multi.add(4);
    multi.add(4);
    multi.add(4);
    multi.add(1);
    multi.add(1);
    multi.add(1);
    multi.add(0);
    cout << "multi: ";
    multi.print();

    MultiSet final = unification(ms, multi);
    final.print();

    MultiSet sec = section(ms, multi);
    cout << "sec: ";
    sec.print();

    multi.remove(4);
    multi.remove(1);
    multi.remove(1);
    MultiSet multiAdd = addition(multi);
    cout << "multi add: ";
    multiAdd.print();

    std::ofstream ofs("log.dat", std::ios::binary | std::ios::out);
    ofs << multiAdd;
    ofs.close();

    std::ifstream ifs("log.dat", std::ios::binary | std::ios::in);
    ifs >> multiAdd;
    ifs.close();
    cout << "multi after file: ";
    multiAdd.print();

    multi.add(4);
    cout << "multi: ";
    multi.print();

    try {
        multi.add(4);
    }
    catch (std::out_of_range& e) 
    {
        cout << e.what() << endl;
    }
    catch (std::exception& e) 
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Err" << endl;
    }

    try {
        const char* fk = "Test Throw";
        throw std::logic_error(fk);
    }
    catch (std::exception& e) {
        cout << e.what() << endl;

    }

    return 0;
}
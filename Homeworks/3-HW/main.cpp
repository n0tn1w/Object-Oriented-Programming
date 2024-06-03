#include <iostream>
#include "Factory.h"
using std::cin;
using std::cout;
using std::endl;

namespace TestData {
    constexpr char FIRST_FILE_NAME[] = "first.dat";
    constexpr char SECOND_FILE_NAME[] = "second.dat";
    constexpr char THIRD_FILE_NAME[] = "third.dat";

    constexpr char FUNC_FILE_NAME[] = "func.dat";
};

static void CreateFunctionFile(const char* fileName, uint16_t N, uint16_t T, int* numbers, bool isDefinedF) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
    ofs.write((const char*)&N, sizeof(N));
    ofs.write((const char*)&T, sizeof(T));
    ofs.write((const char*)numbers, (isDefinedF ? N * 2 : N) * sizeof(int));
}

static void CreateFuncFile(const char* fileName, uint16_t N, uint16_t T) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
    ofs.write((const char*)&N, sizeof(N));
    ofs.write((const char*)&T, sizeof(T));

    ofs.write((const char*)TestData::FIRST_FILE_NAME, sizeof(TestData::FIRST_FILE_NAME));
    ofs.write((const char*)TestData::SECOND_FILE_NAME, sizeof(TestData::SECOND_FILE_NAME));
    ofs.write((const char*)TestData::THIRD_FILE_NAME, sizeof(TestData::THIRD_FILE_NAME));

}

static void GenerateTestData() {
    int numbersFirst[] = {0, 1, 2, 3, 5, 6, 7, 0, 3, 3, 3, 4, 4, 0};
    CreateFunctionFile(TestData::FIRST_FILE_NAME, 7, 0, numbersFirst, true);
    
    int numbersSecond[] = {3, 5};
    CreateFunctionFile(TestData::SECOND_FILE_NAME, 2, 1, numbersSecond, false);

    int numbersThird[] = {0, 5, 6, 7};
    CreateFunctionFile(TestData::THIRD_FILE_NAME, 4, 2, numbersThird, false);

    CreateFuncFile(TestData::FUNC_FILE_NAME, 3, 3);
}

int main() {

    GenerateTestData();
    PF* func = FunctionFactory::createFunction(TestData::FUNC_FILE_NAME);

    //CLI
    while(true) {
        cout << "Enter work regime" << endl;
        cout << "1 - [a, b] or 2 - entering one digit at a time" << endl;
        int regime = 0;
        cin >> regime;

        if(regime == 1) {
            int a, b;
            cout << "Enter a: " << endl;
            cin >> a;
            cout << "Enter b: " << endl;
            cin >> b;

            if(a > b) {
                cout << "a should be >= in relation to b" << endl;
                continue;
            }

            for(int i = a; i <= b; i++) {
                Pair<int, bool> res = func->operator()(i);  
                cout << i << ": " <<"defined: " << res.second();
                if(res.second()) {
                    cout << " value: " << res.first();
                }
                cout << endl;
            }
            ;
        } else if(regime == 2) {
            
            int next = 0;
            cout << "Enter 1 for next number: ";
            cin >> next;
            bool noDefinedNumber = true;

            for(long i = INT32_MIN; i < INT32_MAX; i++) {
                Pair<int, bool> res = func->operator()(i);  

                if(res.second()) {
                    noDefinedNumber = false;
                    cout << i << ": " << res.second();
                    cout << " value: " << res.first();
                    cout << endl;

                    cout << "Enter 1 for next number: ";
                    cin >> next;
                }
            }

            if(noDefinedNumber) {
                cout << "No defined numbers!";
            }

        } else {
            cout << "This is not a regime..." << endl;
            continue;
        }
    }

    delete func;
}


// Notes:

//PFContainer::PFContainer(const PF* const* funcs, size_t size) { fix

//Pair<int, bool> resultPair(resultsFromFunctions[0], true); fix
//Pair<int, bool> resultPair(resultsFromFunctions[_size - 1], true); fix

//Pair<int, bool> res = func->operator()(i);  could throw


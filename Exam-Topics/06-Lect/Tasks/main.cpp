#include "GraduatedStudent.h"
#include <iostream>

#include <cstring> // Used for memcpy

using std::cout;
using std::endl;

int main() {
    GraduatedStudent gs;

    gs.setName("Ivan");
    cout << gs.getName() << endl;
    gs.setName("Iv");
    cout << gs.getName() << endl;
    
    int grades[5] = {2, 4, 5, 1, 2};
    gs.setGrades(grades, 5);
    char quote[30] = "12345123451234512345123451234";
    gs.setQuote(quote);
    size_t cnt = gs.getGradesCount();
    const int* gradesS= gs.getGrades();
    for(size_t i = 0; i < cnt; i++) {
        cout << gradesS[i] << " ";
    }
    cout << endl;
    cout << gs.getGrades() << " " << gs.getQuote() << endl;

    int s[5] = {1, 2, 3, 4, 5};
    int ss[5];
    std::memcpy(ss, s, sizeof(s));
    for(int i = 0; i < 5; i++) {
        cout << ss[i] << " ";
    }
    cout << endl;

    GraduatedStudent copyConst(gs);
    GraduatedStudent copyConst2 = gs;
    copyConst = copyConst2;

    GraduatedStudent arr[2];

    //GraduatedStudent err(*(new GraduatedStudent())); // funny thing happens it tries to CC but it cannot because the object doesnt exist
    //cout << err.getGrades();

}
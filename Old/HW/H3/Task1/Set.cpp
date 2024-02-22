#include "Set.h"

bool Set::printOneMoreElement() const
{
    char input;
    cout << "Do you want one more element? (y/n)" << endl;
    cin >> input;
    if (input == 'y') 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

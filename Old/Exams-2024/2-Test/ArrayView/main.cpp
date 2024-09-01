#include <iostream>
#include "ArrayView.hpp"

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    ArrayView<int> view(arr, 10);
    
    std::cout << view << std::endl;
    
    ArrayView<int> sub = view.subArr(2, 3);
    std::cout << sub << std::endl;
    
    const char* arr2 = "Hello World";
    
    ArrayView<char> view2(arr2 + 2, 5);
    
    std::cout<<view2<<std::endl;

    return 0;
}
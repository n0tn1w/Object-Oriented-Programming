#include <iostream>
using namespace std;

int main() {
    char arr[5] = {17, 2, 0, 20, 3};

    for(int i = 0; i < 5; i++) {
        int minIndex = i;
        int currElt = arr[i];
        for(int k = i + 1; k < 5; k++) {
            if(currElt < arr[k]) {
                currElt = arr[k];
                minIndex = k;
            }
        }

        if(minIndex != -1) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

    }

    for(int i =0 ;i < 5;i++) {
        cout << arr[i] << endl;
    }
}
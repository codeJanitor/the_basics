#include <iostream>
using namespace std;

void insertionSort(int array[], int length);
void printArray(int array[], int length);


int main() {
    int testArray[] = {5, 3, 2, 4, 1};
    int arrayLength = sizeof testArray / sizeof *testArray;
    printArray(testArray, arrayLength);
    insertionSort(testArray, arrayLength);
    printArray(testArray, arrayLength);
    
    return 0;
}


void insertionSort(int array[], int length) {
    int i, current;
    
    for (int j = 1; j < length; j++) {
        current = array[j];
        i = j - 1;
        
        while (i >= 0 && array[i] > current) {
            array[i + 1] = array[i];
            i--;
        }
        
        array[i + 1] = current;
    }
}


void printArray(int array[], int length) {
    cout << "Array: " << endl;

    for (int i = 0; i < length; i++) {
        cout << array[i] << endl;
    }
}

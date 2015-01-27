#include <iostream>
using namespace std;

void bubbleSort(int array[], int length);
void swap(int array[], int first, int second);
void printArray(int array[], int length);


int main() {
    int testArray[] = {1, 2, 4, 3, 5, 0};
    int length      = sizeof testArray / sizeof *testArray;

    printArray(testArray, length);
    bubbleSort(testArray, length);
    printArray(testArray, length);

    return 0;
}


void bubbleSort(int array[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (array[j] < array[j-1]) {
                swap(array, j, j-1);
            }
        }
    }
}


void swap(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}


void printArray(int array[], int length) {
    cout << "Array: " << endl;

    for (int i = 0; i < length; i++) {
        cout << array[i] << endl;
    }
}

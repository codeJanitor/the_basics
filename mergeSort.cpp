#include <iostream>
#include<limits>
using namespace std;

void mergeSort(int array[], int start, int end);
void merge(int array[], int start, int midpoint, int end); 
void printArray(int array[], int length);


int main() {
    //int testArray[] = {0, 5, 3, 4, 2, 1};
    int testArray[] = {2, 1, 0};
    int arrayLength = sizeof testArray / sizeof *testArray;

    printArray(testArray, arrayLength);
    mergeSort(testArray, 0, arrayLength - 1);
    printArray(testArray, arrayLength);

    return 0;
}


void mergeSort(int array[], int start, int end) {
    int midpoint;

    if (start < end) {
        midpoint = (start + end) / 2;
        cout << "Midpoint: " << midpoint << endl;
        mergeSort(array, start, midpoint);
        mergeSort(array, midpoint + 1, end);
        merge(array, start, midpoint, end);
    }
}


void merge(int array[], int start, int midpoint, int end) {
    const int INFINITY = std::numeric_limits<int>::max();

    int i, j, next;
    int a1_length = midpoint - start + 2;
    int a2_length = end - midpoint + 1;

    int a1[a1_length];
    int a2[a2_length];

    for (i = 0; i < a1_length - 1; i++) {
        a1[i] = array[start + i];
    }

    for (j = 0; j < a2_length - 1; j++) {
        a2[j] = array[midpoint + j + 1];
    }

    a1[a1_length] = INFINITY;
    a2[a2_length] = INFINITY;
    
    cout << "A1 and A2: " << endl;
    printArray(a1, a1_length);
    printArray(a2, a2_length);
    cout << "End arrays." << endl;

    i = 0;
    j = 0;

    for (int k = start; k < end + 1; k++) {
        cout << "Indices: " << i << " and " << j << endl;
        cout << "Comparing " << a1[i] << " and " << a2[j] << endl;
        if (a1[i] <= a2[j]) {
            next = a1[i];
            i++;

        } else {
            next = a2[j];
            j++;
        }

        array[k] = next;
    }
}


void printArray(int array[], int length) {
    cout << "Array: " << endl;

    for (int i = 0; i < length; i++) {
        cout << array[i] << endl;
    }
}

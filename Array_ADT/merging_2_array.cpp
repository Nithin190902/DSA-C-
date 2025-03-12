#include <iostream>
#include <stdio.h>
using namespace std;

/*
In array_adt structure *A is a pointer , 
so while declare and initialize the array we have to use new keyword
for dynamic memory allocation
*/
struct array_adt
{
    int *A;
    int size;
    int length;
};

// Merging 2 arrays
// *merge returns a pointer to a new array which is the merged array of arr1 and arr2
struct array_adt *merge(struct array_adt *arr1, struct array_adt *arr2) {
    int i = 0, j = 0, k = 0;
    struct array_adt *arr3 = new struct array_adt;
    arr3->size = arr1->size + arr2->size;
    arr3->length = arr1->length + arr2->length;
    arr3->A = new int[arr3->size];
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }
    return arr3;
}

int main() {
    struct array_adt arr1;
    arr1 = {new int[10] {2, 4, 6, 8, 10}, 10, 5};
    // arr1 = {new int[10] {2, 4, 6, 8, 10}, 10, 5}; // This is also valid

    struct array_adt arr2;
    arr2.size = 10;
    arr2.length = 5;
    arr2.A = new int[arr2.size] {1, 3, 5, 7, 8};

    struct array_adt *arr3;
    arr3 = merge(&arr1, &arr2);
    for (int i = 0; i < arr3->length; i++) {
        cout << arr3->A[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr1.A;
    delete[] arr2.A;
    delete[] arr3->A;
    delete arr3;

    return 0;
}

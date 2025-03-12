#include <iostream>
#include <stdio.h>
using namespace std;

struct array_adt
{
    int *A;
    int size;
    int length;
};
// union is a set operation that returns a new array containing all the elements of the two arrays without repetition
void set_union(struct array_adt *arr1, struct array_adt *arr2, struct array_adt *arr3) {
    int i = 0, j = 0, k = 0;
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    arr3->A = new int[arr3->size];
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        arr3->length++;
    }
    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
        arr3->length++;
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
        arr3->length++;
    }
}

// union for unsorted arrays
void union_unsorted(struct array_adt *arr1, struct array_adt *arr2, struct array_adt *arr3) {
    int i, j, k;
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    arr3->A = new int[arr3->size];
    for (i = 0; i < arr1->length; i++) {
        arr3->A[i] = arr1->A[i];
        arr3->length++;
    }
    for (i = 0; i < arr2->length; i++) {
        for (j = 0; j < arr1->length; j++) {
            if (arr2->A[i] == arr1->A[j]) {
                break;
            }
        }
        if (j == arr1->length) {
            arr3->A[arr3->length++] = arr2->A[i];
        }
    }
}

// intersection is a set operation that returns a new array containing only the elements that are common to both arrays
void intersection(struct array_adt *arr1, struct array_adt *arr2, struct array_adt *arr3) {
    int i = 0, j = 0, k = 0;
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    arr3->A = new int[arr3->size];
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
            arr3->length++;
        }
    }
}

/*
difference is a set operation that returns a new array containing only the elements that are in the first array 
but not in the second array
A-B = {x | x ∈ A and x ∉ B} 
*/

void difference(struct array_adt *arr1, struct array_adt *arr2, struct array_adt *arr3) {
    int i = 0, j = 0, k = 0;
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    arr3->A = new int[arr3->size];
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            arr3->length++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
        arr3->length++;
    }
}


int main() {
    struct array_adt arr1;
    arr1 = {new int[10] {2, 4, 6, 8, 10}, 10, 5};

    struct array_adt arr2;
    arr2.size = 10;
    arr2.length = 5;
    arr2.A = new int[arr2.size] {1, 3, 5, 7, 8};

    struct array_adt arr3;
    set_union(&arr1, &arr2, &arr3);
    for (int i = 0; i < arr3.length; i++) {
        cout << arr3.A[i] << " ";
    }
    cout << endl;

    struct array_adt arr4;
    union_unsorted(&arr1, &arr2, &arr4);
    for (int i = 0; i < arr4.length; i++) {
        cout << arr4.A[i] << " ";
    }
    cout << endl;

    struct array_adt arr5;
    intersection(&arr1, &arr2, &arr5);
    for (int i = 0; i < arr5.length; i++) {
        cout << arr5.A[i] << " ";
    }
    cout << endl;

    struct array_adt arr6;
    difference(&arr1, &arr2, &arr6);
    for (int i = 0; i < arr6.length; i++) {
        cout << arr6.A[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr1.A;
    delete[] arr2.A;
    delete[] arr3.A;
    delete[] arr4.A;
    return 0;
}
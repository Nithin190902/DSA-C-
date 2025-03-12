#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

// creating auxiliary array to store the elements of the array
void reverse(struct Array *arr) {
    int *B = new int[arr->length];
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--) {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    delete[] B;
}

void swaprev(struct Array *arr) {
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void right_shift(struct Array *arr) {
    for (int i = arr->length - 1; i >= 0; i--) {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[0] = 0;
}

int main() {
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    // reverse(&arr);
    right_shift(&arr);
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    return 0;
}
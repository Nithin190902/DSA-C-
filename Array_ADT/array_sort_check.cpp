#include <iostream>
#include <stdio.h>
using namespace std;

struct array_adt
{
    int *A;
    int size;
    int length;
};

void add_element_to_sorted_array(struct array_adt *arr, int x) {
    // Check if the array is full
    if (arr->length == arr->size) {
        return;
    }
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;

}

bool is_sorted(struct array_adt arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }
    return true;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// -ve on left, +ve on right swap
void rearrange(struct array_adt *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0) {
            i++;
        }
        while (arr->A[j] >= 0) {
            j--;
        }
        if (i < j) {
            swap(arr->A[i], arr->A[j]);
        }
    }
}


void display(struct array_adt arr) {
    cout << "Elements are: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

int main() {
    struct array_adt arr;
    arr.size = 10;
    arr.length = 5;
    arr.A = new int[arr.size] {2, 3, -5, 7, -9};
    add_element_to_sorted_array(&arr, 4);
    is_sorted(arr) ? cout << "Array is sorted" : cout << "Array is not sorted";
    rearrange(&arr);
    display(arr);
    return 0;
}
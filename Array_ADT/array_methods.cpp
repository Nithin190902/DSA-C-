#include <iostream>
#include <stdio.h>
using namespace std;

struct array_adt
{
    int *A;
    int size;
    int length;
};

// here -> used to access the members because we are passing the address of the object 
void append(struct array_adt *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(struct array_adt *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int delete_element(struct array_adt *arr, int index) {
    int x = arr->A[index];
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
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
    arr.A = new int[arr.size] {2, 3, 4, 5, 6};
    append(&arr, 10);
    display(arr);
    insert(&arr, 0, 1);
    display(arr);
    cout << "Deleted element: " << delete_element(&arr, 0) << endl;
    display(arr);
    return 0;
}

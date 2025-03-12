#include <iostream>
using namespace std;

struct Arrary {
    int A[10];
    int size;
    int length;
};


int linear_search(struct Arrary arr, int key) {
    for(int i = 0; i < arr.length; i++) {
        if(arr.A[i] == key) {
            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
} 

int transposition_search(struct Arrary *arr, int key) {
    for(int i = 0; i < arr->length; i++) {
        if(arr->A[i] == key) {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

void display(struct Arrary arr) {
    for(int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

int main() {
    struct Arrary arr = {{2, 3, 4, 5, 6}, 10, 5};
    int key = 4;
    // int result = linear_search(arr, key);
    int trans_result = transposition_search(&arr, key);
    if(trans_result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << trans_result << endl;
    }

    display(arr);

    return 0;
}
#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

int binary_search(struct Array arr, int key) {
    int low = 0;
    int high = arr.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(struct Array arr, int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            return binary_search_recursive(arr, low, mid - 1, key);
        } else {
            return binary_search_recursive(arr, mid + 1, high, key);
        }
    }
    return -1;
}


int main() {
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    int key = 6;
    int index = binary_search(arr, key);
    cout << "Element found at index: " << index << endl;
    return 0;
}
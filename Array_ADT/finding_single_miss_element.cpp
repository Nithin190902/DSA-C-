#include <iostream>
using namespace std;

// finding single missing element in a sorted array
int findSingleMissingElement(int arr[], int n) {
    int diff ,low = arr[0], high = arr[n - 1] ;
    diff = low;
    for (int i = 0; i < n; i++) {
        if (arr[i] - i != diff) {
            return i + diff;
        }
    }
    return -1;
}

int main() {
    int arr[] = {6, 7, 8, 9, 11, 12, 13, 14, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Single missing element: " << findSingleMissingElement(arr, n) << endl;
    return 0;
}

// Output
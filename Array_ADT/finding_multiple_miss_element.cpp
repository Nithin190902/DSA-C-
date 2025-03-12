#include <iostream>
using namespace std;

// finding multiple missing elements in a sorted array
void findMultipleMissingElements(int arr[], int n) {
    int diff = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}

int main() {
    int arr[] = {6, 7, 8, 9, 12, 13, 15, 17, 17, 18, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Multiple missing elements: ";
    findMultipleMissingElements(arr, n);
    cout << endl;
    return 0;
}
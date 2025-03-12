#include <iostream>
using namespace std;

// Function to find the duplicate element in an sorted array
void find_duplicate_in_array(int arr[], int n) {
    int last_duplicate = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] && arr[i] != last_duplicate) {
            cout << "Duplicate element is: " << arr[i] << endl;
            last_duplicate = arr[i];
        }
    }
}

void find_and_count_duplicate_in_array(int arr[], int n) {
    int last_duplicate = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] && arr[i] != last_duplicate) {
            cout << "Duplicate element is: " << arr[i] << endl;
            last_duplicate = arr[i];
            int j = i + 1;
            while (arr[j] == arr[i]) {
                j++;
            }
            cout << "Count: " << j - i << endl;
        }
    }
}

// Driver code
int main() {
    int arr[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    // find_duplicate_in_array(arr, n);
    find_and_count_duplicate_in_array(arr, n);
    return 0;
}
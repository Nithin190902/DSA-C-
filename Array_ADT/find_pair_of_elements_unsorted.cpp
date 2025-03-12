#include <iostream>
using namespace std;

void find_pair_of_elements_unsorted(int arr[], int n, int sum) {
    // Create a hash table initialized with 0
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int* hash = new int[max + 1] {0};
    // Traverse the array and find the pair of elements
    for (int i = 0; i < n; i++) {
        int temp = sum - arr[i];
        if (temp >= 0 && hash[temp] == 1) {
            cout << "Pair with the given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << endl;
        }
        hash[arr[i]]++;
    }

    delete[] hash;
}

int main() {
    int arr[] = {3, 7, 1, 2, 8, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    find_pair_of_elements_unsorted(arr, n, sum);
    return 0;
}
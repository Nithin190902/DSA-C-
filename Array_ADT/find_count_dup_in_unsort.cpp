#include <iostream>
using namespace std;

// Function to find and count duplicate elements in an unsorted array using basic hashing
void find_count_dup_unsort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // Create a hash table initialized with 0
    int* hash = new int[max + 1] {0};
    // Traverse the array and increment the hash table
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    // Traverse the hash table and find the duplicate elements
    for (int i = 1; i <= max; i++) {
        if (hash[i] > 1) {
            cout << "Element " << i << " is repeated " << hash[i] << " times" << endl;
        }
    }

    delete[] hash;
}

int main() {
    int arr[] = {3, 7, 1, 2, 8, 4, 5, 2, 7, 8, 3, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_count_dup_unsort(arr, n);
    return 0;
}
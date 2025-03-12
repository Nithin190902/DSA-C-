#include <iostream>
using namespace std;

// Function to find the missing element in an unsorted array using basic hashing
int find_miss_element_unsort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // Create a hash table initialized with 0
    int hash[max + 1] = {0};
    // Traverse the array and increment the hash table
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    // Traverse the hash table and find the missing element
    for (int i = 1; i <= max; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}

// Driver code
int main() {
    int arr[] = {3, 7, 1, 2, 8, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The missing element is: " << find_miss_element_unsort(arr, n);
    return 0;
}


    
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array_adt
{
    int *A;
    int size;
    int length;
};

void display(struct array_adt arr) {
    cout << "Elements are: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

int main () {
    struct array_adt arr;
    cout << "Enter the size of the array: ";
    cin >> arr.size;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr.A[i];
    }
    arr.length = n;


    display(arr);
    

    return 0;
}

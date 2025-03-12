#include <iostream>
using namespace std;

// int main() {
//     int arr[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};
//     cout << "2D Array: "<< arr[2][3] << endl;
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 4; j++) {
//             cout << arr[i][j] << " ";
//             cout << " "<< i << " " << j << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// partially stack allocated 2D array

int main() {
    int *A[3];
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = count++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
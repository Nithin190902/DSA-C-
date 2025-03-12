#include <iostream>
using namespace std;

// increase the size of the array

int main() {
    int *p , *q;
    p = new int[5];
    for (int i = 0; i < 5; i++) {
        p[i] = i + 2;
    }

    q = new int[10];
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    delete []p;
    p = q;
    q = NULL;

    cout << "The elements of the array are: " << p[6] << endl;

    for (int i = 0; i < 10; i++) {
        cout << p[i] << " ";
    }

    

}
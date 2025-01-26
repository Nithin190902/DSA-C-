#include <iostream>
#include <stdio.h>

using namespace std;

// we can create a custom pattern for N numbers using recursion 
// each function will call the next function in the pattern

void funA(int n);
void funB(int n);
void funC(int n);

void funA(int n) {
    if (n>0)
    {
        cout << n << endl;
        funB(n-2);
    }
}

void funB(int n) {
    if (n>1)
    {
        cout << n << endl;
        funC(n/2);
    }
}

void funC(int n) {
    if (n>0)
    {
        cout << n << endl;
        funA(n+1);
    }
}

int main() {
    int n = 20;
    funA(n);
    return 0;
}

// Output: 20 18 9 10 8 4 5 3 1 2
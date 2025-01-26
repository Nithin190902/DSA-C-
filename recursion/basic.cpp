#include <stdio.h>
#include <iostream>

using namespace std;

void func1(int n) {
    if (n>0)
    {
        func1(n-1);
        cout << n << endl;
    } 
}

int main() {
    int n = 5;
    func1(n);
    return 0;
}
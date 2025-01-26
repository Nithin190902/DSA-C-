
#include <stdio.h>
#include <iostream>

using namespace std;

// here x is a static variable thst is initialized only once
//it is not reinitialized when the function is called again and again
// so the value of x is retained in the memory , its a call by reference

int fun(int n) {
    static int x = 0;
    if (n>0)
    {
        x++;
        int y = fun(n-1) + x;
        cout << x << " value of return" << y << endl;
        return y;
    }
    return 0;
}

int main() {
    int n = 5;
    cout << fun(n) << endl;
    return 0;
}
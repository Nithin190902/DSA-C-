// Description: There may be more that one function the calls each other in a circular way. This is called indirect recursion.
// In this example, funA calls funB and funB calls funA. This is an example of indirect recursion.
// Time complexity: O(n)
// Space complexity: O(n)
#include <iostream>
#include <stdio.h>

using namespace std;

void funB(int n);
void funA(int n) {
    if (n>0)
    {
        cout << n << endl;
        funB(n/2);
    }
}

void funB(int n) {
    if (n>0)
    {
        cout << n << endl;
        funA(n-1);
    }
}

int main() {
    funA(20);
    return 0;
}

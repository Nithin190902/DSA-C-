// Description: Nested Recursion is a type of recursion in which a recursive function calls itself as a parameter.
// In the example below, the function fun calls itself as a parameter. This is an example of nested recursion.
#include <iostream>
#include <stdio.h>

using namespace std;

int fun(int n) {
    if (n>100)
    {
        return n-10;
    }
    return fun(fun(n+11));
}

int main() {
    int n = 95;
    cout << fun(n) << endl;
    return 0;
}

/* visualize the recursion tree

funC(95)
├── funC(106) // Base case: returns 96
└── funC(96)
    ├── funC(107) // Base case: returns 97
    └── funC(97)
        ├── funC(108) // Base case: returns 98
        └── funC(98)
            ├── funC(109) // Base case: returns 99
            └── funC(99)
                ├── funC(110) // Base case: returns 100
                └── funC(100)
                    ├── funC(111) // Base case: returns 101
                    └── Returns 91
Output: 91 

Time complexity: O(2^n)
Space complexity: O(n) */


// description: A function that calla itself more than once is called tree recursion
#include <iostream>
#include <stdio.h>

using namespace std;

/*In this example, the function fun is called twice in the function fun
if i call the function fun triple times, the time complexity will be 3^n , but the space complexity will be O(n) */

int fun(int n) {
    if (n>0)
    {
        cout << n << endl;
        fun(n-1);
        fun(n-1);
    }
    return 0;
}

int main() {
    fun(3);
    return 0;
}

/* visualize the recursion tree
funB(3)
├── funB(2)
│   ├── funB(1)
│   │   ├── funB(0)
│   │   └── funB(0)
│   └── funB(1)
│       ├── funB(0)
│       └── funB(0)
└── funB(2)
    ├── funB(1)
    │   ├── funB(0)
    │   └── funB(0)
    └── funB(1)
        ├── funB(0)
        └── funB(0)

Output: 3 2 1 1 2 1 1
Time complexity: O(2^n)
Space complexity: O(n) */
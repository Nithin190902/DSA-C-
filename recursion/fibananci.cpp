#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

/*visualization
time complexity is O(2^n) 
space complexity is O(n)

                fib(5)
               /      \
         fib(4)        fib(3)
         /     \       /     \
     fib(3)  fib(2)  fib(2)  fib(1)
     /    \    /  \   /   \
 fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
 /    \
fib(1) fib(0) */
int fibt(int n)
{
    if (n <= 1)
        return n;
    return fibt(n - 1) + fibt(n - 2);
}

// optimized solution 
int fibLoop(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibMemo(int n, vector<int>meno) {
    if (n <= 1)
        return n;
    if (meno[n] != -1)
        return meno[n];
    meno[n] = fibMemo(n - 1, meno) + fibMemo(n - 2, meno);
    return meno[n];
}

const int MAX = 10; // Define max limit for array size
int A[MAX]; // Global array for memoization

void initializationArray() {
    memset(A, -1, sizeof(A));
}
int fib(int n) {
    if (n <= 1) return A[n]= n;
    if (A[n] != -1) return A[n];
    A[n] = fib(n - 1) + fib(n - 2);
    return A[n];
}
/*
---------------------------------
Index n	| 0 | 1 | 2 | 3 | 4 | 5 |
memo[n]	| 0	| 1 | 1 | 2 | 3 | 5 |
---------------------------------

fib(0) = 0 → Store in memo[0]
fib(1) = 1 → Store in memo[1]
fib(2) = 1 + 0 = 1 → Store in memo[2]
fib(3) = 1 + 1 = 2 → Store in memo[3]
fib(4) = 2 + 1 = 3 → Store in memo[4]
fib(5) = 3 + 2 = 5 → Store in memo[5]
*/

int main()
{
    initializationArray();
    int n = 9;
    cout << fib(n) << endl;
    // vector<int>meno(n + 1, -1);
    // cout << fibMemo(n, meno) << endl;
    return 0;

}
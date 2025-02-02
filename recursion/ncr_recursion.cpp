#include <iostream>
#include <stdio.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// nCr = n! / (n-r)! * r!
int nCr(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(n - r);
    t3 = fact(r);
    return t1 / (t2 * t3);
}

// resursive function to calculate nCr
// here resursive achived through pascal triangle
int nCr_recursion(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return nCr_recursion(n - 1, r - 1) + nCr_recursion(n - 1, r);
}

//memoization technique to reduce the time complexity of the recursive function 
int nCr_memoization(int n, int r)
{
    int C[n + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][r];
}

int main()
{
    int n, r;
    cout << "Enter the value of n and r: ";
    cin >> n >> r;
    cout << "nCr using recursion: " << nCr_recursion(n, r) << endl;
    cout << "nCr using formula: " << nCr(n, r) << endl;
    cout << "nCr using memoization: " << nCr_memoization(n, r) << endl;
    return 0;
}



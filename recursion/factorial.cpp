//factorail of a number
#include <iostream>
#include <stdio.h>
using namespace std;

// recursive function to find the factorial of a number
int factR(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factR(n - 1);
}
/* Time complexity = O(n)
space complexity = O(n) */

// loop function to find the factorial of a number
int factL(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
/* time complexity = O(n)
space complexity = O(1) */

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Factorial of " << n << " using recursive function: " << factR(n) << endl;
    cout << "Factorial of " << n << " using loop function: " << factL(n) << endl;
    return 0;
}
//sum of n natural numbers
#include <iostream>
#include <stdio.h>
using namespace std;

// recursive function to find the sum of n natural numbers
int sumR(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumR(n - 1);
}
/* Time complexity = O(n)
space complexity = O(n) */

// loop function to find the sum of n natural numbers
int sumL(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
/* time complexity = O(n)
space complexity = O(1) */

//direct formula to find the sum of n natural numbers
int sumF(int n)
{
    return n * (n + 1) / 2;
}
/* time complexity = O(1)
space complexity = O(1) */

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Sum of " << n << " natural numbers using recursive function: " << sumR(n) << endl;
    cout << "Sum of " << n << " natural numbers using loop function: " << sumL(n) << endl;
    cout << "Sum of " << n << " natural numbers using direct formula: " << sumF(n) << endl;
    return 0;
}
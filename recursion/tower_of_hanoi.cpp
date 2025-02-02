#include <iostream>
#include <stdio.h>
using namespace std;

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("Move disk %d from %c to %c\n", n, A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(10, 'A', 'B', 'C');
    return 0;
}
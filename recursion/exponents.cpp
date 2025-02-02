#include <iostream>
#include <stdio.h>
using namespace std;

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

int power1(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp % 2 == 0) {
        return power1(base*base, exp / 2);
    } else {
        return base * power1(base*base, (exp-1) / 2);
    }
}

int main() {
    int base = 2;
    int exp = 10;
    cout << power(base, exp) << endl;
    cout << power1(base, exp) << endl;
    return 0;
}
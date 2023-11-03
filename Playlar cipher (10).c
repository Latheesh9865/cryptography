#include <stdio.h>
#include <math.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 25;
    unsigned long long totalKeys = factorial(n);

    double approxPowerOf2 = log2(totalKeys);

    printf("Total possible keys: %llu\n", totalKeys);
    printf("Expressed as an approximate power of 2: %.1f\n", approxPowerOf2);

    return 0;
}

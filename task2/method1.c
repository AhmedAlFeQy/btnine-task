// # **Method 1: Recursive Function**

// # The first way to implement the recurrence relation is to use a recursive function. Here's the implementation:


#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return fibonacci(n-3) + fibonacci(n-2);
}

int main() {
    int n = 10;
    printf("F(%d) = %d\n", n, fibonacci(n));
    return 0;
}








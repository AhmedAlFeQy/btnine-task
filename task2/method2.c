// # **Method 2: Iterative Loop**

// # The second way to implement the recurrence relation is to use an iterative loop. Here's the implementation:


#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 0, b = 1, c = 2, i;
    for (i = 3; i <= n; i++) {
        int temp = c;
        c = a + b + c;
        a = b;
        b = temp;
    }
    return c;
}

int main() {
    int n = 10;
    printf("F(%d) = %d\n", n, fibonacci(n));
    return 0;
}

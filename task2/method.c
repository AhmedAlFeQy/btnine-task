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
```

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
```

// #**Method 3: Dynamic Programming**

// # The third way to implement the recurrence relation is to use dynamic programming to store previously calculated values. Here's the implementation:

```c
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int i;
    for (i = 3; i <= n; i++) {
        dp[i] = dp[i-3] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    printf("F(%d) = %d\n", n, fibonacci(n));
    return 0;
}



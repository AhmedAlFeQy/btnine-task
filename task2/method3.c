// #**Method 3: Dynamic Programming**

// # The third way to implement the recurrence relation is to use dynamic programming to store previously calculated values. Here's the implementation:


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

#include <stdio.h>
#include <stdlib.h>

// Define the node structure with a type tag
typedef struct Node {
    enum TypeTag { ADD, SUB, MUL, DIV, FIBO } type;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node with the given type tag
Node* makeNode(enum TypeTag type, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

// Calculate the result of the given node using dynamic programming
int calc(Node* node, int* fib) {
    switch (node->type) {
        case ADD:
            return calc(node->left, fib) + calc(node->right, fib);
        case SUB:
            return calc(node->left, fib) - calc(node->right, fib);
        case MUL:
            return calc(node->left, fib) * calc(node->right, fib);
        case DIV:
            return calc(node->left, fib) / calc(node->right, fib);
        case FIBO:
            return fib[calc(node->left, fib)];
        default:
            return 0;
    }
}

// Calculate the Fibonacci sequence up to n using dynamic programming
void fibonacci(int n, int* fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    // Create the nodes for the arithmetic operations and Fibonacci sequence
    Node* add = makeNode(ADD, makeNode(FIBO, makeNode(SUB, makeNode(MUL, NULL, NULL), NULL), NULL), makeNode(FIBO, NULL, NULL));
    Node* mul = makeNode(MUL, makeNode(FIBO, NULL, NULL), makeNode(FIBO, NULL, NULL));
    Node* sub = makeNode(SUB, mul, add);
    Node* fibo = makeNode(FIBO, sub, NULL);

    // Calculate the Fibonacci sequence up to the required size
    int n = calc(fibo, NULL);
    int* fib = (int*)malloc((n+1) * sizeof(int));
    fibonacci(n, fib);

    // Calculate the results of the arithmetic operations and Fibonacci sequence
    int addResult = calc(add, fib);
    int mulResult = calc(mul, fib);
    int subResult = calc(sub, fib);
    int fiboResult = calc(fibo, fib);

    // Print the results
    printf("add: %d\n", addResult);
    printf("mul: %d\n", mulResult);
    printf("sub: %d\n", subResult);
    printf("fibo: %d\n", fiboResult);

    // Free memory
    free(fib);

    return 0;
}

#include <stdio.h>
#include <time.h>

#define MAX 1000
int memo[MAX];

int fib_memo(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

void limpar_memo() {
    int i;
    for (i = 0; i < MAX; i++) memo[i] = -1;
}

int main() {
    int n = 40;

    limpar_memo();
    clock_t start = clock();
    int resultado = fib_memo(n);
    clock_t end = clock();

    double tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Fibonacci com memoizacao (%d): %d\n", n, resultado);
    printf("Tempo: %f segundos\n", tempo);

    return 0;
}

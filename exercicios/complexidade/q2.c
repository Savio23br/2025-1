#include <stdio.h>
#include <time.h>

int fib_iterativo(int n) {
    if (n <= 1) return 1;
    int a = 1, b = 1, c;
    int i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 40;
    int repeticoes = 10;
    clock_t start, end;
    double total_time = 0.0;
    int i;
    for ( i = 0; i < repeticoes; i++) {
        start = clock();
        int resultado = fib_iterativo(n);
        end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        total_time += time_taken;

        printf("Execução %d: resultado = %d, tempo = %.6f segundos\n", i + 1, resultado, time_taken);
    }

    double tempo_medio = total_time / repeticoes;
    printf("Tempo médio para %d execuções: %.6f segundos\n", repeticoes, tempo_medio);

    return 0;
}

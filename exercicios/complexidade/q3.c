#include <stdio.h>
#include <math.h>
#include <time.h>

int fib_binet(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return (int)(pow(phi, n + 1) / sqrt(5) + 0.5);
}

int main() {
    int n = 40;
    int repeticoes = 100000;  
    clock_t inicio, fim;
    double tempo_total = 0.0;

    inicio = clock();
    int i;
    for (i = 0; i < repeticoes; i++) {
        fib_binet(n);
    }
    fim = clock();

    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    double tempo_medio = tempo_total / repeticoes;

    printf("Tempo total para %d execuções: %.8f segundos\n", repeticoes, tempo_total);
    printf("Tempo médio por execução: %.12f segundos\n", tempo_medio);

    return 0;
}

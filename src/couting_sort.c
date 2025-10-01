#include "couting_sort.h"

void counting_sort(int vetor[], int n) {
    if (n <= 0) return;

    int i;
    int max = vetor[0];
    for (i = 1; i < n; i++) {
        if (vetor[i] > max) max = vetor[i];
    }

    if (max < 0) {
        printf("Erro: Counting Sort não suporta números negativos.\n");
        exit(1);
    }

    int *count = (int*) calloc(max + 1, sizeof(int));
    if (!count) {
        printf("Erro: memória insuficiente para Counting Sort.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) count[vetor[i]]++;
    int idx = 0;
    for (i = 0; i <= max; i++) {
        while (count[i]--) {
            vetor[idx++] = i;
        }
    }

    free(count);
}

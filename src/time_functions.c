#include "time_functions.h"

#define TAM 10001

// Função genérica para medir tempo (algoritmos que recebem sort_func(int*, int))
double medir_tempo(void (*sort_func)(int*, int), int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        if (!temp) {
            printf("Erro: memória insuficiente.\n");
            exit(1);
        }
        memcpy(temp, vetor, sizeof(int) * n);

        sort_func(temp, n);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

// Medição para QuickSort
double medir_tempo_quick(int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        memcpy(temp, vetor, sizeof(int) * n);

        quick_sort(temp, 0, n - 1);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

// Medição para MergeSort
double medir_tempo_merge(int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        memcpy(temp, vetor, sizeof(int) * n);

        merge_sort(temp, 0, n - 1);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

double medir_tempo_counting(int vetor[], int n, int rep) {
    if (n <= 0 || n > TAM) {
        printf("Erro: tamanho inválido do vetor (%d)\n", n);
        exit(1);
    }

    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        if (!temp) {
            printf("Erro: memória insuficiente.\n");
            exit(1);
        }
        memcpy(temp, vetor, sizeof(int) * n);

        counting_sort(temp, n);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

double medir_tempo_bucket(int vetor[], int n, int rep) {
    if (n <= 0 || n > TAM) {
        printf("Erro: tamanho inválido do vetor (%d)\n", n);
        exit(1);
    }

    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        if (!temp) {
            printf("Erro: memória insuficiente.\n");
            exit(1);
        }
        memcpy(temp, vetor, sizeof(int) * n);

        bucket_sort(temp, n);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

double medir_tempo_radix(int vetor[], int n, int rep) {
    if (n <= 0 || n > TAM) {
        printf("Erro: tamanho inválido do vetor (%d)\n", n);
        exit(1);
    }

    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = (int*) malloc(sizeof(int) * n);
        if (!temp) {
            printf("Erro: memória insuficiente.\n");
            exit(1);
        }
        memcpy(temp, vetor, sizeof(int) * n);

        radix_sort(temp, n);

        free(temp);
    }

    clock_t fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

int carregar_vetor(const char *filename, int vetor[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }
    int n = 0;
    while (fscanf(file, "%d", &vetor[n]) != EOF) n++;
    fclose(file);
    return n;
}

void salvar_vetor(const char *filename, int vetor[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo %s.\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) fprintf(file, "%d\n", vetor[i]);
    fclose(file);
}
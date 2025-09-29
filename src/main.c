#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

#define TAM 10001

void bubble_sort(int vetor[], int n);
void quick_sort(int vetor[], int inicio, int fim);
void merge_sort(int vetor[], int inicio, int fim);


// Função para ler vetor do arquivo
int carregar_vetor(const char *filename, int vetor[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }
    int n = 0;
    while (fscanf(file, "%d", &vetor[n]) != EOF) {
        n++;
    }
    fclose(file);
    return n;
}

// Função para salvar vetor ordenado em arquivo
void salvar_vetor(const char *filename, int vetor[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo %s.\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", vetor[i]);
    }
    fclose(file);
}

// Função genérica para medir tempo com repetição
double medir_tempo(void (*sort_func)(int*, int), int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        // Criar cópia do vetor para não modificar o original
        int *temp = malloc(sizeof(int) * n);
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

double medir_tempo_quick(int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = malloc(sizeof(int) * n);
        memcpy(temp, vetor, sizeof(int) * n);
        quick_sort(temp, 0, n - 1);
        free(temp);
    }

    clock_t fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}

double medir_tempo_merge(int vetor[], int n, int rep) {
    clock_t inicio = clock();

    for (int i = 0; i < rep; i++) {
        int *temp = malloc(sizeof(int) * n);
        memcpy(temp, vetor, sizeof(int) * n);
        merge_sort(temp, 0, n - 1);
        free(temp);
    }

    clock_t fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / rep;
}


int main(void) {
    printf("Carregando dados do arquivo:\n");
    const char *input_file = "instancias-num/num.1000.1.in";
    
    // Vetores para cada algoritmo
    int vetor_original[TAM];
    int vetor_bubble[TAM], vetor_selection[TAM], vetor_insertion[TAM];
    int vetor_quick[TAM], vetor_merge[TAM], vetor_heap[TAM];

    // Carregar dados do arquivo
    int n = carregar_vetor(input_file, vetor_original);

    // Criar cópias para cada algoritmo
    for (int i = 0; i < n; i++) {
        vetor_bubble[i] = vetor_selection[i] = vetor_insertion[i] =
        vetor_quick[i]  = vetor_merge[i]    = vetor_heap[i] = vetor_original[i];
    }

    // Testar Bubble Sort
    double tempo = medir_tempo(bubble_sort, vetor_bubble, n, 10);
    printf("Tempo de execucao do Bubble Sort:   %.9lf segundos\n", tempo);

    tempo = medir_tempo(selection_sort, vetor_selection, n, 10);
    printf("Tempo de execucao do Selection Sort: %.9lf segundos\n", tempo);

    tempo = medir_tempo(insertion_sort, vetor_insertion, n, 10);
    printf("Tempo de execucao do Insertion Sort: %.9lf segundos\n", tempo);

    tempo = medir_tempo_quick(vetor_quick, n, 10);
    printf("Tempo de execucao do Quick Sort:     %.9lf segundos\n", tempo);

    tempo = medir_tempo_merge(vetor_merge, n, 10);
    printf("Tempo de execucao do Merge Sort:     %.9lf segundos\n", tempo);

    tempo = medir_tempo(heap_sort, vetor_heap, n, 10);
    printf("Tempo de execucao do Heap Sort:      %.9lf segundos\n", tempo);


    printf("\nOrdenacao concluida!\n");
    return 0;
}

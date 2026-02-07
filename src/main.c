#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time_functions.h"

#define TAM 10001


int main(void) {
    printf("Carregando dados do arquivo:\n");
    const char *input_file = "instancias-num/d.txt";

    int vetor_original[TAM];
    int vetor_bubble[TAM], vetor_selection[TAM], vetor_insertion[TAM];
    int vetor_quick[TAM], vetor_merge[TAM], vetor_heap[TAM];
    int vetor_counting[TAM], vetor_bucket[TAM], vetor_radix[TAM];

    int n = carregar_vetor(input_file, vetor_original);

    for (int i = 0; i < n; i++) {
        vetor_bubble[i] = vetor_selection[i] = vetor_insertion[i] =
        vetor_quick[i] = vetor_merge[i] = vetor_heap[i] =
        vetor_counting[i] = vetor_bucket[i] = vetor_original[i] =
        vetor_radix[i] = vetor_original[i];
    }

    double tempo;

    tempo = medir_tempo(bubble_sort, vetor_bubble, n, 10);
    printf("Bubble Sort:   %.9lf s\n", tempo);

    tempo = medir_tempo(selection_sort, vetor_selection, n, 10);
    printf("Selection Sort: %.9lf s\n", tempo);

    tempo = medir_tempo(insertion_sort, vetor_insertion, n, 10);
    printf("Insertion Sort: %.9lf s\n", tempo);

    tempo = medir_tempo_quick(vetor_quick, n, 10);
    printf("Quick Sort:     %.9lf s\n", tempo);

    tempo = medir_tempo_merge(vetor_merge, n, 10);
    printf("Merge Sort:     %.9lf s\n", tempo);

    tempo = medir_tempo(heap_sort, vetor_heap, n, 10);
    printf("Heap Sort:      %.9lf s\n", tempo);

    //tempo = medir_tempo_counting(vetor_counting, n, 10);
    //printf("Counting Sort:  %.9lf s\n", tempo);

    tempo = medir_tempo_bucket(vetor_bucket, n, 10);
    printf("Bucket Sort:    %.9lf s\n", tempo);

    //tempo = medir_tempo_radix(vetor_radix, n, 10);
    // printf("Radix Sort:     %.9lf s\n", tempo);

    printf("\nOrdenacao concluida!\n");

    return 0;
}

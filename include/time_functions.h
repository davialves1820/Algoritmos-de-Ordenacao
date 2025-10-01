#ifndef TIME_FUNCTIONS_H
#define TIME_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "bucket_sort.h"
#include "couting_sort.h"
#include "radix_sort.h"

// Função genérica para medir tempo (algoritmos que recebem sort_func(int*, int))
double medir_tempo(void (*sort_func)(int*, int), int vetor[], int n, int rep);

// Medição para QuickSort (recebe low e high)
double medir_tempo_quick(int vetor[], int n, int rep);

// Medição para MergeSort (recebe low e high)
double medir_tempo_merge(int vetor[], int n, int rep);

double medir_tempo_counting(int vetor[], int n, int rep);

// Medição para Bucket Sort (int[])
double medir_tempo_bucket(int vetor[], int n, int rep);

// Medição para Radix Sort
double medir_tempo_radix(int vetor[], int n, int rep);

int carregar_vetor(const char *filename, int vetor[]);

void salvar_vetor(const char *filename, int vetor[], int n);

#endif
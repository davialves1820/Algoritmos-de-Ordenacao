#include "quick_sort.h"
#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivo = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while(arr[i] < pivo);

        do {
            j--;
        } while(arr[j] > pivo);

        if (i>= j) {
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi);
        quick_sort(arr, pi + 1, high);
    }
}
#include "insertion_sort.h"

void insertion_sort(int v[], int tam) {
    
    for (int i = 1; i < tam; i++) {

        int pivo = v[i]; // Pivô para salvar o elemento atual
        int j = i - 1; // j começa uma posição antes de i

        // Enquanto a posição antes do pivô conter um valor superior ou chegar ao fim do vetor
        while (j >= 0 && v[j] > pivo) { 
            
            v[j + 1] = v[j]; // Faz um reordenamento da esquerda para direita
            j--; // Decrementa j
        }

        v[j+1] = pivo; // O pivô é realocado para a que antes dele não esteja nenhum valor superior
    }
}
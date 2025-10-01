#include "radix_sort.h"

void radix_sort(int ar[], int t) {
    int maior, i, j, idx;

    //procurar maior valor 
    maior = ar[0];
    
    for(i = 1; i < t; i++) {
        if (ar[i] > maior) {
            maior = ar[i];
        }
    }

    int lista[10][t];
    int q_lista[10] = {0};

    idx = 1;
    int l, k = 0;
    
    while(maior/idx > 0){
        
        //distribuicao
        for(i = 0; i < t; i++) {
            l = ar[i]/idx % 10;
            lista[l][q_lista[l]] = ar[i];
            q_lista[l]++;
        }

        //recuperacao
        k = 0;
        for(i = 0; i < 10; i++) {
            for(j = 0; j < q_lista[i]; j++) {
                ar[k++] = lista[i][j];
            }
        }

        //zera listas
        memset(q_lista, 0, sizeof(int)*10);

        idx *= 10;
    }

}
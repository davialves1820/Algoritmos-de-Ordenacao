#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time_functions.h"
#include "instancias.h"

#define TAM 100001
#define REPETICOES 1

void salvar_resultado_csv(FILE *csv, const char *tipo,
                          int n, double sel, double ins,
                          double quick, double merge) {

    fprintf(csv, "%s,%d,%.9lf,%.9lf,%.9lf,%.9lf\n",
            tipo, n, sel, ins, quick, merge);
}

void testar_instancia(FILE *csv, const char *tipo, int n) {

    char nomeArquivo[150];
    sprintf(nomeArquivo, "instancias/%s_%d.txt", tipo, n);

    int vetor_original[TAM];
    int v_sel[TAM], v_ins[TAM], v_quick[TAM], v_merge[TAM];

    int tamanho = carregar_vetor(nomeArquivo, vetor_original);

    for (int i = 0; i < tamanho; i++) {
        v_sel[i] = vetor_original[i];
        v_ins[i] = vetor_original[i];
        v_quick[i] = vetor_original[i];
        v_merge[i] = vetor_original[i];
    }

    double tempo_sel = medir_tempo(selection_sort, v_sel, tamanho, REPETICOES);
    double tempo_ins = medir_tempo(insertion_sort, v_ins, tamanho, REPETICOES);
    double tempo_quick = medir_tempo_quick(v_quick, tamanho, REPETICOES);
    double tempo_merge = medir_tempo_merge(v_merge, tamanho, REPETICOES);

    printf("%s %d concluido.\n", tipo, n);

    salvar_resultado_csv(csv, tipo, n,
                         tempo_sel, tempo_ins,
                         tempo_quick, tempo_merge);
}

int main() {

    srand(time(NULL));

    //gerar_instancias(); // Só precisa ser descomentado na primeira execução para gerar as instâncias

    FILE *csv = fopen("resultados.csv", "w");
    if (!csv) {
        printf("Erro ao criar CSV!\n");
        return 1;
    }

    fprintf(csv, "Tipo,Tamanho,Selection,Insertion,Quick,Merge\n");

    int tamanhos[] = {1000, 0000,5000, 1 50000, 100000};
    int qtd = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const char *tipos[] = {"aleatorio", "repetido", "ordenado", "inverso"};

    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < qtd; i++) {
            testar_instancia(csv, tipos[t], tamanhos[i]);
        }
    }

    fclose(csv);

    printf("\nTodos os testes finalizados!\n");
    printf("Resultados salvos em resultados.csv\n");

    return 0;
}

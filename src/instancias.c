#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "instancias.h"

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #define MKDIR(dir) mkdir(dir, 0777)
#endif

/* ============================
   Criar pasta
   ============================ */
void criar_pasta_instancias() {
    MKDIR("instancias");
}

/* ============================
   Geração base
   ============================ */

void gerarAleatorio(int n, const char *nome) {
    FILE *arq = fopen(nome, "w");
    if (!arq) return;
    for (int i = 0; i < n; i++)
        fprintf(arq, "%d ", rand() % 100000);
    fclose(arq);
}

void gerarRepetido(int n, const char *nome) {
    FILE *arq = fopen(nome, "w");
    if (!arq) return;
    for (int i = 0; i < n; i++)
        fprintf(arq, "%d ", rand() % 5);
    fclose(arq);
}

void gerarOrdenado(int n, const char *nome) {
    FILE *arq = fopen(nome, "w");
    if (!arq) return;
    for (int i = 0; i < n; i++)
        fprintf(arq, "%d ", i);
    fclose(arq);
}

void gerarInverso(int n, const char *nome) {
    FILE *arq = fopen(nome, "w");
    if (!arq) return;
    for (int i = n; i > 0; i--)
        fprintf(arq, "%d ", i);
    fclose(arq);
}

/* ============================
   Gerar todas as instâncias
   ============================ */

void gerar_instancias() {

    int tamanhos[] = {1000, 5000, 10000, 50000, 100000};
    int qtd = sizeof(tamanhos) / sizeof(tamanhos[0]);
    char nome[150];

    criar_pasta_instancias();

    for (int i = 0; i < qtd; i++) {
        int n = tamanhos[i];

        sprintf(nome, "instancias/aleatorio_%d.txt", n);
        gerarAleatorio(n, nome);

        sprintf(nome, "instancias/repetido_%d.txt", n);
        gerarRepetido(n, nome);

        sprintf(nome, "instancias/ordenado_%d.txt", n);
        gerarOrdenado(n, nome);

        sprintf(nome, "instancias/inverso_%d.txt", n);
        gerarInverso(n, nome);
    }

    printf("Instancias geradas dentro da pasta /instancias\n");
}

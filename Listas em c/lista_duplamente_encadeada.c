#include <stdio.h>
#include <stdlib.h>

typedef struct lista_duplamente_encadeada {
    int info;
    struct lista_duplamente_encadeada* ant;
    struct lista_duplamente_encadeada* prox;
} lista_duplamente_encadeada;

void inicializar(lista_duplamente_encadeada* l) {
    l->ant = NULL;
    l->prox = NULL;
}

lista_duplamente_encadeada* inserir(lista_duplamente_encadeada* l, int i) {
    lista_duplamente_encadeada* novo = (lista_duplamente_encadeada*) malloc (sizeof(lista_duplamente_encadeada));
    novo->info = i;
    novo->prox = l;
    novo->ant = NULL;

    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

lista_duplamente_encadeada* busca(lista_duplamente_encadeada* l, int v) {
    lista_duplamente_encadeada* p = l;

    while (p != NULL) {
        if (p->info == v) {
            return p;
        }
        p = p->prox;
    }
    return NULL;
}

lista_duplamente_encadeada* retirar(lista_duplamente_encadeada* l, int v) {
    lista_duplamente_encadeada* p = busca(l, v);

    if (p == NULL) {
        return l;
    }

    if (p == l) {
        l = p->prox;
    } else {
        p->ant->prox = p->prox;
    }

    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    }

    free(p);

    return l;
}

int main(void) {



    return 0;
}
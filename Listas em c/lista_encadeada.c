#include <stdio.h>
#include <stdlib.h>

// Define a estrutura de uma lista encadeada
typedef struct {
    int info;                        // Informação armazenada no nó
    struct lista_encadeada* prox;    // Ponteiro para o próximo nó na lista
} lista_encadeada;

// Inicializa a lista encadeada, retornando NULL (lista vazia)
lista_encadeada* inicializar() {
    return NULL;
}

// Cria um novo nó
lista_encadeada* criar_novo(int v) {
    lista_encadeada* n = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    n->info = v;
    return n;
}

// Insere a lista mantendo uma ordenação
lista_encadeada* inserir_ordenado(lista_encadeada* l, int v) {
    lista_encadeada* novo = criar_novo(v);  // Cria um novo nó
    lista_encadeada* ant = NULL;            // Variável que se refere ao nó anterior
    lista_encadeada* prox = l;              // Variável que se refere ao próximo nó

    // Looping até encontrar a posição correta onde o nó deve ser inserido
    while (prox != NULL && prox->info < v) {
        ant = prox;             // Atualiza o ponteiro para o nó anterior
        prox = prox->prox;      // Atualiza o ponteiro para o próximo nó
    }

    // Verifica se o nó deve ser inserido na primeira posição
    if (ant == NULL) {
        novo->prox = prox;
        l = novo;
    } else { // Caso o nó for inserido numa posição sem ser o início
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

// Insere um novo elemento no início da lista
lista_encadeada* inserir(lista_encadeada* l, int i) {
    lista_encadeada* novo = (lista_encadeada*) malloc(sizeof(lista_encadeada)); // Aloca memória para um novo nó
    novo->info = i;  // Define o valor do novo nó
    novo->prox = l;  // Faz o próximo nó do novo elemento apontar para a cabeça atual da lista
    return novo;     // Retorna o novo nó como a nova cabeça da lista
}

// Imprime todos os elementos da lista
void imprimir(lista_encadeada* l) {
    lista_encadeada* p = l;  // Ponteiro auxiliar para percorrer a lista

    while (p != NULL) {      // Enquanto não for o final da lista
        printf("%d ", p->info); // Imprime o valor do nó atual
        p = p->prox;            // Avança para o próximo nó
    }
    printf("\n");
}

// Busca um elemento na lista pelo valor informado
lista_encadeada* buscar(lista_encadeada* l, int v) {
    lista_encadeada* p = l;  // Ponteiro auxiliar para percorrer a lista

    while (p != NULL) {      // Enquanto não for o final da lista
        if (p->info == v) {  // Verifica se o valor do nó atual corresponde ao valor procurado
            return p;        // Retorna o nó encontrado
        }
        p = p->prox;         // Avança para o próximo nó
    }
    return NULL;             // Retorna NULL se o elemento não for encontrado
}

// Retira um elemento da lista com base no valor informado
lista_encadeada* retirar(lista_encadeada* l, int v) {
    lista_encadeada* anterior = NULL; // Ponteiro para o nó anterior ao atual
    lista_encadeada* p = l;           // Ponteiro para o nó atual

    // Procura o nó com o valor correspondente
    while (p != NULL && p->info != v) {
        anterior = p;     // Atualiza o ponteiro para o nó anterior
        p = p->prox;      // Avança para o próximo nó
    }

    if (p == NULL) {      // Elemento não encontrado
        return l;         // Retorna a lista sem alterações
    } else if (anterior == NULL) { // O elemento a ser removido é o primeiro da lista
        l = p->prox;      // Atualiza a cabeça da lista
    } else {              // O elemento não é o primeiro da lista
        anterior->prox = p->prox; // Faz o nó anterior apontar para o próximo nó
    }
    free(p);              // Libera a memória do nó removido
    return l;             // Retorna a lista atualizada
}

// Libera toda a memória alocada para a lista
void libera(lista_encadeada* l) {
    lista_encadeada* p = l;  // Ponteiro auxiliar para percorrer a lista

    while (p != NULL) {      // Enquanto não for o final da lista
        lista_encadeada* t = p->prox; // Salva o próximo nó
        free(p);            // Libera o nó atual
        p = t;              // Avança para o próximo nó
    }
}

// Função principal para testar as funções da lista encadeada
int main(void) {
    lista_encadeada* l;               // Declara um ponteiro para a lista
    l = inicializar();                // Inicializa a lista como vazia
    l = inserir_ordenado(l, 2);       // Insere o valor 2 na lista
    l = inserir_ordenado(l, 5);       // Insere o valor 5 na lista
    l = inserir_ordenado(l,4);
    imprimir(l);                      // Imprime os valores da lista
    l = retirar(l, 2);                // Retira o valor 2 da lista
    imprimir(l);                      // Imprime os valores da lista
    libera(l);                        // Libera a memória alocada pela lista
    return 0;                         // Encerra o programa
}

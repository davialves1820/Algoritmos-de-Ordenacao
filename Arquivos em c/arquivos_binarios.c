#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f1 = fopen("../input/Gravando.m4a", "rb");
    FILE *f2 = fopen("../saida/escrita.m4a", "wb");

    if (f1 == NULL || f2 == NULL) {
        printf("Erro ao abrir");
        exit(1);
    }

    char buffer[1024]; // Buffer para armazenar temporariamente os dados
    size_t bytesRead; // Armazena o número de bytes realmente lidos do arquivo em cada iteração do loop.
    //size_t: Um tipo de dado usado para representar tamanhos ou quantidades (não negativo).
    // É retornado por funções como fread, fwrite e sizeof.

/*fread: Lê dados de um arquivo e os armazena no buffer.

buffer: O local onde os dados lidos serão armazenados.
1: O tamanho de cada elemento a ser lido (em bytes). Aqui, estamos lendo byte a byte.
sizeof(buffer): O número máximo de bytes a serem lidos (tamanho do buffer).
f1: O ponteiro para o arquivo de entrada, de onde os dados serão lidos.
O que fread retorna?
Retorna o número total de elementos lidos com sucesso.
Nesse caso, retorna o número de bytes lidos (máximo de 1024).
Se fread não conseguir ler mais nada (final do arquivo ou erro), retornará 0.
*/

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
        fwrite(buffer, 1, bytesRead, f2);
    }

/*fwrite: Escreve dados no arquivo de saída.

buffer: O local de onde os dados serão escritos.
1: O tamanho de cada elemento a ser escrito (em bytes).
bytesRead: O número de bytes lidos anteriormente (e que serão agora escritos).
f2: O ponteiro para o arquivo de saída, onde os dados serão escritos.
*/

    fclose(f1);
    fclose(f2);

    printf("Encerrado");

    return 0;
}
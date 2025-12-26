#include <stdio.h>
#include <stdlib.h>
//matriz de 5x10
char** mapa[5][10+1];// por causa do /0
int linhas;
int colunas;
int main() {
    FILE* f;
    f = fopen("mapa.txt","r");
    if(f == 0) {
        printf("Mapa não encontrado");
        exit(1);
    }
    fscanf(f,"%d %d", &linhas, &colunas);
    //lê os dois números que inforam qual qtd de linhas e colunas
    printf("linhas %d colunas %d\n", linhas, colunas);
    //alocação de memória dinâmica utilizando a função malloc
    // no caso de variáveis, o sistema sabe o tamanho pois elas têm tamanho fixo conforme arquitetura. 
    char** mapa = malloc(sizeof(char) * linhas); 
    for(int i = 0; i < linhas; i++) {
        mapa[i] = malloc(sizeof((char) + 1) * colunas);
    }
    // utiliza o for para percorrer as linhas na linha 19
    // pra alocar memória para um array, basta multiplicar pelo tamanho do array.
    //sizeof define quantos bytes um tipo primitivo precisa
    for(int i = 0; i < linhas;i++) {    
        fscanf(f, "%s\n", mapa[i]);
    }
    for(int i = 0; i < linhas;i++) {    
       printf("%s\n", mapa[i]);
    }
    fclose(f);
    for(int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    // libera memória para todas as linhas
    free(mapa);
    //libera memória do ponteiro
    return 0;
}
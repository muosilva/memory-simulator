#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>
#include <stdbool.h> 

#define TAMANHO_MEMORIA 1024

typedef struct BlocoMemoria {
    size_t inicio;
    size_t tamanho;
    bool livre; 
    struct BlocoMemoria* proximo;
} BlocoMemoria;

void inicializa_memoria();
void* aloca(size_t tamanho);
void desaloca(void* endereco);
void exibe_memoria();

#endif 
/*
int main() {
    inicializa_memoria();

    printf("Memória inicial:\n");
    exibe_memoria();

    aloca(200);
    printf("\nApós alocar 200 bytes:\n");
    exibe_memoria();

    aloca(300);
    printf("\nApós alocar 300 bytes:\n");
    exibe_memoria();

    void* bloco1 = aloca(100);
    desaloca(bloco1);
    printf("\nApós desalocar o bloco de 100 bytes:\n");
    exibe_memoria();

    return 0;
} */
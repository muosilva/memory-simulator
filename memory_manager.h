#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>
#include <stdbool.h>

#define TAMANHO_MEMORIA 1024 // Defina o tamanho da memória simulada

// Estrutura para representar um bloco de memória
typedef struct BlocoMemoria {
    size_t inicio;
    size_t tamanho;
    bool livre;
    struct BlocoMemoria* proximo;
} BlocoMemoria;

// Funções para gerenciar a memória
void inicializa_memoria();
void* aloca(size_t tamanho);
void desaloca(void* endereco);
void exibe_memoria();

#endif // MEMORY_MANAGER_H

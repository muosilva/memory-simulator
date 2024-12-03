#include "memory_manager.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static char memoria[TAMANHO_MEMORIA]; // Memória simulada
static BlocoMemoria lista_blocos[TAMANHO_MEMORIA]; // Lista de blocos de memória
static BlocoMemoria* cabeca = NULL; // Cabeça da lista de blocos

// Inicializa a memória simulada e os blocos de memória
void inicializa_memoria() {
    cabeca = &lista_blocos[0];
    cabeca->inicio = 0;
    cabeca->tamanho = TAMANHO_MEMORIA;
    cabeca->livre = true;
    cabeca->proximo = NULL;
}

// Função de alocação de memória
void* aloca(size_t tamanho) {
    BlocoMemoria* atual = cabeca;

    while (atual) {
        // Se o bloco estiver livre e tiver tamanho suficiente
        if (atual->livre && atual->tamanho >= tamanho) {
            // Se o bloco for maior que o necessário, divide
            if (atual->tamanho > tamanho) {
                BlocoMemoria* novo_bloco = &lista_blocos[atual - lista_blocos + 1];
                novo_bloco->inicio = atual->inicio + tamanho;
                novo_bloco->tamanho = atual->tamanho - tamanho;
                novo_bloco->livre = true;
                novo_bloco->proximo = atual->proximo;
                atual->proximo = novo_bloco;
            }

            // Atualiza o bloco atual
            atual->tamanho = tamanho;
            atual->livre = false;
            return &memoria[atual->inicio]; // Retorna o ponteiro para a memória alocada
        }
        atual = atual->proximo;
    }

    fprintf(stderr, "Erro: Memória insuficiente\n");
    return NULL;
}

// Função para desalocar memória
void desaloca(void* endereco) {
    if (!endereco) {
        fprintf(stderr, "Erro: Endereço inválido\n");
        return;
    }

    size_t pos = (char*)endereco - memoria;
    BlocoMemoria* atual = cabeca;

    while (atual) {
        if (atual->inicio == pos) {
            atual->livre = true;

            // Verifica se o próximo bloco também está livre, para fundir os blocos
            if (atual->proximo && atual->proximo->livre) {
                atual->tamanho += atual->proximo->tamanho;
                atual->proximo = atual->proximo->proximo;
            }
            return;
        }
        atual = atual->proximo;
    }

    fprintf(stderr, "Erro: Endereço inválido\n");
}

// Função para exibir a memória de maneira simplificada
void exibe_memoria() {
    size_t memoria_livre = 0;
    int blocos_livres = 0;
    BlocoMemoria* atual = cabeca;

    printf("Estado da Memória:\n");
    while (atual) {
        if (atual->livre) {
            memoria_livre += atual->tamanho;
            blocos_livres++;
        }
        atual = atual->proximo;
    }

    printf("Memória livre: %zu bytes em %d blocos.\n", memoria_livre, blocos_livres);
}

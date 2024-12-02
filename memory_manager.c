#include "memory_manager.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static char memoria[TAMANHO_MEMORIA];

static BlocoMemoria lista_blocos[TAMANHO_MEMORIA];
static BlocoMemoria* cabeca = NULL;

void inicializa_memoria() {
    cabeca = &lista_blocos[0];
    cabeca->inicio = 0;
    cabeca->tamanho = TAMANHO_MEMORIA;
    cabeca->livre = true;
    cabeca->proximo = NULL;
}

void* aloca(size_t tamanho) {
    BlocoMemoria* atual = cabeca;

    while (atual) {
        if (atual->livre && atual->tamanho >= tamanho) {
            if (atual->tamanho > tamanho) {
                BlocoMemoria* novo_bloco = &lista_blocos[atual - lista_blocos + 1];
                novo_bloco->inicio = atual->inicio + tamanho;
                novo_bloco->tamanho = atual->tamanho - tamanho;
                novo_bloco->livre = true;
                novo_bloco->proximo = atual->proximo;

                atual->proximo = novo_bloco;
            }

            atual->tamanho = tamanho;
            atual->livre = false;
            return &memoria[atual->inicio];
        }
        atual = atual->proximo;
    }

    fprintf(stderr, "Erro: Memória insuficiente\n");
    return NULL;
}

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

void exibe_memoria() {
    BlocoMemoria* atual = cabeca;

    printf("Estado da Memória:\n");
    while (atual) {
        printf("Início: %zu, Tamanho: %zu, Livre: %s\n",
               atual->inicio, atual->tamanho, atual->livre ? "Sim" : "Não");
        atual = atual->proximo;
    }
}
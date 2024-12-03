#include "memory_manager.h"
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista encadeada
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Função para inicializar a lista encadeada
No* inicializa_lista() {
    return NULL;
}

// Função para adicionar um nó no início da lista
No* adiciona_no_inicio(No* lista, int valor) {
    No* novo_no = (No*)aloca(sizeof(No)); // Aloca memória para o nó
    if (novo_no == NULL) {
        printf("Erro ao alocar memória!\n");
        return lista;
    }
    novo_no->valor = valor;
    novo_no->proximo = lista; // Aponta para o nó anterior
    return novo_no;
}

// Função para exibir a lista encadeada
void exibe_lista(No* lista) {
    No* atual = lista;
    printf("Lista encadeada: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para remover o primeiro nó da lista
No* remove_do_inicio(No* lista) {
    if (lista == NULL) {
        printf("A lista está vazia!\n");
        return NULL;
    }
    No* temp = lista;
    lista = lista->proximo;
    desaloca(temp); // Libera a memória do nó removido
    return lista;
}

// Função para liberar a lista inteira
void libera_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        desaloca(temp); // Libera a memória de cada nó
    }
}

int main() {
    inicializa_memoria();  // Inicializa a memória simulada

    No* lista = inicializa_lista();  // Inicializa a lista encadeada

    // Adiciona elementos na lista
    lista = adiciona_no_inicio(lista, 10);
    lista = adiciona_no_inicio(lista, 20);
    lista = adiciona_no_inicio(lista, 30);

    // Exibe a lista e o estado da memória
    exibe_lista(lista);
    exibe_memoria();

    // Remove o primeiro elemento da lista
    lista = remove_do_inicio(lista);
    exibe_lista(lista);
    exibe_memoria();

    lista = remove_do_inicio(lista);
    exibe_lista(lista);
    exibe_memoria();

    lista = remove_do_inicio(lista);
    exibe_lista(lista);
    exibe_memoria();

    libera_lista(lista);

    return 0;
}

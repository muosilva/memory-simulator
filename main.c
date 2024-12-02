#include "memory_manager.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* inicializa_lista() {
    return NULL;
}

No* adiciona_no_inicio(No* lista, int valor) {
    No* novo_no = (No*)aloca(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória!\n");
        return lista;
    }
    novo_no->valor = valor;
    novo_no->proximo = lista; 
    return novo_no; 
}

void exibe_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

No* remove_do_inicio(No* lista) {
    if (lista == NULL) {
        printf("A lista está vazia!\n");
        return NULL;
    }
    No* temp = lista;
    lista = lista->proximo;  
    desaloca(temp); 
    return lista;
}

void libera_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        desaloca(temp);  
    }
}

int main() {
    No* lista = inicializa_lista();  

    lista = adiciona_no_inicio(lista, 10);
    lista = adiciona_no_inicio(lista, 20);
    lista = adiciona_no_inicio(lista, 30);
    
    printf("Lista encadeada: ");
    exibe_lista(lista);

    lista = remove_do_inicio(lista);
    printf("Lista após remover o primeiro elemento: ");
    exibe_lista(lista);

    libera_lista(lista);

    return 0;
}

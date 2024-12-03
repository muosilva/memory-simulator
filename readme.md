# Memory Simulator

Este projeto simula um **gerenciador de memória** simples usando **memória estática** e **listas encadeadas**. O simulador permite alocar e desalocar blocos de memória de forma semelhante ao gerenciamento de memória em sistemas operacionais.

## Objetivo

O objetivo deste projeto é criar um sistema simples de gerenciamento de memória, onde você pode alocar e desalocar blocos de memória dinamicamente. A memória é gerida utilizando uma lista encadeada, e as operações de alocação e desalocação são simuladas. O projeto foi implementado em **C** e usa uma memória simulada de tamanho fixo.

## Como Funciona

- O gerenciador de memória aloca e desaloca blocos de memória utilizando uma **lista encadeada** de blocos de memória.
- A memória simulada é gerenciada através de uma estrutura `BlocoMemoria` que mantém o controle sobre os blocos de memória alocados e livres.
- A simulação permite visualizar o estado da memória após operações de alocação e desalocação.
- A memória simulada tem um tamanho fixo (definido pela constante `TAMANHO_MEMORIA`).

## Estrutura do Projeto

### Arquivos principais

- `memory_manager.h`: Definições de estruturas e funções para o gerenciamento de memória.
- `memory_manager.c`: Implementação das funções de alocação, desalocação e exibição da memória.
- `main.c`: Implementação do programa principal, que simula a criação de uma lista encadeada usando a memória gerenciada.

## Como Compilar e Executar
    -> gcc -Wall -Wextra -std=c99 -o memoria main.c memory_manager.c
    -> ./memoria
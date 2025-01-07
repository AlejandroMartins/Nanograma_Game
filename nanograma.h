#ifndef NONOGRAMA_H
#define NONOGRAMA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dimensao;        // Dimensão do tabuleiro
    char **tabuleiro;    // Matriz representando o tabuleiro
    int **dicasLinhas;   // Dicas das linhas
    int **dicasColunas;  // Dicas das colunas
    int *tamanhoDicasLinhas;   // Número de dicas em cada linha
    int *tamanhoDicasColunas; // Número de dicas em cada coluna
} Nonograma;

// Funções para manipular o TAD Nonograma
Nonograma* NonogramAllocate(int dimensao) {
    // Alocar memória para o TAD Nonograma
    Nonograma *nonograma = (Nonograma *)malloc(sizeof(Nonograma));
   if (nonograma == NULL) {
        printf("Erro ao alocar Nonograma.\n");
        exit(1);
    }

    nonograma->dimensao = dimensao;

    // Alocar memória para o tabuleiro
    nonograma->tabuleiro = (char **)malloc(dimensao * sizeof(char *));
    for (int i = 0; i < dimensao; i++) {
        nonograma->tabuleiro[i] = (char *)malloc(dimensao * sizeof(char));
        for (int j = 0; j < dimensao; j++) {
            nonograma->tabuleiro[i][j] = '.'; // Inicializar com pontos
        }
    }

    // Alocar memória para as dicas
    nonograma->dicasLinhas = (int **)malloc(dimensao * sizeof(int *));
    nonograma->dicasColunas = (int **)malloc(dimensao * sizeof(int *));
    nonograma->tamanhoDicasLinhas = (int *)malloc(dimensao * sizeof(int));
    nonograma->tamanhoDicasColunas = (int *)malloc(dimensao * sizeof(int));

    for (int i = 0; i < dimensao; i++) {
        nonograma->dicasLinhas[i] = NULL;
        nonograma->dicasColunas[i] = NULL;
        nonograma->tamanhoDicasLinhas[i] = 0;
        nonograma->tamanhoDicasColunas[i] = 0;
    }

    return nonograma;
}

void NonogramFree(Nonograma *nonograma) {
    // Liberar memória do tabuleiro
    for (int i = 0; i < nonograma->dimensao; i++) {
        free(nonograma->tabuleiro[i]);
    }
    free(nonograma->tabuleiro);

    // Liberar memória das dicas
    for (int i = 0; i < nonograma->dimensao; i++) {
        free(nonograma->dicasLinhas[i]);
        free(nonograma->dicasColunas[i]);
    }
    free(nonograma->dicasLinhas);
    free(nonograma->dicasColunas);
    free(nonograma->tamanhoDicasLinhas);
    free(nonograma->tamanhoDicasColunas);

    // Liberar o próprio TAD
    free(nonograma);
}

void NonogramRead (Nonograma *nonograma) {
    printf("Digite as dicas do Nonograma:\n");

    // Lendo as dicas das colunas
    for (int i = 0; i < nonograma->dimensao; i++) {
        printf("Coluna %d: ", i + 1);
        scanf("%d", &nonograma->tamanhoDicasColunas[i]);
        nonograma->dicasColunas[i] = (int *)malloc(nonograma->tamanhoDicasColunas[i] * sizeof(int));
        for (int j = 0; j < nonograma->tamanhoDicasColunas[i]; j++) {
            scanf("%d", &nonograma->dicasColunas[i][j]);
        }
    }
    
    // Lendo as dicas das linhas
    for (int i = 0; i < nonograma->dimensao; i++) {
        printf("Linha %d: ", i + 1);
        scanf("%d", &nonograma->tamanhoDicasLinhas[i]);
        nonograma->dicasLinhas[i] = (int *)malloc(nonograma->tamanhoDicasLinhas[i] * sizeof(int));
        for (int j = 0; j < nonograma->tamanhoDicasLinhas[i]; j++) {
            scanf("%d", &nonograma->dicasLinhas[i][j]);
        }
    }
}


#endif

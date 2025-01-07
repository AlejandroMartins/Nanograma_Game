#include "nonogram.h"

int main() {
    int dimensao;

    // Ler a dimensão do tabuleiro
    printf("Digite a dimensão do tabuleiro: ");
    scanf("%d", &dimensao);

    // Criar o Nonograma
    Nonograma *nonograma = NonogramAllocate(dimensao);

    // Ler as dicas do usuário
    NonogramRead(nonograma);

    // Liberar a memória alocada
    NonogramFree(nonograma);

    return 0;
}

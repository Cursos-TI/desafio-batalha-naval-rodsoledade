#include <stdio.h>

// Definindo constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== Tabuleiro Completo ===\n");
    printf("  ");
    for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Índices das colunas
    }
    printf("\n");
    
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Índices das linhas
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Criando o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Definindo posições fixas para os quatro navios
    // Navio 1 - Vertical
    int navio1_x = 2;
    int navio1_y = 3;
    
    // Navio 2 - Horizontal
    int navio2_x = 5;
    int navio2_y = 7;
    
    // Navio 3 - Diagonal (crescente: baixo-esquerda para cima-direita)
    int navio3_x = 7;
    int navio3_y = 1;
    
    // Navio 4 - Diagonal (decrescente: cima-esquerda para baixo-direita)
    int navio4_x = 0;
    int navio4_y = 8;
    
    // Posicionando Navio 1 (Vertical)
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_x][navio1_y + i] = 3;
    }
    
    // Posicionando Navio 2 (Horizontal)
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_x + i][navio2_y] = 3;
    }
    
    // Posicionando Navio 3 (Diagonal crescente)
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio3_x - i][navio3_y + i] = 3;
    }
    
    // Posicionando Navio 4 (Diagonal decrescente)
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio4_x + i][navio4_y - i] = 3;
    }
    
    // Exibindo as coordenadas dos navios
    printf("=== Posicoes dos Navios ===\n");
    
    printf("\nNavio 1 (Vertical):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", i + 1, navio1_x, navio1_y + i);
    }
    
    printf("\nNavio 2 (Horizontal):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", i + 1, navio2_x + i, navio2_y);
    }
    
    printf("\nNavio 3 (Diagonal crescente):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", i + 1, navio3_x - i, navio3_y + i);
    }
    
    printf("\nNavio 4 (Diagonal decrescente):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", i + 1, navio4_x + i, navio4_y - i);
    }
    
    // Exibindo o tabuleiro completo
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
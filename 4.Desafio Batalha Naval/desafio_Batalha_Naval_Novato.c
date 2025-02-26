#include <stdio.h>

// Definindo constantes para o tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Criando o tabuleiro como uma matriz bidimensional
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Definindo posições fixas para os navios (para o nível novato)
    // Navio 1 - Vertical (3 posições)
    int navio1_x = 2;  // Coordenada X fixa
    int navio1_y = 3;  // Coordenada Y inicial
    
    // Navio 2 - Horizontal (3 posições)
    int navio2_x = 5;  // Coordenada X inicial
    int navio2_y = 7;  // Coordenada Y fixa
    
    // Posicionando o navio vertical
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_x][navio1_y + i] = 1;
    }
    
    // Posicionando o navio horizontal
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_x + i][navio2_y] = 1;
    }
    
    // Exibindo as coordenadas dos navios
    printf("=== Posicoes dos Navios ===\n");
    
    printf("\nNavio 1 (Vertical):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", 
               i + 1, 
               navio1_x, 
               navio1_y + i);
    }
    
    printf("\nNavio 2 (Horizontal):\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao %d: (%d, %d)\n", 
               i + 1, 
               navio2_x + i, 
               navio2_y);
    }
    
    // Exibindo o tabuleiro completo (opcional para visualização)
    printf("\nTabuleiro (0 = agua, 1 = navio):\n");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
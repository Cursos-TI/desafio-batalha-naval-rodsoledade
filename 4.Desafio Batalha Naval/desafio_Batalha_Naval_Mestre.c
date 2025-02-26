#include <stdio.h>

// Definindo constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], const char* titulo) {
    printf("\n=== %s ===\n", titulo);
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

// Função para aplicar habilidade Cone (triângulo para a direita)
void aplicarCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for(int i = 0; i < 3; i++) { // Altura do cone: 3 linhas
        for(int j = 0; j <= i; j++) { // Base cresce à direita
            if(x + i < TAMANHO_TABULEIRO && y + j < TAMANHO_TABULEIRO) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

// Função para aplicar habilidade Cruz (forma de +)
void aplicarCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Linha vertical
    for(int i = -2; i <= 2; i++) {
        if(x + i >= 0 && x + i < TAMANHO_TABULEIRO) {
            tabuleiro[x + i][y] = 1;
        }
    }
    // Linha horizontal
    for(int j = -2; j <= 2; j++) {
        if(y + j >= 0 && y + j < TAMANHO_TABULEIRO) {
            tabuleiro[x][y + j] = 1;
        }
    }
}

// Função para aplicar habilidade Octaedro (diamante 3x3)
void aplicarOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int dist = abs(i) + abs(j); // Distância de Manhattan
            if(dist <= 1 && x + i >= 0 && x + i < TAMANHO_TABULEIRO && 
               y + j >= 0 && y + j < TAMANHO_TABULEIRO) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

int main() {
    // Criando tabuleiros separados para cada habilidade
    int tabuleiroCone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int tabuleiroCruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int tabuleiroOctaedro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Definindo posições iniciais das habilidades (manualmente)
    int cone_x = 2, cone_y = 3;    // Canto superior esquerdo do cone
    int cruz_x = 5, cruz_y = 5;    // Centro da cruz
    int octaedro_x = 8, octaedro_y = 1; // Centro do octaedro
    
    // Aplicando as habilidades
    aplicarCone(tabuleiroCone, cone_x, cone_y);
    aplicarCruz(tabuleiroCruz, cruz_x, cruz_y);
    aplicarOctaedro(tabuleiroOctaedro, octaedro_x, octaedro_y);
    
    // Exibindo os tabuleiros com as áreas afetadas
    exibirTabuleiro(tabuleiroCone, "Tabuleiro - Habilidade Cone");
    exibirTabuleiro(tabuleiroCruz, "Tabuleiro - Habilidade Cruz");
    exibirTabuleiro(tabuleiroOctaedro, "Tabuleiro - Habilidade Octaedro");
    
    return 0;
}
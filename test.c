#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void inicializarMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Habilidade em cruz (alvo central e linhas + colunas)
void habilidadeCruz(int matriz[TAM][TAM], int x, int y, int alcance) {
    for (int i = -alcance; i <= alcance; i++) {
        if (y + i >= 0 && y + i < TAM) matriz[y + i][x] = 1; // vertical
        if (x + i >= 0 && x + i < TAM) matriz[y][x + i] = 1; // horizontal
    }
}

// Cone para baixo (triângulo invertido com vértice no topo)
void habilidadeCone(int matriz[TAM][TAM], int x, int y, int altura) {
    for (int i = 0; i < altura; i++) {
        for (int j = -i; j <= i; j++) {
            int nx = x + j;
            int ny = y + i;
            if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM)
                matriz[ny][nx] = 1;
        }
    }
}

// Octaedro (diamante) baseado em distância de Manhattan
void habilidadeOctaedro(int matriz[TAM][TAM], int x, int y, int raio) {
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (abs(i) + abs(j) <= raio) {
                int nx = x + j;
                int ny = y + i;
                if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM)
                    matriz[ny][nx] = 1;
            }
        }
    }
}

int main() {
    int cruz[TAM][TAM];
    int cone[TAM][TAM];
    int octaedro[TAM][TAM];

    inicializarMatriz(cruz);
    inicializarMatriz(cone);
    inicializarMatriz(octaedro);

    // Define posições centrais e alcances
    habilidadeCruz(cruz, 5, 5, 3);
    habilidadeCone(cone, 4, 2, 4);
    habilidadeOctaedro(octaedro, 7, 7, 3);

    // Exibir as habilidades
    printf("Padrão Cruz:\n");
    exibirMatriz(cruz);
    printf("\nPadrão Cone:\n");
    exibirMatriz(cone);
    printf("\nPadrão Octaedro:\n");
    exibirMatriz(octaedro);

    return 0;
}

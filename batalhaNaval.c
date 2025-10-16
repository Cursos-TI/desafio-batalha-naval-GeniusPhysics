#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("    "); // Espaço inicial para alinhar com os números das linhas
    for (int j = 0; j < 10; j++) {
        printf(" %c ", 'A' + j); // Cabeçalho das colunas (A, B, C, ...)
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d |", i + 1); // Número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navio1[3] = {3,3,3}; // navio horizontal
    int navio2[3] = {3,3,3}; // navio vertical

    int linha1 = 2; // posição inicial do primeiro navio (horizontal)
    int coluna1 = 4;

    int linha2 = 5; // posição inicial do segundo navio (vertical)
    int coluna2 = 7;

   
    // Posiciona o navio 1 (horizontal)
    if (coluna1 + 3 > 10 || linha1 > 10 || linha1 < 0 || coluna1 < 0 ) // Verifica se o navio cabe no tabuleiro
    {
        printf("O navio 1 nao pode ser posicionado aqui\n");
        return 0;
    }
    for(int i = 0; i < 3; i++) {
        if (tabuleiro[linha1][coluna1 + i] != 0){ // Verifica se a posicao ja esta ocupada
            printf("O navio 1 colide com outro navio\n");
            return 0;
        }
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }
    
    // Posiciona o navio 2 (vertical)
    if (linha2 + 3 > 10 || coluna2 > 10 || coluna2 < 0 || linha2 < 0  ) // Verifica se o navio cabe no tabuleiro
    {
        printf("O navio 2 nao pode ser posicionado aqui\n");
        return 0;
    }
    for(int i = 0; i < 3; i++) {
        if (tabuleiro[linha2 + i][coluna2] != 0){ // Verifica se a posicao ja esta ocupada
            printf("O navio 2 colide com outro navio\n");
            return 0;
        }
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    
    exibirTabuleiro(tabuleiro);
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    printf(" Tabuleiro  Nivel Aventureiro: \n\n");
    int navio3[3] = {3,3,3}; // diagonal principal 
    int navio4[3] = {3,3,3}; // diagonal secundária 

    int linha3 = 7; 
    int coluna3 = 1;

    int linha4 = 4; 
    int coluna4 = 2;

    // Posiciona o navio 3 (diagonal principal)
    if (linha3 + 3 > 10  || coluna3 + 3 > 10 || linha3 < 0 || coluna3 < 0 ) { // Verifica se o navio cabe no tabuleiro
        printf("O navio 3 nao pode ser posicionado aqui\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha3 + i][coluna3 + i] != 0) { // Verifica se a posicao ja esta ocupada
            printf("O navio 3 colide com outro navio!\n");
            return 0;
        }
        tabuleiro[linha3 + i][coluna3 + i] = navio3[i];
    }
    
    // Posiciona o navio 4 (diagonal secundária)
    if (linha4 + 3 > 10 || coluna4 - 2 < 0 || linha4 < 0 || coluna4 > 10 ) { // Verifica se o navio cabe no tabuleiro
        printf("O navio 4 nao pode ser posicionado aqui\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha4 + i][coluna4 - i] != 0) { // Verifica se a posicao ja esta ocupada
            printf("O navio 4 colide com outro navio!\n");
            return 0;
        }
        tabuleiro[linha4 + i][coluna4 - i] = navio4[i];

    }

    
    exibirTabuleiro(tabuleiro);



    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}


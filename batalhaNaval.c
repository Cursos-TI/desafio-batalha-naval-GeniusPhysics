#include <stdio.h>
#include <stdlib.h>
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

void exibirHabilidades(int habilidades[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", habilidades[i][j]);
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
     printf("\n Tabuleiro Nivel Mestre - Habilidades Especiais:\n\n");

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    int centro = 2;

    // Preenche CONE (formato triangular)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dx = abs(j - centro);
            int dy = i; // distância vertical do topo
            // A largura cresce 1 unidade a cada linha descendo (até o meio)
            // Condição: estamos dentro dos limites de um "cone" simétrico
            cone[i][j] = (dy >= dx && dy <= 2) ? 1 : 0;
        }
    }

    // Preenche CRUZ (+)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Está na linha ou coluna central?
            cruz[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }

    // Preenche OCTAEDRO (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dx = abs(j - centro);
            int dy = abs(i - centro);
            // O losango é formado onde a soma das distâncias ≤ raio (2)
            octaedro[i][j] = (dx + dy <= 2) ? 1 : 0;
        }
    }
    exibirHabilidades(cone);
    printf("\n");
    exibirHabilidades(cruz);
    printf("\n");
    exibirHabilidades(octaedro);
    printf("\n");

      // Definindo pontos de origem para cada habilidade no tabuleiro
    int origemCone[2] = {3, 3};      // linha, coluna
    int origemCruz[2] = {7, 5};
    int origemOctaedro[2] = {5, 2};

    // Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origemCone[0] + i - 2;   // deslocamento vertical
            int coluna = origemCone[1] + j - 2;  // deslocamento horizontal

            // Verifica se o ponto calculado está dentro do tabuleiro (0 a 9)
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                // Se a habilidade atinge água (0) → marca 1
                // Se atinge navio (3) → marca 5 (impacto)
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 1;
                } else if (cone[i][j] == 1 && tabuleiro[linha][coluna] == 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origemCruz[0] + i - 2;
            int coluna = origemCruz[1] + j - 2;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 1;
                } else if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origemOctaedro[0] + i - 2;
            int coluna = origemOctaedro[1] + j - 2;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 1;
                } else if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro com as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);





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


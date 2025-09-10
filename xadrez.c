#include <stdio.h>

int main() {
    // ===============================
    // Movimentação da Torre (for)
    // ===============================
    int casasTorre = 5; 
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n"); 

    // ===============================
    // Movimentação do Bispo (while)
    // ===============================
    int casasBispo = 5;
    int contadorBispo = 1;

    printf("Movimento do Bispo:\n");
    while (contadorBispo <= casasBispo) {
        printf("Cima, Direita\n");
        contadorBispo++;
    }

    printf("\n"); 

    // ===============================
    // Movimentação da Rainha (do-while)
    // ===============================
    int casasRainha = 8;
    int contadorRainha = 1;

    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    printf("\n");

    // ===============================
    // Movimentação do Cavalo (for + while)
    // ===============================
    // O Cavalo vai andar: 2 casas para baixo e 1 para a esquerda
    int casasBaixo = 2;
    int casasEsquerda = 1;

    printf("Movimento do Cavalo:\n");

    // Primeiro loop (for) para as duas casas para baixo
    for (int i = 1; i <= casasBaixo; i++) {
        printf("Baixo\n");
    }

    // Segundo loop (while) para a casa à esquerda
    int contadorEsquerda = 1;
    while (contadorEsquerda <= casasEsquerda) {
        printf("Esquerda\n");
        contadorEsquerda++;
    }

    return 0;
}
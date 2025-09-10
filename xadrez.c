#include <stdio.h>

/* ============================
   Funções Recursivas
   ============================ */

// Torre: move N casas para a direita (recursão de cauda)
void moverTorreDireitaRec(int n) {
    if (n <= 0) return;            // Caso base evita recursão infinita
    printf("Direita\n");           // Move 1 casa
    moverTorreDireitaRec(n - 1);   // Passo recursivo
}

// Rainha: move N casas para a esquerda (recursão de cauda)
void moverRainhaEsquerdaRec(int n) {
    if (n <= 0) return;
    printf("Esquerda\n");
    moverRainhaEsquerdaRec(n - 1);
}

// Bispo (versão recursiva): N passos na diagonal (Cima + Direita).
// Cada passo imprime duas direções atômicas conforme o padrão exigido.
void moverBispoCimaDireitaRec(int n) {
    if (n <= 0) return;
    printf("Cima\n");
    printf("Direita\n");
    moverBispoCimaDireitaRec(n - 1);
}

/* ============================
   Bispo com Loops Aninhados
   (externo = vertical; interno = horizontal)
   ============================ */
void moverBispoCimaDireitaLoops(int passos) {
    // Para cada "passo diagonal", fazemos 1 movimento vertical e 1 horizontal
    for (int s = 1; s <= passos; s++) {     // Loop externo: vertical
        printf("Cima\n");
        for (int h = 0; h < 1; h++) {       // Loop interno: horizontal (1 vez por passo)
            printf("Direita\n");
        }
    }
}

/* ============================
   Cavalo com Loops Complexos
   - Objetivo: 2 para cima, 1 para a direita (L clássico)
   - Requisitos: loops aninhados, múltiplas variáveis/condições,
     uso de continue e break.
   Estratégia:
     1) Varremos combinações de deltas possíveis do cavalo usando 2 loops.
     2) Usamos 'continue' para pular combinações que não são (-2, +1).
     3) Ao encontrar a combinação desejada, executamos o movimento
        de forma atômica (Cima/Cima/Direita) e usamos 'break' para sair.
   ============================ */
void moverCavaloCimaDireitaComplexo(void) {
    // Conjunto reduzido de deltas típicos do cavalo (vertical, horizontal)
    int deltasY[2] = {-2,  2};  // negativo = para cima; positivo = para baixo
    int deltasX[2] = {-1,  1};  // negativo = esquerda; positivo = direita

    // Flags/contadores auxiliares apenas para demonstrar múltiplas condições
    int movimentosExecutados = 0;
    int limiteMovimentos = 1; // só queremos executar UM L (2 cima, 1 direita)

    for (int i = 0; i < 2; i++) {            // Loop externo: escolher delta vertical
        for (int j = 0; j < 2; j++) {        // Loop interno: escolher delta horizontal
            int dy = deltasY[i];
            int dx = deltasX[j];

            // Condição: queremos exatamente "duas casas para cima" (-2) e "uma para a direita" (+1)
            if (!(dy == -2 && dx == 1)) {
                // Não é a combinação desejada: pule esta iteração
                continue;
            }

            // Se já atingiu o limite (em um cenário mais complexo), encerre
            if (movimentosExecutados >= limiteMovimentos) {
                break; // sai do loop interno
            }

            // Executa o movimento atômico conforme o delta encontrado
            int passosVerticais = dy < 0 ? -dy : dy; // magnitude
            int passosHorizontais = dx < 0 ? -dx : dx;

            // Primeiro, realizar os passos verticais (aqui: 2 para cima)
            for (int v = 0; v < passosVerticais; v++) {
                if (dy < 0) printf("Cima\n");
                else        printf("Baixo\n");
            }

            // Depois, realizar os passos horizontais (aqui: 1 para a direita)
            for (int h = 0; h < passosHorizontais; h++) {
                if (dx < 0) printf("Esquerda\n");
                else        printf("Direita\n");
            }

            movimentosExecutados++;

            // Como nosso objetivo era um único L, podemos encerrar
            break; // sai do loop interno após executar
        }

        // Se já fizemos o necessário, também quebramos o loop externo
        if (movimentosExecutados >= limiteMovimentos) {
            break;
        }
    }
}

int main(void) {
    /* ===============================
       Parâmetros de movimento
       =============================== */
    int casasTorre   = 5;  // Torre: 5 para a direita
    int casasBispo   = 5;  // Bispo: 5 passos na diagonal (Cima + Direita)
    int casasRainha  = 8;  // Rainha: 8 para a esquerda

    /* ===============================
       Torre (Recursivo)
       =============================== */
    printf("Movimento da Torre (recursivo):\n");
    moverTorreDireitaRec(casasTorre);
    printf("\n");

    /* ===============================
       Bispo (Recursivo)
       =============================== */
    printf("Movimento do Bispo (recursivo, diagonal Cima+Direita):\n");
    moverBispoCimaDireitaRec(casasBispo);
    printf("\n");

    /* ===============================
       Bispo (Loops aninhados: externo vertical, interno horizontal)
       =============================== */
    printf("Movimento do Bispo (loops aninhados, externo=vertical, interno=horizontal):\n");
    moverBispoCimaDireitaLoops(casasBispo);
    printf("\n");

    /* ===============================
       Rainha (Recursivo)
       =============================== */
    printf("Movimento da Rainha (recursivo):\n");
    moverRainhaEsquerdaRec(casasRainha);
    printf("\n");

    /* ===============================
       Cavalo (Loops complexos com continue/break)
       Objetivo: 2 para Cima, 1 para Direita
       =============================== */
    printf("Movimento do Cavalo (loops aninhados + continue/break):\n");
    moverCavaloCimaDireitaComplexo();
    printf("\n");

    return 0;
}

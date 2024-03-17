#include <stdio.h>    // Inclui as declarações de funções padrão de entrada e saída
#include <string.h>   // Inclui as declarações de funções para manipulação de strings
#include <math.h>     // Inclui as declarações de funções matemáticas

int main() {
    // Declaração e inicialização de variáveis
    float A = 0, B = 0;         // Variáveis de ângulo
    float i, j;                  // Variáveis de iteração
    int k;                       // Variável de iteração
    float z[1760];               // Array de profundidade
    char b[1760];                // Array de caracteres ASCII para desenho

    // Limpa o console
    printf("\x1b[2J");

    // Loop infinito para renderização contínua
    for(;;) {
        // Limpa os arrays de caracteres e profundidade
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        // Loop para varrer os ângulos j e i
        for(j = 0; j < 6.28; j += 0.07) {
            for(i = 0; i < 6.28; i += 0.02) {
                // Cálculos trigonométricos
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                // Cálculo das coordenadas x e y na tela
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                // Desenho dos caracteres ASCII se a profundidade for maior que a existente
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        
        // Limpa o console e imprime os caracteres ASCII
        printf("\x1b[H");
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);  // Imprime um caractere por vez ou uma nova linha após 80 caracteres
            A += 0.00004;                 // Incrementa o ângulo A
            B += 0.00002;                 // Incrementa o ângulo B
        }

        // Aguarda um curto período de tempo para controle de velocidade de renderização
        usleep(30000);
    }
    return 0;
}

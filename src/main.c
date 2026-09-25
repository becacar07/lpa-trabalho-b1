#include <stdio.h>

int main() {
    int continuar;
    printf("===== SIMULADOR DE ENTREGAS =====\n");

    do {
        double distancia, peso;
        int modalidade, protecao, tentativas;
        printf("\nDistancia (km): ");
        scanf("%lf", &distancia);

        printf("Peso (kg): ");
        scanf("%lf", &peso);

        printf("Modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
        scanf("%d", &modalidade);

        printf("Protecao adicional (1-Sim, 0-Nao): ");
        scanf("%d", &protecao);

        printf("Tentativas adicionais: ");
        scanf("%d", &tentativas);
        printf("\nDistancia: %.2f km\n", distancia);
        printf("Peso: %.2f kg\n", peso);
        printf("Modalidade: %d\n", modalidade);
        printf("Protecao: %d\n", protecao);
        printf("Tentativas: %d\n", tentativas);
        printf("\nDeseja processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
    printf("\nPrograma encerrado.\n");
    return 0;
}


#include <stdio.h>

int main() {
    int continuar;
    printf("===== SIMULADOR DE ENTREGAS =====\n");

    do {
        double distancia, peso;
        int modalidade, protecao, tentativas;

        printf("\nDistancia (km): ");
        scanf("%lf", &distancia);
        while (distancia <= 0) {
            printf("Valor invalido. Digite uma distancia maior que zero: ");
            scanf("%lf", &distancia);
        }

        printf("Peso (kg): ");
        scanf("%lf", &peso);
        while (peso <= 0) {
            printf("Valor invalido. Digite um peso maior que zero: ");
            scanf("%lf", &peso);
        }

        printf("Modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
        scanf("%d", &modalidade);
        while (modalidade < 1 || modalidade > 3) {
            printf("Opcao invalida. Digite 1, 2 ou 3: ");
            scanf("%d", &modalidade);
        }

        printf("Protecao adicional (1-Sim, 0-Nao): ");
        scanf("%d", &protecao);
        while (protecao < 0 || protecao > 1) {
            printf("Opcao invalida. Digite 0 ou 1: ");
            scanf("%d", &protecao);
        }

        printf("Tentativas adicionais: ");
        scanf("%d", &tentativas);
        while (tentativas < 0) {
            printf("Valor invalido. Digite um numero maior ou igual a zero: ");
            scanf("%d", &tentativas);
        }

        printf("\nDistancia: %.2f km\n", distancia);
        printf("Peso: %.2f kg\n", peso);
        printf("Modalidade: %d\n", modalidade);
        printf("Protecao: %d\n", protecao);
        printf("Tentativas: %d\n", tentativas);

        printf("\nDeseja processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);
        while (continuar < 0 || continuar > 1) {
            printf("Opcao invalida. Digite 0 ou 1: ");
            scanf("%d", &continuar);
        }
    } while (continuar == 1);

    printf("\nPrograma encerrado.\n");
    return 0;
}

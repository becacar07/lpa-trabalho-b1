#include <stdio.h>

#define TARIFA_POR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA 4.00

int main() {
    int continuar;
    int totalEntregas = 0, qtdEconomica = 0, qtdExpressa = 0, qtdPrioritaria = 0;
    double valorTotal = 0, maiorValor = 0, menorValor = 0;

    printf("===== SIMULADOR DE ENTREGAS =====\n");

    do {
        double distancia, peso, valorBase, subtotal;
        double percentualPeso, percentualModalidade;
        double adicionalPeso, adicionalModalidade, valorFinal;
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

        if (distancia <= 5) {
            valorBase = 8.00;
        } else if (distancia <= 15) {
            valorBase = 12.00;
        } else if (distancia <= 30) {
            valorBase = 18.00;
        } else {
            valorBase = 25.00;
        }

        subtotal = valorBase + distancia * TARIFA_POR_KM;

        if (peso <= 2) {
            percentualPeso = 0;
        } else if (peso <= 5) {
            percentualPeso = 0.05;
        } else if (peso <= 10) {
            percentualPeso = 0.10;
        } else {
            percentualPeso = 0.20;
        }

        if (modalidade == 2) {
            percentualModalidade = 0.15;
        } else if (modalidade == 3) {
            percentualModalidade = 0.30;
        } else {
            percentualModalidade = 0;
        }

        adicionalPeso = subtotal * percentualPeso;
        adicionalModalidade = subtotal * percentualModalidade;

        valorFinal = subtotal + adicionalPeso + adicionalModalidade;

        if (protecao == 1) {
            valorFinal = valorFinal + VALOR_PROTECAO;
        }

        valorFinal = valorFinal + tentativas * VALOR_TENTATIVA;

        printf("\nValor final da entrega: R$ %.2f\n", valorFinal);

        totalEntregas = totalEntregas + 1;
        valorTotal = valorTotal + valorFinal;

        if (totalEntregas == 1 || valorFinal > maiorValor) {
            maiorValor = valorFinal;
        }
        if (totalEntregas == 1 || valorFinal < menorValor) {
            menorValor = valorFinal;
        }

        if (modalidade == 1) {
            qtdEconomica = qtdEconomica + 1;
        } else if (modalidade == 2) {
            qtdExpressa = qtdExpressa + 1;
        } else {
            qtdPrioritaria = qtdPrioritaria + 1;
        }

        printf("\nDeseja processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);
        while (continuar < 0 || continuar > 1) {
            printf("Opcao invalida. Digite 0 ou 1: ");
            scanf("%d", &continuar);
        }
    } while (continuar == 1);

    printf("\nRESUMO DA SESSAO\n");
    printf("Entregas processadas: %d\n", totalEntregas);
    printf("Valor total: R$ %.2f\n", valorTotal);
    printf("Valor medio: R$ %.2f\n", valorTotal / totalEntregas);
    printf("Entregas Economicas: %d\n", qtdEconomica);
    printf("Entregas Expressas: %d\n", qtdExpressa);
    printf("Entregas Prioritarias: %d\n", qtdPrioritaria);
    printf("Maior valor: R$ %.2f\n", maiorValor);
    printf("Menor valor: R$ %.2f\n", menorValor);

    return 0;
}


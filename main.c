// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

int main() {
    Passageiro* espera = NULL;
    PassageiroEmbarcado* embarcados = NULL;
    Era* eras = inicializar_eras();
    int opcao, posicao;
    char nome[50], destino[50];


    do {
        printf("\n===== Agencia do Tempo =====\n");
        printf("1. Adicionar passageiro a espera\n");
        printf("2. Listar passageiros em espera\n");
        printf("3. Embarcar primeiro passageiro da espera\n");
        printf("4. Embarcar ultimo passageiro da espera\n");
        printf("5. Embarcar passageiro especifico\n");
        printf("6. Listar passageiros embarcados\n");
        printf("7. Desembarcar passageiro especifico\n");
        printf("8. Desembarcar primeiro passageiro\n");
        printf("9. Desembarcar ultimo passageiro\n");
        printf("0. Sair\n> ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Nome do passageiro: ");
            scanf("%s", nome);
            printf("Selecione o destino:\n");
            printf("1. Idade Media\n");
            printf("2. Era dos Dinossauros\n");
            printf("3. Ano 3000\n");
            printf("4. Corrida Espacial\n");
            printf("5. Revolucao Industrial\n");
            int escolha;
            scanf("%d", &escolha);

            switch (escolha) {
            case 1: strcpy(destino, "Idade Media"); break;
            case 2: strcpy(destino, "Era dos Dinossauros"); break;
            case 3: strcpy(destino, "Ano 3000"); break;
            case 4: strcpy(destino, "Corrida Espacial"); break;
            case 5: strcpy(destino, "Revolucao Industrial"); break;
            default: printf("Opção inválida!\n"); continue;
            }
            adicionar_espera(&espera, nome, destino);
            break;
        case 2:
            listar_espera(espera);
            break;
        case 3:
            embarcar_passageiro(&espera, &embarcados, eras, 1);
            break;
        case 4:
        {
            int count = 0;
            Passageiro* aux = espera;
            while (aux) { count++; aux = aux->prox; }
            embarcar_passageiro(&espera, &embarcados, eras, count);
        }
        break;
        case 5:
            printf("Número do passageiro na lista de espera: ");
            scanf("%d", &posicao);
            embarcar_passageiro(&espera, &embarcados, eras, posicao);
            break;
        case 6:
            listar_embarcados(embarcados);
            break;
        case 7:
            printf("Número do passageiro embarcado: ");
            scanf("%d", &posicao);
            desembarcar_passageiro(&embarcados, eras, posicao);
            break;
        case 8:
            desembarcar_passageiro(&embarcados, eras, 1);
            break;
        case 9:
        {
            int count = 0;
            PassageiroEmbarcado* aux = embarcados;
            while (aux) { count++; aux = aux->prox; }
            desembarcar_passageiro(&embarcados, eras, count);
        }
        break;
        }
    } while (opcao != 0);

    return 0;
}
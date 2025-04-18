// Feito por Hnerique Zimermann e Gabriel Sereia
#include "estruturas.h"

int main() {
    Passageiro* espera = NULL;
    PassageiroEmbarcado* embarcados = NULL;
    Era* eras = inicializar_eras();

    int opcao, posicao, escolha;
    char nome[50], destino[50];

    do {

        printf("===== Agencia do Tempo =====\n");
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
            printf("1. Idade Media\n2. Era dos Dinossauros\n3. Ano 3000\n4. Corrida Espacial\n5. Revolucao Industrial\n> ");
            scanf("%d", &escolha);

            switch (escolha) {
            case 1: strcpy_simples(destino, "Idade Media"); break;
            case 2: strcpy_simples(destino, "Era dos Dinossauros"); break;
            case 3: strcpy_simples(destino, "Ano 3000"); break;
            case 4: strcpy_simples(destino, "Corrida Espacial"); break;
            case 5: strcpy_simples(destino, "Revolucao Industrial"); break;
            default: printf("Destino invalido!\n"); continue;
            }

            adicionar_espera(&espera, nome, destino);
            break;

        case 2:
            listar_espera(espera);
            break;

        case 3:
            embarcar_passageiro(&espera, &embarcados, eras, 1);
            break;

        case 4: {
            int count = 0;
            Passageiro* aux = espera;
            while (aux) { count++; aux = aux->prox; }
            embarcar_passageiro(&espera, &embarcados, eras, count);
            break;
        }

        case 5:
            printf("Numero do passageiro na lista de espera: ");
            scanf("%d", &posicao);
            embarcar_passageiro(&espera, &embarcados, eras, posicao);
            break;

        case 6:
            listar_embarcados(embarcados);
            break;

        case 7:
            printf("Numero do passageiro embarcado: ");
            scanf("%d", &posicao);
            desembarcar_passageiro(&embarcados, eras, posicao);
            break;

        case 8:
            desembarcar_passageiro(&embarcados, eras, 1);
            break;

        case 9: {
            int count = 0;
            PassageiroEmbarcado* aux = embarcados;
            while (aux) { count++; aux = aux->prox; }
            desembarcar_passageiro(&embarcados, eras, count);
            break;
        }
        }

        printf("\nPressione Enter para continuar...");
        getchar(); getchar();

    } while (opcao != 0);

    return 0;
}

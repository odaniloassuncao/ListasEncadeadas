#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int opcao;
    char nova_operacao = 'y';
    do {
        // MENU INICIAL
        printf("=======================>    MENU    <=======================\n");  
        printf("Selecione uma opção (digite apenas o valor inteiro):\n");
        printf(">(0) Sair\n");
        printf(">(1) Inserir no início\n");
        printf(">(2) Inserir em uma posição específica\n");
        printf(">(3) Inserir no final\n");
        printf(">(4) Remover\n>(5) Buscar\n>(6) Listar\n");
        printf("Opção: ");

        while (1){ // input
        if (scanf("%d", &opcao) != 1){ // Leitura da operação e verificação se escreveu um numero de fato
            printf("Entrada inválida. Digite um número.\n");
            while (getchar() != '\n'); // limpa o buffer
            continue;
        }

        if (opcao >= 0 && opcao <= 6){ // caso esteja tudo certo
            break;
        }
        // caso seja inteiro, mas não entre 0 e 6:
        printf("Opção inválida. Sua opção deve ser um inteiro entre 0 e 6. \nTente novamente: ");
    }

    switch (opcao) { // Processamento de cada caso

        case 1:
            // inserir no início
            break;

        case 2:
            // inserir em posição específica
            break;

        case 3:
            // inserir no final
            break;

        case 4:
            // remover
            break;

        case 5:
            // buscar
            break;

        case 6:
            // listar
            break;

        case 0:
            printf("\nDesligando o programa...");
            return 0;
        }

    // Solicitação de nova operação
    printf("\nDeseja realizar uma nova operação? [y/n]: ");
    scanf(" %c", &nova_operacao);

    // Caso o usuário digite algo diferente de 'y' ou 'n':
    while (tolower(nova_operacao) != 'y' && tolower(nova_operacao) != 'n'){
        printf("\nResposta inválida. Utilize [y] para SIM e [n] para NÃO: ");
        scanf(" %c", &nova_operacao);
    }
    } while (tolower(nova_operacao) == 'y');

    // Encerrando o programa (caso o usuário digite 'n'):
    printf("\nDesligando o programa...");
    return 0;
}
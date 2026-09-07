#include <stdio.h> // biblioteca padrão
#include <stdlib.h> // para usar malloc e fazer alocação de memória
#include <ctype.h>

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} no;

no *lista = NULL;
int tamanho = 0;


void input_tratado(int *n){
    while (1){ // input
        if (scanf("%d", n) != 1){ 
            printf("Entrada inválida. Digite um número inteiro: ");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
}

void inserir_inicio(no **lista, int num){ // concluído
    no *novo = malloc(sizeof(no));
    if (novo == NULL){
        printf("Erro ao alocar memória!");
        return;
    }
    else{
        novo->valor = num;
        novo->anterior = NULL;
        novo->proximo = *lista;
        if (*lista != NULL) (*lista)->anterior = novo;
        *lista = novo;
    }
    printf("\nO número %d foi inserido no inicio da lista.\n", num);
    tamanho++;
}
void inserir_pos_especifica(no **lista, int num, int id){ // concluído
    if (id <= 0 || id > tamanho+1){
        printf("Posição escolhida inválida.");
        return;
    }
    else if (id == tamanho+1){
        inserir_final(lista, num);
        return;
    }
    else if (id == 1){
        inserir_inicio(lista, num);
        return;
    }
    no *aux = *lista;
    no *novo = malloc(sizeof(no));

    if (novo == NULL){ 
        printf("Erro ao alocar memória!");
        return;
    }

    else{ 
        novo->valor = num;

        for (int i=1; i<id; i++){
            aux = aux->proximo;
        }
        novo->anterior = aux->anterior;
        aux->anterior = novo;
        novo->proximo = aux;
        novo->anterior->proximo = novo;
        
        printf("\nO número %d foi inserido na posição %d da lista.\n", num, id);
        tamanho++;
    }

}
void inserir_final(no **lista, int num){
    no *aux, *novo = malloc(sizeof(no));

    if (novo == NULL){ 
        printf("Erro ao alocar memória!");
        return;
    }

    else{ 
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL){ // verifica se tem elemento na lista
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            aux = *lista;
            while (aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    printf("\nO número %d foi inserido no final da lista.\n", num);
    tamanho++;

}
void remover(no **lista, int id){ 
    if (id <= 0 || id > tamanho){
        printf("Posição escolhida inválida.");
        return;
    }
    no *aux = *lista;

    if (id == 1){
        *lista = aux->proximo;

        if (*lista != NULL)
            (*lista)->anterior = NULL;
    }
    else{
        for (int i=1; i<id; i++){
            aux = aux->proximo;
        }
        aux->anterior->proximo = aux->proximo;
        if (!(id == tamanho)){
            aux->proximo->anterior = aux->anterior;
        }
    }
    printf("\nO número %d da posição %d foi removido da lista.\n", aux->valor, id);

    free(aux);
    tamanho--;
}

void buscar(no *lista, int num){
    int cont=1;
    no *aux = lista;
    while (aux != NULL && aux->valor != num){
        aux = aux->proximo;
        cont++;
    }
    if (aux == NULL){
        printf("\nO número %d não está contido na lista.\n", num);
    }
    else if (aux->valor == num){
        printf("\n O número %d está presente na posição %d da lista.\n", num, cont);
    }
}

void listar(no *lista){ // concluído
    if (tamanho == 0){
        printf("-----------------------------------------\n");
        printf("Não há elementos na lista, seu bocó.\n");
        printf("-----------------------------------------\n");
        return;
    }
    int cont=1;
    no *aux = lista;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-\n");
    printf("    ELEMENTOS DA LISTA\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-\n");
    if (tamanho == 1){
        
        printf("\nNÓ %d\nValor: %d\nAnterior: NULL\nProximo: NULL\n", cont, aux->valor);
        printf("----------------------------------------");
    }
    else{
        printf("\nNÓ %d\nValor: %d\nAnterior: NULL\nProximo: %d\n", cont, aux->valor, aux->proximo->valor);
        while (aux->proximo->proximo != NULL){
            aux = aux->proximo;
            cont++;
            printf("NÓ %d\nValor: %d\nAnterior: %d\nProximo: %d\n", cont, aux->valor, aux->anterior->valor, aux->proximo->valor);
        }
        aux = aux->proximo;
        cont++;
        printf("NÓ %d\nValor: %d\nAnterior: %d\nProximo: NULL\n", cont, aux->valor, aux->anterior->valor);
    }
    printf("\n------------------------------\n");
    printf("Há %d elementos na lista.\n", tamanho);
    printf("------------------------------\n");

}

int main(){
    int num, pos;
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
            printf("\nVocê escolheu INSERIR NO INÍCIO!\n");
            printf("Digite o número que você quer inserir: ");
            input_tratado(&num);
            inserir_inicio(&lista, num);
            break;

        case 2:
            printf("\nVocê escolheu INSERIR EM UMA POSIÇÃO ESPECÍFICA!\n");
            printf("Digite o número que você quer inserir: ");
            input_tratado(&num);
            printf("\nDigite a posição que você quer este número: ");
            input_tratado(&pos);
            inserir_pos_especifica(&lista, num, pos);
            break;

        case 3:
            printf("\nVocê escolheu INSERIR NO FINAL!\n");
            printf("Digite o número que você quer inserir: ");
            input_tratado(&num);
            inserir_final(&lista, num);
            break;

        case 4:
            printf("\nVocê escolheu REMOVER!\n");
            printf("Digite a posição do número que você quer remover: ");
            input_tratado(&pos);
            remover(&lista, pos);
            break;

        case 5:
            printf("\nVocê escolheu BUSCAR!\n");
            printf("Digite o número que você quer buscar: ");
            input_tratado(&num);
            buscar(lista, num);
            break;

        case 6:
            listar(lista);
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
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} no;

no *lista = NULL;
int tamanho = 0;

void input_tratado(int *n);
void inserir_inicio(no **lista, int num);
void inserir_pos_especifica(no **lista, int num, int id);
void inserir_final(no **lista, int num);
void remover(no **lista, int id);
void buscar(no *lista, int num);
void listar(no *lista);

void input_tratado(int *n){
    while (1){
        if (scanf("%d", n) != 1){ 
            printf("Entrada invalida. Digite um numero inteiro: ");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
}

void inserir_inicio(no **lista, int num){
    no *novo = malloc(sizeof(no));
    if (novo == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }
    else{
        novo->valor = num;
        novo->anterior = NULL;
        novo->proximo = *lista;
        if (*lista != NULL) (*lista)->anterior = novo;
        *lista = novo;
    }
    printf("\nO numero %d foi inserido no inicio da lista.\n", num);
    tamanho++;
}
void inserir_pos_especifica(no **lista, int num, int id){
    if (id <= 0 || id > tamanho+1){
        printf("Posicao escolhida invalida.");
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
        printf("Erro ao alocar memoria!");
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
        
        printf("\nO numero %d foi inserido na posicao %d da lista.\n", num, id);
        tamanho++;
    }

}
void inserir_final(no **lista, int num){
    no *aux, *novo = malloc(sizeof(no));

    if (novo == NULL){ 
        printf("Erro ao alocar memoria!");
        return;
    }

    else{ 
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL){
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
    printf("\nO numero %d foi inserido no final da lista.\n", num);
    tamanho++;

}
void remover(no **lista, int id){ 
    if (id <= 0 || id > tamanho){
        printf("Posicao escolhida invalida.");
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
    printf("\nO numero %d da posicao %d foi removido da lista.\n", aux->valor, id);

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
        printf("\nO numero %d nao esta contido na lista.\n", num);
    }
    else if (aux->valor == num){
        printf("\n O numero %d esta presente na posicao %d da lista.\n", num, cont);
    }
}

void listar(no *lista){
    if (tamanho == 0){
        printf("-----------------------------------------\n");
        printf("Nao ha elementos na lista, seu boco.\n");
        printf("-----------------------------------------\n");
        return;
    }
    int cont=1;
    no *aux = lista;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-\n");
    printf("    ELEMENTOS DA LISTA\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-\n");
    if (tamanho == 1){
        
        printf("\nNO %d\nValor: %d\nAnterior: NULL\nProximo: NULL\n", cont, aux->valor);
        printf("----------------------------------------");
    }
    else{
        printf("\nNO %d\nValor: %d\nAnterior: NULL\nProximo: %d\n", cont, aux->valor, aux->proximo->valor);
        while (aux->proximo->proximo != NULL){
            aux = aux->proximo;
            cont++;
            printf("NO %d\nValor: %d\nAnterior: %d\nProximo: %d\n", cont, aux->valor, aux->anterior->valor, aux->proximo->valor);
        }
        aux = aux->proximo;
        cont++;
        printf("NO %d\nValor: %d\nAnterior: %d\nProximo: NULL\n", cont, aux->valor, aux->anterior->valor);
    }

    aux = lista;
    printf("\n%d", aux->valor);
    while (aux->proximo != NULL){
        aux = aux->proximo;
        printf(" <-> %d", aux->valor);
    }

    printf("\n------------------------------\n");
    printf("Ha %d elementos na lista.\n", tamanho);
    printf("------------------------------\n");

}

int main(){
    int num, pos;
    int opcao;
    char nova_operacao = 'y';
    do {
        printf("=======================>    MENU    <=======================\n");  
        printf("Selecione uma opcao (digite apenas o valor inteiro):\n");
        printf(">(0) Sair\n");
        printf(">(1) Inserir no inicio\n");
        printf(">(2) Inserir em uma posicao especifica\n");
        printf(">(3) Inserir no final\n");
        printf(">(4) Remover\n>(5) Buscar\n>(6) Listar\n");
        printf("Opcao: ");

        while (1){
        if (scanf("%d", &opcao) != 1){ 
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (opcao >= 0 && opcao <= 6){ 
            break;
        }
        printf("Opcao invalida. Sua opcao deve ser um inteiro entre 0 e 6. \nTente novamente: ");
    }

    switch (opcao) { 

        case 1:
            printf("\nVoce escolheu INSERIR NO INICIO!\n");
            printf("Digite o numero que voce quer inserir: ");
            input_tratado(&num);
            inserir_inicio(&lista, num);
            break;

        case 2:
            printf("\nVocê escolheu INSERIR EM UMA POSICAO ESPECIFICA!\n");
            printf("Digite o numero que voce quer inserir: ");
            input_tratado(&num);
            printf("\nDigite a posicao que voce quer este numero: ");
            input_tratado(&pos);
            inserir_pos_especifica(&lista, num, pos);
            break;

        case 3:
            printf("\nVoce escolheu INSERIR NO FINAL!\n");
            printf("Digite o numero que voce quer inserir: ");
            input_tratado(&num);
            inserir_final(&lista, num);
            break;

        case 4:
            printf("\nVoce escolheu REMOVER!\n");
            printf("Digite a posicao do numero que voce quer remover: ");
            input_tratado(&pos);
            remover(&lista, pos);
            break;

        case 5:
            printf("\nVoce escolheu BUSCAR!\n");
            printf("Digite o numero que voce quer buscar: ");
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

    
    printf("\nDeseja realizar uma nova operacao? [y/n]: ");
    scanf(" %c", &nova_operacao);

    
    while (tolower(nova_operacao) != 'y' && tolower(nova_operacao) != 'n'){
        printf("\nResposta invalida. Utilize [y] para SIM e [n] para NAO: ");
        scanf(" %c", &nova_operacao);
    }
    } while (tolower(nova_operacao) == 'y');

    printf("\nDesligando o programa...");
    return 0;
}
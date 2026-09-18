#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    int valor;
    struct no *direita;
    struct no *esquerda;
}NoArv;

NoArv* inserir(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if (num<raiz->valor)
        {
            raiz->esquerda = inserir(raiz->esquerda, num);
        }
        else{
            raiz->direita = inserir(raiz->direita, num);
        }
        return raiz;
    }
}

NoArv* buscar(NoArv *raiz, int num){
    if(raiz!=NULL){
        if(num == raiz->valor){
            return raiz;
        }
        else if(num < raiz->valor){
            return buscar(raiz->esquerda, num);
        }
        else{
            return buscar(raiz->direita, num);
        }
    }
    return NULL;
}

int main(){
    int opcao, valor;
    NoArv *raiz = NULL;
    
    do
    {
        printf("\n\t 1 - Inserir valor \n\t 2 - Buscar valor \n\t 3 - Remover valor \n\t 4 - Percorrer arvore \n\t 5 - imprimir arvore \n\t 0 - Sair");
        scanf("%d", &opcao );

        switch (opcao)
        {
        case 1:
            printf("Digite um valor que deseja inserir: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            if (raiz = inserir(raiz, valor))
            {
                printf("Valor inserido com sucesso!");
            }
            else{
                printf("Tente novamente, ocorreu um problema no procedimento de insercao.");
            }
            break;
        case 2:
            printf("Digite um valor que deseja buscar: ");
            scanf("%d", &valor);
            buscar(raiz, valor);
        default:
            break;
        }

    } while (opcao!=0);
    

    return 0;
    
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *direita;
    struct no *esquerda;
} NoArv;

NoArv *inserir(NoArv *raiz, int num)
{
    if (raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (num < raiz->valor)
        {
            raiz->esquerda = inserir(raiz->esquerda, num);
        }
        else
        {
            raiz->direita = inserir(raiz->direita, num);
        }
        return raiz;
    }
}

NoArv *buscar(NoArv *raiz, int num)
{
    if (raiz != NULL)
    {
        if (num == raiz->valor)
        {
            return raiz;
        }
        else if (num < raiz->valor)
        {
            return buscar(raiz->esquerda, num);
        }
        else
        {
            return buscar(raiz->direita, num);
        }
    }
    return NULL;
}

NoArv *remover(NoArv *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!");
        return NULL;
    }
    else
    {
        if (raiz->valor == chave)
        {
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("No folha removido: %d", chave);
                return NULL;
            }
            else
            {
                if (raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    /* code */
                }
                else{
                    NoArv *aux;
                    if (raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                    }
                    else{
                        aux = raiz->direita;
                    }
                    free(raiz);
                    printf("No com 1 filho removido: %d", chave);
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->valor)
            {
                raiz->esquerda = remover(raiz->esquerda, chave);
            }
            else
            {
                raiz->direita = remover(raiz->direita, chave);
            }
        }
    }
}

int main()
{
    int opcao, valor;
    NoArv *busca, *raiz = NULL;

    do
    {
        printf("=======================>    MENU    <=======================\n");
        printf("Selecione uma opcao (digite apenas o valor inteiro):\n");
        printf(">(1) Inserir valor\n");
        printf(">(2) Buscar valor\n");
        printf(">(3) Remover valor\n");
        printf(">(4) Percorrer arvore\n");
        printf(">(5) Imprimir arvore\n");
        printf(">(0) Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numero que deseja inserir: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            printf("Numero inserido com sucesso!");
            break;

        case 2:
            printf("Digite um numero que deseja buscar: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);
            if (busca)
            {
                printf("\n Numero encontrado: %d\n", busca->valor);
            }
            else
            {
                printf("Numero nao encontrado.\n");
            }
            break;

        case 3:
            printf("Digite um valor que deseja remover: ");
            scanf("%d", &valor);
            raiz= remover(raiz, valor);
            break;

        default:
            if (opcao != 0)
            {
                printf("Opcao invalida, tente novamente.");
            }
        }

    } while (opcao != 0);

    return 0;
}
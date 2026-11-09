#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct no{
    float info;
    struct no *prox;
}no;

typedef struct{
    no* inicio;
    no *fim;
} indicador;

indicador* inicializa(){
    indicador *i;

    i = malloc(sizeof(indicador));
    i->inicio = NULL;
    i->fim = NULL;
    return i;

}

void inserir_inicio(indicador *i, float valor) {
    no *novo, *inicio_antigo;
    novo = malloc(sizeof(no));
    novo->info = valor;
    novo->prox = NULL;
    inicio_antigo = NULL;
    if (i->inicio == NULL) {
        i->inicio = novo;
        i->fim = novo;
    }
    else {
        inicio_antigo = i->inicio;
        novo->prox = inicio_antigo;
        i->inicio = novo;
    }
    i->fim->prox = novo;
}

void inserir_fim(indicador *i, float valor) {
    no *novo, *fim_antigo;
    novo = malloc(sizeof(no));
    novo->info = valor;
    fim_antigo = NULL;
    if (i->inicio == NULL) {
        i->inicio = novo;
        i->fim = novo;
    }
    else {
        fim_antigo = i->fim;
        i->fim = novo;
    }
    novo->prox = i->inicio;
}

void remover_inicio(indicador *i) {
    no *aux;
    aux = i->inicio;
    if (aux==NULL) {
      printf("Lista vazia! \n");
    } else if (aux->prox == aux) {
        free(aux);
        i->inicio = NULL;
        i->fim = NULL;
    } else {
        i->inicio = aux->prox;
        free(aux);
        i->fim->prox = i->inicio;
    }
}

void remover_fim(indicador *i) {
    no *aux;
    aux = i->fim;
    if (aux==NULL) {
      printf("Lista vazia! \n");
    } else if (aux->prox == aux) {
        free(aux);
        i->inicio = NULL;
        i->fim = NULL;
    } else {
        while (aux->prox != i->fim) {
            aux=aux->prox;
        }
        free(i->fim);
        i->fim = aux;
    }
}

void atualizar_valor(indicador *i, float valor, float valor_alterado) {
    no *aux;
    int achado = 0;
    aux = i->inicio;
    if (aux==NULL) {
        printf("Lista vazia! \n");
    } else {
        aux = aux->prox;
        while (aux != i->inicio) {
            if (aux->info = valor) {
                aux->info = valor_alterado;
                achado = 1;
                printf("Valor encontrado e editado. \n");

            }
        }
        if (achado = 0) {
            printf("Valor não encontrado!");
        }
    }
}

void destruir_lista(indicador *i) {
    no *aux1, *aux2;
    aux1 = i->inicio;
    aux2 = aux1;
    if (aux1 == NULL) {
        printf("Lista vazia! \n");
    } else {
        while (aux1 != i->fim) {
            aux2 = aux1->prox;
            free(aux1);
            aux1 = aux1->prox;
        }
        free(aux1);
        i->inicio = NULL;
        i->fim = NULL;
    }
}

void exibir_lista(indicador *i) {
    no *aux;
    aux = i->inicio;
    if (aux == NULL) {
        printf("Lista vazia! \n");
    } else {
        do {
            printf("-> %f ",aux->info);
            aux = aux->prox;
        } while (aux != i->inicio);
    }
}

void main() {
    setlocale(LC_ALL, "portuguese");

    indicador *lista = inicializa();
    int opcao;
    float valor;

    do {

        printf("      Pilha  \n");
        printf("=========================================\n");
        printf(" 1 - Inserir inicio \n");
        printf(" 2 - Inserir fim \n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o valor para inserir: ");
                scanf("%f", &valor);
                inserir_inicio(lista, valor);
                exibir_lista(lista);
                printf("Valor inserido com sucesso!\n");
                break;

            case 2:
                printf("\nDigite o valor para inserir: ");
                scanf("%f", &valor);
                inserir_fim(lista, valor);
                exibir_lista(lista);
                printf("Valor inserido com sucesso!\n");
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                destruir_lista(lista);
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcao != 0);
}




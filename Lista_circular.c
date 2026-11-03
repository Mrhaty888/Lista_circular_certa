#include <stdio.h>
#include <loacle.h>
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

    i = malloc(sizeof(fila));
    i->inicio = NULL;
    i->fim = NULL;
    return i;

}

void inserir_inicio(indicador *i, float valor) {
    no *novo, *inicio_antigo;
    novo = malloc(sizeof(no));
    novo->info = valor;
    inicio_antigo = NULL;
    if (i->inicio == NULL) {
        i->inicio = novo;
        i->fim = novo;
    }
    else {
        inicio_antigo = f->inicio;
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
        while (aux->prox != i->fim;) {
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
            printf("Valor não encontrado!")
        }
    }
}




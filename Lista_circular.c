#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct no{
    float info;
    struct no *prox;
}no;

typedef struct{
    no *inicio;
    no *fim;
} indicador;

indicador* inicializa(){
    /*Cria um incializador com os ponteiros apontando pro primeiro e ultimo elemento da lista
      Apontando para NULL apenas no inicio.*/
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
    inicio_antigo = i->inicio;
    //inicio_antigo armazena o antigo inicio da lista.
    if (i->inicio == NULL) {
        i->inicio = novo;
        i->fim = novo;
        novo->prox = novo;
    }
    else {
        novo->prox = inicio_antigo;
        //o ponteiro prox do novo inicio aponta para o o inicio_antigo.
        i->inicio = novo;
        //o indicador aponta o inicio para o novo.
    }
    i->fim->prox = i->inicio;
    //o indicador aponta o ponteiro prox de onde fim aponta para o novo, que é o novo inicio.
}

void inserir_fim(indicador *i, float valor) {
    no *novo, *fim_antigo;
    novo = malloc(sizeof(no));
    novo->info = valor;
    fim_antigo = i->fim;
    //fim_antigo armazena o antigo fim da lista.
    if (i->inicio == NULL) {
        i->inicio = novo;
        i->fim = novo;
        novo->prox = novo;
    }
    else {
        fim_antigo->prox = novo;
        //o ponteiro prox de fim_antigo aponta para o novo.
        i->fim = novo;
        //o indicador aponta o fim para o novo, se tornando o novo fim da lista.
    }
    novo->prox = i->inicio;
    //o fim aponta para o inicio, mantendo a circularidade.
}

void remover_inicio(indicador *i) {
    no *aux;
    aux = i->inicio;
    //aux armazena o inicio.
    if (aux==NULL) {
      printf("Lista vazia! \n");
    } else if (aux->prox == aux) {
        //Quando só tem 1 elemento.
        printf("Removendo inicio . . . \n");
        free(aux);
        i->inicio = NULL;
        i->fim = NULL;
        //indicador volta ao estado inicial.
    } else {
        printf("Removendo inicio . . . \n");
        i->inicio = aux->prox;
        //o ponteiro inicio do indicador aponta para o elemento que o "prox" do inicio que será apagado aponta.
        free(aux);
        i->fim->prox = i->inicio;
        //o indicador aponta o ponteiro prox de onde fim aponta para o novo inicio.
    }
}

void remover_fim(indicador *i) {
    no *aux;
    aux = i->fim;
    if (aux==NULL) {
      printf("Lista vazia! \n");
    } else if (aux->prox == aux) {
        //Quando só tem 1 elemento.
        printf("Removendo fim . . . \n");
        free(aux);
        i->inicio = NULL;
        i->fim = NULL;
        //indicador volta ao estado inicial.
    } else {
        printf("Removendo fim . . . \n");
        while (aux->prox != i->fim) {
            aux=aux->prox;
            //roda até o penultimo elemento da lista,pois esse vira o novo fim.
        }
        free(i->fim);
        i->fim = aux;
        //o fim do indicador aponta para o novo fim
        aux->prox = i->inicio;
        //o novo fim aponta pro início.
    }
}

void atualizar_valor(indicador *i, float valor, float valor_alterado) {
    no *aux;
    int achado = 0;
    aux = i->inicio;
    if (aux==NULL) {
        printf("Lista vazia! \n");
    }
    else {
        //como a condição precisa ser testada se tiver pelo menos 1 elemento, usamos do-while.
        do {
            if (aux->info == valor) {
                aux->info = valor_alterado;
                achado = 1;
                //o valor do nó encontrado é trocado pelo valor novo e achado vira 1, indicando que foi achado.
                printf("Valor encontrado e editado. \n");
                break;
            }
            aux = aux->prox;
            //vai passando de nó em nó até voltar ao início.
            }while (aux != i->inicio);
        }
        if (achado == 0) {
            printf("Valor inexistente! \n");
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
            aux1 = aux2;
        }
        free(aux1);
        i->inicio = NULL;
        i->fim = NULL;
        //indicador volta ao estado inicial.
        printf("Lista destruida.");
    }
}

void exibir_lista(indicador *i) {
    no *aux;
    aux = i->inicio;
    if (aux == NULL) {
        printf("Nada para exibir! \n");
    } else {
        do {
            printf("-> %.2f --",aux->info);
            aux = aux->prox;
        } while (aux != i->inicio);
    }
}

void main() {
    setlocale(LC_ALL, "portuguese");

    indicador *lista = inicializa();
    int opcao;
    float valor;
    float valor_alterado;

    do {

        printf("   Lista Circular  \n");
        printf("=========================================\n");
        printf(" 1 - Inserir inicio \n");
        printf(" 2 - Inserir fim \n");
        printf(" 3 - Remover inicio \n");
        printf(" 4 - Remover fim \n");
        printf(" 5 - Atualizar valor \n");
        printf(" 6 - Exibir lista \n");
        printf(" 7 - Destruir lista \n");
        printf(" 0 - Sair \n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o valor para inserir: ");
                scanf("%f", &valor);
                inserir_inicio(lista, valor);
                exibir_lista(lista);
                printf("\nValor inserido com sucesso!\n");
                break;

            case 2:
                printf("\nDigite o valor para inserir: ");
                scanf("%f", &valor);
                inserir_fim(lista, valor);
                exibir_lista(lista);
                printf("\nValor inserido com sucesso!\n");
                break;

            case 3:
                remover_inicio(lista);
                exibir_lista(lista);
                break;
            case 4:
                remover_fim(lista);
                exibir_lista(lista);
                break;

            case 5:
                printf("\nDigite o valor para ser editado: ");
                scanf("%f", &valor);
                printf("\nDigite o novo valor: ");
                scanf("%f", &valor_alterado);
                atualizar_valor(lista,valor,valor_alterado);
                exibir_lista(lista);
                break;

            case 6:
                printf("\nExibindo lista: ");
                exibir_lista(lista);
                break;

            case 7:
                printf("\nDestruindo lista: ");
                destruir_lista(lista);
                break;

            case 0:
                destruir_lista(lista);
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcao != 0);

    free(lista);
}




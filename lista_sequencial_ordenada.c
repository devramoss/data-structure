#include "lista_sequencial_ordenada.h"
#include <stdio.h>
#include <stdlib.h>
#define N 100;
#define ERRO -1
#define FALSO 0
#define VERDADEIRO 1

struct lista_sequencial_ordenada{
    unsigned int quantidade;
    item *dados[100];
};


Lista_Sequencial_Ordenada *criar_lista_ordenada(){
    Lista_Sequencial_Ordenada *l = (Lista_Sequencial_Ordenada*) malloc(sizeof(Lista_Sequencial_Ordenada));
    if(l == NULL)
        return NULL;
    l->quantidade = 0;
    return l;
}


int lista_ordenada_cheia(Lista_Sequencial_Ordenada *l){
    if(l == NULL)
        return ERRO;
    if(sizeof(l->dados) == l->quantidade)
        return VERDADEIRO ;
    else
        return FALSO;
}

int lista_ordenada_vazia(Lista_Sequencial_Ordenada *l){
    if(l == NULL)
        return ERRO;
    return (l->quantidade == 0);
}

int lista_ordenada_tamanho(Lista_Sequencial_Ordenada *l){
    if(l != NULL)
        return l->quantidade;
    else
        return ERRO;
}


int liberar_lista_ordenada(Lista_Sequencial_Ordenada **l){
    esvaziar_lista_ordenada(*l);
    free(*l);
    *l = NULL;
    return VERDADEIRO;
}

int exibir_lista_ordenada(Lista_Sequencial_Ordenada *l){
    if(l == NULL)
        return FALSO;

    printf("\nExibindo lista ordenada:");

    for(int i=0; i<(l->quantidade); i++){
        imprimirItem(l->dados[i]);
    }
    return VERDADEIRO;
}

void esvaziar_lista_ordenada(Lista_Sequencial_Ordenada *l){
    while(!lista_ordenada_vazia(l))
        remover_fim_ordenada(l);
}

int remover_inicio_ordenada(Lista_Sequencial_Ordenada *l){
    if(lista_ordenada_vazia(l))
        return FALSO;

    l->dados[0] = l->dados[1];

    for(int i = 1; i<l->quantidade; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->quantidade--;
}

int remover_fim_ordenada(Lista_Sequencial_Ordenada *l){
    if(lista_ordenada_vazia(l))
        return FALSO;

    liberarItem(&(l->dados[l->quantidade-1]));

    l->quantidade--;
    return VERDADEIRO;
}

int remover_meio_ordenada(Lista_Sequencial_Ordenada *l, unsigned int posicao){
    if(lista_ordenada_vazia(l) || posicao > (l->quantidade-1))
        return FALSO;

    for(int i = posicao; i <= (l->quantidade-1); i++){
        l->dados[i] = l->dados[i+1];
    }
    l->quantidade--;
    return VERDADEIRO;
}

int buscar_elemento_ordenada(Lista_Sequencial_Ordenada* l, unsigned int chave){
    for(int k = 0; k < (l->quantidade); k++) {
        if(getChave(l->dados[k]) == chave) {
            printf("\n  RESULTADO DA BUSCA SEQUENCIAL > > >");
            imprimirItem(l->dados[k]);
            return VERDADEIRO;
        }
    }
    return printf("RESULTADO DA BUSCA >>> %d\n", ERRO);
}

int inserir_ordenada(Lista_Sequencial_Ordenada *l, item *Item){
    if(lista_ordenada_cheia(l))
        return FALSO;
    int i ;

    for (i=0; i<lista_ordenada_tamanho(l); i++){
        if(getChave(l->dados[i]) > getChave(Item)){
            int j;
            for (j=lista_ordenada_tamanho(l); j>=i; j--){
                l->dados[j+1] = l->dados[j];
            }
            break;
        }
    }
    l->dados[i] = Item;
    l->quantidade ++;
    return VERDADEIRO;
}

int busca_binaria(Lista_Sequencial_Ordenada *l, unsigned int chave){
    int inicio = 0;
    int meio;
    int fim = lista_ordenada_tamanho(l)-1;

    while(fim >= inicio){
        meio = (fim + inicio)/2;
        if (getChave(l->dados[meio]) == chave)
            return meio;
        else if (getChave(l->dados[meio]) > chave)
            fim = meio -1;
        else
            inicio = meio + 1;
    }
    return ERRO;
}

int merge(Lista_Sequencial_Ordenada *l, Lista_Sequencial_Ordenada *l2, Lista_Sequencial_Ordenada *l3){
    if(lista_ordenada_vazia(l) && lista_ordenada_vazia(l2))
        return FALSO;
        
    for (int i = 0; i < lista_ordenada_tamanho(l); i++)
        inserir_ordenada(l3, l->dados[i]);

    for (int j = 0; j < lista_ordenada_tamanho(l2); j++)
        inserir_ordenada(l3, l2->dados[j]);

    return VERDADEIRO;
}
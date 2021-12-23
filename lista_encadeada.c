#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct celula {
    item *conteudo;
    Celula *prox;
};

struct lista_encadeada {
    Celula *primeiro, *ultimo;
    unsigned int quant;
};

Lista_Encadeada *criar_lista_encadeada() {
   Lista_Encadeada *l = (Lista_Encadeada*) malloc(sizeof(Lista_Encadeada));
   if(l == NULL)
        return NULL;

   l->primeiro = (Celula*) malloc(sizeof(Celula));
   if(l->primeiro == NULL)
        return NULL;

   l->ultimo = l->primeiro;
   l->primeiro->prox = NULL;
   l->quant = 0;

   return l;
}

Lista_Encadeada *concatenar_lista_encadeada(Lista_Encadeada *l, Lista_Encadeada *l2, Lista_Encadeada *l3){
    Celula *auxiliar = l->primeiro;
    Celula *auxiliar2 = l2->primeiro;

    while(auxiliar->prox != NULL){
        inserir_inicio_encadeada(l3, auxiliar->prox->conteudo);
        auxiliar = auxiliar->prox;
        l3->quant++;
    }
    while(auxiliar2->prox != NULL){
        inserir_inicio_encadeada(l3, auxiliar2->prox->conteudo);
        auxiliar2 = auxiliar2->prox;
        l3->quant++;
    }
    printf("\nLista Encadeada Concatenada >>>\n");
    exibir_lista_encadeada(l3);
}

int lista_encadeada_vazia(Lista_Encadeada *l) {
    return (l->primeiro == l->ultimo);
}

int inserir_inicio_encadeada(Lista_Encadeada *l, item *i) {
    Celula *auxiliar = (Celula*) malloc(sizeof(Celula));
    if(auxiliar == NULL)
        return ERRO;
    if(lista_encadeada_vazia(l))
        l->ultimo = auxiliar;
   
    auxiliar->conteudo = i;
    auxiliar->prox = l->primeiro->prox;
    l->primeiro->prox = auxiliar;
    l->quant++;
    
    return VERDADEIRO;
}

int inserir_meio_encadeada(Lista_Encadeada *l, item *i, unsigned int k) {
    int posic;
    Celula *auxiliar = l->primeiro;

    for(posic = 0; posic<k-1; posic++) {
        if(auxiliar->prox != NULL)
            auxiliar = auxiliar->prox; 
        else    
            return FALSO;
    }

    Celula *novoItem = (Celula*) malloc(sizeof(Celula));

    if(novoItem == NULL)
        return FALSO;
    novoItem->conteudo = i;
    novoItem->prox = auxiliar->prox;
    auxiliar->prox = novoItem;

    return VERDADEIRO;
}

int inserir_fim_encadeada(Lista_Encadeada *l, item *i){
    Celula *auxiliar = (Celula*) malloc(sizeof(Celula));
    Celula *atual = (Celula*) malloc(sizeof(Celula));

    if(auxiliar == NULL || atual == NULL)
        return FALSO;
    auxiliar->conteudo = i;
    auxiliar->prox = NULL;

    if(lista_encadeada_vazia(l))
        l->primeiro = auxiliar;
  
    l->ultimo->prox = auxiliar;
    l->ultimo = auxiliar;
    l->quant ++;

    return VERDADEIRO;
}

int tamanho_da_lista(Lista_Encadeada *l){
    return (l->quant);
}

int exibir_lista_encadeada(Lista_Encadeada *l) {
    Celula *atual = l->primeiro->prox;
    printf("  LISTA ENCADEADA");

    while(atual != NULL) {
        imprimirItem(atual->conteudo);
        atual = atual->prox;
    }
}

int remover_inicio_encadeada(Lista_Encadeada *l){
    if(lista_encadeada_vazia(l))
        return FALSO;
    l->primeiro = l->primeiro->prox;
    l->quant --;
    return VERDADEIRO;
}

int remover_meio_encadeada(Lista_Encadeada *l, unsigned int k){
    Celula *auxiliar = l->primeiro;
    int posic ;
    
    if(lista_encadeada_vazia(l))
        return FALSO;
    else{
        for(posic = 0; posic < k-1; posic++){
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = auxiliar->prox->prox;
        l->quant --;
        return VERDADEIRO;
    }
}

int remover_fim_encadeada(Lista_Encadeada *l) {
    Celula *auxiliar = l->primeiro;

    if(lista_encadeada_vazia(l))
        return FALSO;
    else {
        while(auxiliar->prox->prox != NULL) {
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = NULL;
    }
    l->quant--;
    return VERDADEIRO;
}

int buscar_elemento_encadeada(Lista_Encadeada *l, unsigned int key){
    Celula *auxiliar = l->primeiro;

    for(int i = 0; i < (l->quant); i++){
        auxiliar = auxiliar->prox;
        if(getChave(auxiliar->conteudo) == key){
            printf("\n  RESULTADO DA BUSCA");
            imprimirItem(auxiliar->conteudo);
            return VERDADEIRO;
        }
    }
    return printf("RESULTADO DA BUSCA >>> %d\n", ERRO);
}

void esvaziar_lista_encadeada(Lista_Encadeada *l){
    while(l->primeiro->prox != NULL){
        remover_fim_encadeada(l);
    }
}

void liberar_celula(Celula **c) {
    liberarItem(&(*c)->conteudo);
    free(*c);
    *c = NULL;
}

void liberar_lista_encadeada(Lista_Encadeada **l) {
    Celula *auxiliar;

    while((*l)->primeiro->prox != NULL) {
        auxiliar = (*l)->primeiro->prox->prox;
        liberar_celula(&(*l)->primeiro->prox);
        (*l)->primeiro->prox = auxiliar;
    }
    free((*l)->primeiro);
    (*l)->primeiro = NULL;
    free(*l);
    *l = NULL;
}
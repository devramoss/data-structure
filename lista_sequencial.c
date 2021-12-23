#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista_sequencial.h"
#define N 100;
#define ERRO -1
#define FALSO 0
#define VERDADEIRO 1

struct lista_sequencial{
    unsigned int quantidade;
    item *dados[100];
};
struct Item {
    unsigned int key;
    quad *quadrado;
};

Lista_Sequencial *CriarLista(){
    Lista_Sequencial *l = (Lista_Sequencial*) malloc( sizeof(Lista_Sequencial) );
    if(l == NULL)
        return NULL;
    l->quantidade = 0;
    return l;
}

Lista_Sequencial *ConcatenarLista(Lista_Sequencial *l, Lista_Sequencial *l2, Lista_Sequencial *l3){ 
    if(ListaVazia(l) && ListaVazia(l2))
        return FALSO;
    for(int i=0; i < (l->quantidade); i++){
        InserirFim(l3, l->dados[i]);
        l3->dados[i]->key = l->dados[i]->key++;
    }
    for(int j=0; j < (l2->quantidade); j++){
        InserirFim(l3, l2->dados[j]);
        l3->dados[j]->key = l2->dados[j]->key++;
    }
    printf("\nLISTA CONCATENADA\n");
    ExibirLista(l3);
    return l3;
}

int ListaCheia(Lista_Sequencial *l){
    if(l == NULL)
        return ERRO;
    if(sizeof(l->dados) == l->quantidade)
        return VERDADEIRO ;
    else
        return FALSO;
}

int ListaVazia(Lista_Sequencial *l){
    if(l == NULL)
        return ERRO;
    return (l->quantidade == 0);
}

int ListaTamanho(Lista_Sequencial *l){
    if(l != NULL)
        return l->quantidade;
    else
        return ERRO;
}

int InserirFim(Lista_Sequencial *l, item *Item){
    if(ListaCheia(l))
        return FALSO;
    else {
        l->dados[l->quantidade] = Item;
        l->quantidade ++;
        return VERDADEIRO;
    }
}

int LiberarLista(Lista_Sequencial **l){
    EsvaziarLista(*l);
    free(*l);
    *l = NULL;
    return VERDADEIRO;
}

int ExibirLista(Lista_Sequencial *l){
    if(l == NULL)
        return FALSO;
    printf("\nExibindo lista:");
    for(int i=0; i<(l->quantidade); i++){
        imprimirItem(l->dados[i]);
    }
    return VERDADEIRO;
}

void EsvaziarLista(Lista_Sequencial *l){
    while(!ListaVazia(l))
        RemoverFim(l);
}

int InserirInicio(Lista_Sequencial *l, item *Item){
    if(ListaCheia(l))
        return FALSO;
    for(int j = l->quantidade; j>0; j--){
        l->dados[j] = l->dados[j-1];
    }
    l->dados[0] = Item;
    l->quantidade ++;
    return VERDADEIRO;
}

int RemoverInicio(Lista_Sequencial *l){
    if(ListaVazia(l))
        return FALSO;
    l->dados[0] = l->dados[1];
    for(int i = 1; i<l->quantidade; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->quantidade--;
}

int RemoverFim(Lista_Sequencial *l){
    if(ListaVazia(l))
        return FALSO;
    liberarItem(&(l->dados[l->quantidade-1]));
    l->quantidade--;
    return VERDADEIRO;
}

int RemoverMeio(Lista_Sequencial *l, unsigned int posicao){
    if(ListaVazia(l) || posicao > (l->quantidade-1))
        return FALSO;
    for(int i = posicao; i <= (l->quantidade-1); i++){
        l->dados[i] = l->dados[i+1];
    }
    l->quantidade--;
    return VERDADEIRO;

}

int InserirMeio(Lista_Sequencial *l, item *Item, unsigned int posicao){
    if(ListaCheia(l) || posicao >= (l->quantidade))
        return FALSO;
    int i;
    for(i = l->quantidade; i>posicao; i--){
        l->dados[i] = l->dados[i-1];
    }
    l->dados[posicao] = Item;
    l->quantidade++;

    return VERDADEIRO;
}

int BuscarElemento(Lista_Sequencial* l, unsigned int chave){
    for(int k = 0; k < (l->quantidade); k++) {
        if(l->dados[k]->key == chave) {
            printf("\n  RESULTADO DA BUSCA");
            imprimirItem(l->dados[k]);
            return VERDADEIRO;
        }
    }
    return printf("RESULTADO DA BUSCA >>> %d\n", ERRO);
}
#include <stdio.h>
#include <stdlib.h>
#include "quadrado.h"
#include "item.h"

struct Item {
    unsigned int key;
    quad *quadrado;
};

item *criarItem(float x, float y, float lado, unsigned int key){
    item *Item = (item*) malloc(sizeof(item));
    if(Item == NULL)
        return NULL ;

    pto *ponto = criarPonto(x, y);
    if(ponto == NULL)
        return NULL ;

    Item->quadrado = criarQuadrado(ponto, lado);
    if(Item->quadrado == NULL)
        return NULL ;

    Item->key = key;
    
    return Item ;
 
}

int liberarItem(item **Item){
    liberarQuadrado( &(*Item)->quadrado );
    free(*Item);
    *Item = NULL;
    return VERDADEIRO;
}

unsigned int getChave(item *Item){
    return (Item->key);
}

void imprimirItem(item *Item){
    printf("\n  Item: %d\n  Quadrado: \n", Item->key);
    exibirQuadrado(Item->quadrado);
}
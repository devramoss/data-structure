#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "quadrado.h"

typedef struct Item item;

quad *quadrado;
item *criarItem(float x, float y, float lado, unsigned int key);

int liberarItem(item **Item);
unsigned int getChave(item *Item);
void imprimirItem(item *Item);

#endif
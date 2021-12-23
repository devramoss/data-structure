#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED
#include "item.h"

typedef struct celula Celula;
typedef struct lista_encadeada Lista_Encadeada;

Lista_Encadeada *criar_lista_encadeada();
Lista_Encadeada *concatenar_lista_encadeada(Lista_Encadeada *l, Lista_Encadeada *l2, Lista_Encadeada *l3);

int lista_encadeada_vazia(Lista_Encadeada *l);
int inserir_inicio_encadeada(Lista_Encadeada *l, item *i);
int inserir_fim_encadeada(Lista_Encadeada *l, item *i);
int inserir_meio_encadeada(Lista_Encadeada *l, item *i, unsigned int k);
int tamanho_da_lista(Lista_Encadeada *l);
int exibir_lista_encadeada(Lista_Encadeada *l);
int remover_fim_encadeada(Lista_Encadeada *l);
int remover_inicio_encadeada(Lista_Encadeada *l);
int remover_meio_encadeada(Lista_Encadeada *l, unsigned int k);
int buscar_elemento_encadeada(Lista_Encadeada *l, unsigned int key);
void liberar_lista_encadeada(Lista_Encadeada **l);
void liberar_celula(Celula **c);
void esvaziar_lista_encadeada(Lista_Encadeada *l);

#endif
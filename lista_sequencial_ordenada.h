#ifndef LISTA_SEQUENCIAL_ORDENADA_H_INCLUDED
#define LISTA_SEQUENCIAL_ORDENADA_H_INCLUDED
#include "item.h"

typedef struct lista_sequencial_ordenada Lista_Sequencial_Ordenada;

Lista_Sequencial_Ordenada *criar_lista_ordenada();

int lista_ordenada_cheia(Lista_Sequencial_Ordenada *l);
int lista_ordenada_vazia(Lista_Sequencial_Ordenada *l);
int lista_ordenada_tamanho(Lista_Sequencial_Ordenada *l);
int inserir_ordenada(Lista_Sequencial_Ordenada *l, item *Item);
int liberar_lista_ordenada(Lista_Sequencial_Ordenada **l);
int exibir_lista_ordenada(Lista_Sequencial_Ordenada *l);
void esvaziar_lista_ordenada(Lista_Sequencial_Ordenada *l);
int remover_inicio_ordenada(Lista_Sequencial_Ordenada *l);
int remover_fim_ordenada(Lista_Sequencial_Ordenada *l);
int remover_meio_ordenada(Lista_Sequencial_Ordenada *l, unsigned int posicao);
int buscar_elemento_ordenada(Lista_Sequencial_Ordenada *l, unsigned int chave);
int busca_binaria(Lista_Sequencial_Ordenada *l, unsigned int chave);
int merge(Lista_Sequencial_Ordenada *l, Lista_Sequencial_Ordenada *l2, Lista_Sequencial_Ordenada *l3);

#endif
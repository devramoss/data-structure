#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "item.h"

typedef struct lista_sequencial Lista_Sequencial;

Lista_Sequencial *CriarLista();
Lista_Sequencial *ConcatenarLista(Lista_Sequencial *l, Lista_Sequencial *l2, Lista_Sequencial *l3);

int ListaCheia(Lista_Sequencial *l);
int ListaVazia(Lista_Sequencial *l);
int ListaTamanho(Lista_Sequencial *l);
int InserirFim(Lista_Sequencial *l, item *Item);
int InserirInicio(Lista_Sequencial *l, item *Item);
int LiberarLista(Lista_Sequencial **l);
int ExibirLista(Lista_Sequencial *l);
void EsvaziarLista(Lista_Sequencial *l);
int RemoverInicio(Lista_Sequencial *l);
int RemoverFim(Lista_Sequencial *l);
int RemoverMeio(Lista_Sequencial *l, unsigned int posicao);
int InserirMeio(Lista_Sequencial *l, item *Item, unsigned int posicao);
int BuscarElemento(Lista_Sequencial *l, unsigned int chave);

#endif
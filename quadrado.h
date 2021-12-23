#ifndef QUADRADO_H_INCLUDED
#define QUADRADO_H_INCLUDED
#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct Ponto pto;
typedef struct Quadrado quad;

pto *criarPonto(float x, float y);
quad *criarQuadrado(pto *ptoCentral, float lado);

void exibirQuadrado(quad *quadrado);
void moverQuadrado(quad *quadrado, pto *newPtoCentral);
void liberarQuadrado(quad **quadrado);
int verificarPertinencia(quad *quadrado, pto *newPto);
float calcularArea(quad *quadrado);
float calcularPerimetro(quad *quadrado);
float calcularDistancia(quad *quadrado);

#endif

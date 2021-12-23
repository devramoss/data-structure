#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrado.h"

struct Ponto{
    float x, y;
};
struct Quadrado{
    pto *pontoCentral;
    float lado;
};

pto *criarPonto(float x, float y){
    pto *ptoCentral = malloc( sizeof(pto) );

    if(ptoCentral==NULL)
        return NULL;

    ptoCentral->x = x;
    ptoCentral->y = y;

    return ptoCentral;
}
quad *criarQuadrado(pto *ptoCentral, float lado){
    quad *quadrado = malloc( sizeof(quad) );
    if(quadrado == NULL)
        return NULL;
    quadrado->pontoCentral = ptoCentral;
    quadrado->lado = lado;

    return quadrado;
}

void exibirQuadrado(quad *quadrado){
    printf("  X = %.2f\n", quadrado->pontoCentral->x);
    printf("  Y = %.2f\n", quadrado->pontoCentral->y);
    printf("  Lado = %.2f\n", quadrado->lado);
}
void moverQuadrado(quad *quadrado, pto *newPtoCentral){
    quadrado->pontoCentral->x = newPtoCentral->x;
    quadrado->pontoCentral->y = newPtoCentral->y;
    printf("\nQuadrado movido com sucesso:\n");
    exibirQuadrado(quadrado);
}
void liberarQuadrado(quad **quadrado){
    free(*quadrado);
    *quadrado = NULL ;
}

int verificarPertinencia(quad *quadrado, pto *newPto){
    float metadeLado_X = quadrado->lado/quadrado->pontoCentral->x;
    float metadeLado_Y = quadrado->lado/quadrado->pontoCentral->y;

    if(( (newPto->x)>=(quadrado->pontoCentral->x)-metadeLado_X )&&( (newPto->x)<=metadeLado_X+quadrado->pontoCentral->x) ){
        if(( (newPto->y)>=(quadrado->pontoCentral->y)-metadeLado_Y)&&(newPto->y)<=metadeLado_Y+quadrado->pontoCentral->y){
            printf("\nO ponto esta dentro do quadrado\n");
            return VERDADEIRO;
        }
    }
    printf("\nO ponto esta fora do quadrado\n");
    return FALSO;
}

float calcularArea(quad *quadrado){
    return (quadrado->lado * quadrado->lado); 
}
float calcularPerimetro(quad *quadrado){
    return( quadrado->lado * 4 );
}
float calcularDistancia(quad *quadrado){
    float metadeLado_X = quadrado->lado/quadrado->pontoCentral->x;
    float metadeLado_Y = quadrado->lado/quadrado->pontoCentral->y;
    float dist=pow((quadrado->pontoCentral->x)-metadeLado_X , 2) + pow((quadrado->pontoCentral->y)-metadeLado_Y, 2);
    return sqrt(dist);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaL.h"

typedef struct formaLinha{
  int id; /*id*/
  double x; /*pos x*/
  double y; /*pos y*/
  double x2; /*pos x2*/
  double y2; /*pos y2*/
  char cor[20];
}LinhaStruct;

Linha criaLinha(int id, double x, double y, double x2, double y2, char *cor){
    LinhaStruct *l =(LinhaStruct*)malloc(sizeof(LinhaStruct));
    l->id = id;
    l->x = x;
    l->y = y;
    l->x2 = x2;
    l->y2 = y2;
    strcpy(l->cor, cor);
    return l;
}

int getLinhaId(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->id;
}

double getLinhaX(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->x;
}

double getLinhaY(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->y;
}

double getLinhaX2(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->x2;
}

double getLinhaY2(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->y2;
}

char *getLinhaCor(Linha linha){
    LinhaStruct *l = (LinhaStruct*)linha;
    return l->cor;
}

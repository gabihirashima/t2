#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaR.h"

typedef struct formaRetangulo{
  int id; /*id*/
  double w; /*largura do retangulo*/
  double h; /*altura do retangulo*/
  double x; /*pos x*/
  double y; /*pos y*/
  char corb[20]; /*cor da borda*/
  char corp [20]; /*cor de preenchimento*/
  char rw [20]; /*espessura da borda*/
}RetanguloStruct; 

Retangulo criaRetangulo(int id, double w, double h, double x, double y, char *corb, char *corp, char *rw){
    RetanguloStruct *r =(RetanguloStruct*)malloc(sizeof(RetanguloStruct));
    r->id = id;
    r->w = w;
    r->h = h;
    r->x = x;
    r->y = y;
    strcpy(r->corb, corb);
    strcpy(r->corp, corp);
    strcpy(r->rw, rw);
    return r;
}

int getRetanguloId(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->id;
}


double getRetanguloW(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->w;
}

double getRetanguloH(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->h;
}

double getRetanguloX(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->x;
}

double getRetanguloY(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->y;
}

char *getRetanguloCorb(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->corb;
}

char *getRetanguloCorp(Retangulo retangulo){
    RetanguloStruct *r = (RetanguloStruct*)retangulo;
    return r->corp;
}

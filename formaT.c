#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaT.h"

typedef struct formaTexto{
  int id; /*id*/  
  double x; /*pos x*/
  double y; /*pos y*/
  char corb[20]; /*cor da borda*/
  char corp [20]; /*cor de preenchimento*/
  char text[50]; /*texto*/
}TextoStruct;

Texto criaTexto(int id, double x, double y, char *corb, char *corp, char *text){
    TextoStruct *t =(TextoStruct*)malloc(sizeof(TextoStruct));
    t->id = id;
    t->x = x;
    t->y = y;
    strcpy(t->corb, corb);
    strcpy(t->corp, corp);
    strcpy(t->text, text);
    return t;
}

int getTextoId(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->id;
}

double getTextoX(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->x;
}

double getTextoY(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->y;
}

char *getTextoCorb(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->corb;
}

char *getTextoCorp(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->corp;
}

char *getTextoText(Texto texto){
    TextoStruct *t = (TextoStruct*)texto;
    return t->text;
}

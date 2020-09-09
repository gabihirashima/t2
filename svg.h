#ifndef SVG_H_
#define SVG_H

#include <stdio.h>

void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw);

void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text);

void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw);

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corp);

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw);

#endif
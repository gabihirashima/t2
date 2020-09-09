#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"
#include "svg.h"

void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double w, h;
    w =  8;
    h =  20;
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw){
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text){
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     x, y, corb, corp, text);
}

void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" stroke=\"%s\" rx=\"%lf\" ry=\"%lf\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corp, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" fill = \"%s\" />\n",
      x1, y1, x2, y2, corb, corp);
}

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw){
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\" stroke-width=\"%s\" />\n",
    x, y, r, corb, corp, cw);
}

void criaSvgGeo(Cidade listacidade, FILE *arq, char *sw, char *cw, char *rw){

    listaStruct listaH = getListaHidrantes(listacidade);
    Node noH = getFirst(listaH);

    listaStruct listaQ = getListaQuadras(listacidade);
    Node noQ = getFirst(listaQ);

    listaStruct listaR = getListaRadios(listacidade);
    Node noR = getFirst(listaR);

    listaStruct listaS = getListaSemaforos(listacidade);
    Node noS = getFirst(listaS);

    listaStruct listaC = getListaCirculos(listacidade);
    Node noC = getFirst(listaC);

    listaStruct listaA = getListaRetangulos(listacidade);
    Node noA = getFirst(listaA);

    listaStruct listaT = getListaTexto(listacidade);
    Node noT = getFirst(listaT);

    tipo elemento;

    fprintf(arq, "<svg>\n");

    while(noH != NULL){
        elemento = getElemento(noH);
            desenhaHidrante(arq, getHidranteX(elemento), getHidranteY(elemento), getHidranteCFill(elemento), getHidranteCStrk(elemento), sw);
        noH = getNext(noH);
    }

    while(noQ != NULL){
        elemento = getElemento(noQ);
            desenhaQuadra(arq, getQuadraX(elemento), getQuadraY(elemento), getQuadraW(elemento), getQuadraH(elemento), getQuadraCFill(elemento), getQuadraCStroke(elemento), sw);
        noQ = getNext(noQ);
    }   

    while(noR != NULL){
        elemento = getElemento(noR);
           desenhaRadio(arq, getRadioX(elemento), getRadioY(elemento), getRadioCFill(elemento), getRadioCStroke(elemento), sw);
        noR = getNext(noR);
    }

    while(noS != NULL){
        elemento = getElemento(noS);
            desenhaSemaforo(arq, getSemaforoX(elemento), getSemaforoY(elemento), getSemaforoCFill(elemento), getSemaforoCStroke(elemento), sw);
        noS = getNext(noS);
    }

    while(noC != NULL){
        elemento = getElemento(noC);
            desenhaCirculo(arq, getCirculoX(elemento), getCirculoY(elemento), getCirculoR(elemento), getCirculoCorp(elemento), getCirculoCorb(elemento), cw);
        noC = getNext(noC);
    }

    while(noA != NULL){
        elemento = getElemento(noA);
            desenhaRetangulo(arq, getRetanguloX(elemento), getRetanguloY(elemento), getRetanguloW(elemento), getRetanguloH(elemento), 0, 0, getRetanguloCorb(elemento), getRetanguloCorp(elemento), rw);
        noA = getNext(noA);
    }

    while(noT != NULL){
        elemento = getElemento(noT);
            desenhaTexto(arq, getTextoX(elemento), getTextoY(elemento), getTextoCorb(elemento), getTextoCorp(elemento), getTextoText(elemento));
        noT = getNext(noT);
    }

    fprintf(arq, "</svg>");  
}

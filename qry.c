#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"formaC.h"
#include"formaR.h"
#include"formaT.h"
#include"formaL.h"
#include"quadra.h"
#include"radio.h"
#include"semaforo.h"
#include"hidrante.h"
#include"svg.h"

Cidade delQuadras(Cidade listaCidade, FILE *txt, FILE *svg, int htag, char *id, double r){
    char type = id[0], *cfill = NULL, *cstrk = NULL;
    Node ListEq;
    Node ListQ = getListaQuadras(listaCidade);
    Node eq,Q;
    tipo eqdata,q;
    double x, y, qx, qy, w, h;
    

    switch(type){
        case 'r':
            ListEq = getListaRadios(listaCidade);
            eq = comparaIdR(ListEq,id);
            eqdata = getElemento(eq);
            x = getRadioX(eqdata);
            y = getRadioY(eqdata);
            strcpy(cfill, getRadioCFill(eqdata));
            strcpy(cstrk, getRadioCStroke(eqdata));
            break;
        case 's':
            ListEq = getListaSemaforos(listaCidade);
            eq = comparaIdS(ListEq,id);
            eqdata = getElemento(eq);
            x = getSemaforoX(eqdata);
            y = getSemaforoY(eqdata);
            strcpy(cfill, getSemaforoCFill(eqdata));
            strcpy(cstrk, getSemaforoCStroke(eqdata));
            break;
        case 'h':
            ListEq = getListaHidrantes(listaCidade);
            eq = comparaIdH(ListEq,id);
            eqdata = getElemento(eq);
            x = getHidranteX(eqdata);
            y = getHidranteY(eqdata);
            strcpy(cfill, getHidranteCFill(eqdata));
            strcpy(cstrk, getHidranteCStroke(eqdata));
            break;
    }

    Q = getFirst(ListQ);

    while(Q!=NULL){
        q = getElemento(Q);
        qx = getQuadraX(q);
        qy = getQuadraY(q);
        w = getQuadraW(q);
        h = getQuadraH(q);
        
        if((qx + w < x + r && qx > x - r) && (qy + h < y + r && qy > y - r)){
            fprintf(txt, "\n%s", getQuadraCep(q));
            removeElemento(ListQ,Q);
            if(htag)
                desenhaRetangulo(svg, qx, qy, 10, 10, w, h, "beige", "olive","1.0px");   
        }
        Q = getNext(Q);
    }
    desenhaCirculo(svg, x, y, 22, "none", "blue", "4.0px");
    desenhaCirculo(svg, x, y, 25, "none", "yellow", "10.0px");
    desenhaCirculo(svg, x, y, r, "none", "black", "2.0px");
    
    fprintf(txt, "%s %lf %lf %s %s %s", id, x, y, cfill, cstrk, "1.0px");

    return listaCidade;
}

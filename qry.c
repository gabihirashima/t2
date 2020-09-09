#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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

double dist(double x1, double y1, double x2, double y2){
    return  sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void delQuadras(Cidade listaCidade, FILE *txt, FILE *svg, int htag, char *id, double r){
    char type = id[0], cfill[20], cstrk[20];
    Node ListQ = getListaQuadras(listaCidade);
    Node eq,Q;
    tipo q;
    double x, y, qx, qy, w, h;
    

    switch(type){
        case 'r':
            eq = comparaIdR(listaCidade,id);
            x = getRadioX(eq);
            y = getRadioY(eq);
            strcpy(cfill, getRadioCFill(eq));
            strcpy(cstrk, getRadioCStroke(eq));
            break;
        case 's':
            eq = comparaIdS(listaCidade,id);
            x = getSemaforoX(eq);
            y = getSemaforoY(eq);
            strcpy(cfill, getSemaforoCFill(eq));
            strcpy(cstrk, getSemaforoCStroke(eq));
            break;
        case 'h':
            eq = comparaIdH(listaCidade,id);
            x = getHidranteX(eq);
            y = getHidranteY(eq);
            strcpy(cfill, getHidranteCFill(eq));
            strcpy(cstrk, getHidranteCStroke(eq));
            break;
    }

    Q = getFirst(ListQ);

    while(Q!=NULL){
        q = getElemento(Q);
        qx = getQuadraX(q);
        qy = getQuadraY(q);
        w = getQuadraW(q);
        h = getQuadraH(q);
        
        if(dist(qx,qy,x,y) <=r && dist(qx+w,qy,x,y) <=r && dist(qx,qy+h,x,y) <=r && dist(qx+w,qy+h,x,y) <= r){
            fprintf(txt, "\n%s", getQuadraCep(q));
            removeElemento(ListQ,q);
            if(htag)
                desenhaRetangulo(svg, qx, qy, 10, 10, w, h, "beige", "olive","1.0px");   
        }
        Q = getNext(Q);
    }
    desenhaCirculo(svg, x, y, 22, "none", "blue", "4.0px");
    desenhaCirculo(svg, x, y, 25, "none", "yellow", "10.0px");
    desenhaCirculo(svg, x, y, r, "none", "black", "2.0px");
    
    fprintf(txt, "\n%s %lf %lf %s %s %s", id, x, y, cfill, cstrk, "1.0px");

}

void delUrb(Cidade listaCidade, FILE *svg, FILE *txt, char *cid){
    char type = cid[0], cfill[20], cstrk[20], sw[10];
    double x, y, w, h;
    Node listQ = getListaQuadras(listaCidade), listS = getListaSemaforos(listaCidade);
    Node listR = getListaRadios(listaCidade), listH = getListaHidrantes(listaCidade);
    Node urb;

    switch(type){
        case 'r':
            urb = comparaIdR(listaCidade,cid);
            x = getRadioX(urb);
            y = getRadioY(urb);
            strcpy(cfill,getRadioCFill(urb));
            strcpy(cstrk,getRadioCStroke(urb));
            strcpy(sw,getRadioSw(urb));
            removeElemento(listR,urb);
            fprintf(txt, "\nId: %s  X: %lf  Y: %lf  Cfill: %s  CStrk: %s  Sw: %s",cid,x,y,cfill,cstrk, sw);
            desenhaLinha(svg, x, x, y, 0,"black");
            desenhaTexto(svg, x, 0, "black", "white", cid);
            break;
        case 's':
            urb = comparaIdS(listaCidade,cid);
            x = getSemaforoX(urb);
            y = getSemaforoY(urb);
            strcpy(cfill,getSemaforoCFill(urb));
            strcpy(cstrk,getSemaforoCStroke(urb));
            strcpy(sw,getSemaforoSw(urb));
            removeElemento(listS,urb);
            fprintf(txt, "\nId: %s  X: %lf  Y: %lf  Cfill: %s  Cstrk: %s  Sw:%s",cid,x,y,cfill,cstrk, sw);
            desenhaLinha(svg, x, x, y, 0,"black");
            desenhaTexto(svg, x, 0, "black", "white", cid);
            break;
        case 'h':
            urb = comparaIdH(listaCidade,cid);
            x = getHidranteX(urb);
            y = getHidranteY(urb);
            strcpy(cfill,getHidranteCFill(urb));
            strcpy(cstrk,getHidranteCStroke(urb));
            strcpy(sw,getHidranteSw(urb));
            removeElemento(listH,urb);
            fprintf(txt, "\nId: %s  X:%lf  Y: %lf  Cfill: %s  Cstrk: %s  Sw: %s",cid,x,y,cfill,cstrk, sw);
            desenhaLinha(svg, x, x, y, 0,"black");
            desenhaTexto(svg, x, 0, "black", "white", cid);
            break;
        default:
            urb = comparaIdQ(listaCidade,cid);
            x = getQuadraX(urb);
            y = getQuadraY(urb);
            w = getQuadraW(urb);
            h = getQuadraH(urb);
            strcpy(cfill,getQuadraCFill(urb));
            strcpy(cstrk,getQuadraCStroke(urb));
            strcpy(sw,getQuadraSw(urb));
            removeElemento(listQ,urb);
            fprintf(txt, "\nCep: %s  X: %lf  Y: %lf  W: %lf  H: %lf  Cfill: %s  CStrl:%s  Sw:%s",cid,x,y,w,h,cfill,cstrk, sw);
            desenhaLinha(svg, x + w/2, x, y + h/2, 0,"black");
            desenhaTexto(svg, x + w/2 + 3, 0, "black", "white", cid);
            break;
    }
}

void colorBorder(Cidade listaCidade, FILE *txt, double x, double y, double r, char *cstrk){
    Node listQ = getListaQuadras(listaCidade);
    Node Q;
    tipo q;
    double qx, qy, w, h;

    Q = getFirst(listQ);
    while(Q!=NULL){
        q = getElemento(Q);
        qx = getQuadraX(q);
        qy = getQuadraY(q);
        w = getQuadraW(q);
        h = getQuadraH(q);
        
        if(dist(qx,qy,x,y) <=r && dist(qx+w,qy,x,y) <=r && dist(qx,qy+h,x,y) <=r && dist(qx+w,qy+h,x,y) <= r){
            setQuadCStroke(q,cstrk);
            fprintf(txt, "\n%s", getQuadraCep(q));
        }
        Q = getNext(Q);
    }
}


void coord(Cidade listaCidade, FILE *txt, char *cid){
    char type = cid[0];
    Node urb;

    switch(type){
        case 'r':
            urb = comparaIdR(listaCidade,cid);
            fprintf(txt,"\nId: %s  X: %lf  Y: %lf  Rádio-base",getRadioId(urb),getRadioX(urb),getRadioY(urb));
            break;
        case 's':
            urb = comparaIdS(listaCidade,cid);
            fprintf(txt,"\nId: %s  X: %lf Y: %lf  Semáforo",getSemaforoId(urb),getSemaforoX(urb),getSemaforoY(urb));
            break;
        case 'h':
            urb = comparaIdH(listaCidade,cid);
            fprintf(txt,"\nId: %s  X: %lf Y: %lf Hidrante",getHidranteId(urb),getHidranteX(urb),getHidranteY(urb));
            break;
        default:
            urb = comparaIdQ(listaCidade,cid);
            fprintf(txt,"\nId: %s  X: %lf  Y: %lf Quadra",getQuadraCep(urb),getQuadraX(urb),getQuadraY(urb));
            break;
    }
}

void rectArea(Cidade listaCidade, FILE *svg, FILE *txt, double x, double y, double w, double h){
    Node listQ = getListaQuadras(listaCidade);
    Node Q;
    tipo q;
    double qx, qy, qw, qh, A, AT=0;

    Q = getFirst(listQ);
    while(Q!=NULL){
        q = getElemento(Q);
        qx = getQuadraX(q);
        qy = getQuadraY(q);
        qw = getQuadraW(q);
        qh = getQuadraH(q);

        if(qx >= x && qx + qw <= x + w && qy >= y && qy + qh <= y + h){
            A = qw*qh;
            fprintf(txt, "\nCep: %s  Area: %lf",getQuadraCep(q), A);
            fprintf(svg,"<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">Area: %lf m²</text>\n", qx + qw/2, qy + qh/2, "black", "white", A);
        }
        AT += A;
        Q = getNext(Q);
    }
    fprintf(txt,"\nArea total: %lf",AT);
    desenhaRetangulo(svg, x, y, w, h, 0, 0, "none", "black", "1.0px");
    desenhaLinha(svg, x, x, y, 0, "black");
    fprint(svg,"<text x=\"%lf\" y=\"0\" stroke=\"%s\" fill=\"%s\">Area Total: %lf m²</text>\n", x+5, "black", "white", AT);
}
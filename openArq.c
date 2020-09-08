#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"
#include "lista.h"
#include "openArq.h"
#include "svg.h"

void openGeo(Cidade listacidade)
{
    FILE *arq, *svg; 

    char comando[3];
    char cfillQ[20];
    char cstrkQ[20];
    char cstrkH[20];
    char cfillH[20];
    char cstrkR[20];
    char cfillR[20];
    char cstrkS[20];
    char cfillS[20];
    char corb[20];
    char corp[20];
    char text[50];
    char id[20];
    char cep[20];
    int id_forma;
    int i = 1000;
    int nq = 1000;
    int nh = 1000;
    int ns = 1000;
    int nr = 1000;
    int cont_i = 0;
    int cont_nq = 0;
    int cont_nh = 0;
    int cont_ns = 0;
    int cont_nr = 0;
    double r;
    double x;
    double y;
    double w;
    double h;
    char sw[8];
    char cw[8];
    char rw[8];

    tipo elemento;

    arq = fopen("b1-bsc-000.geo", "r");
    svg = fopen("teste.svg", "w+");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }

        fprintf(svg, "<svg>\n");

         while(fscanf(arq, "%s", comando) != EOF){
                if(strcmp(comando, "nx") == 0){
                    fscanf(arq, "%d %d %d %d %d\n", &i, &nq, &nh, &ns, &nr);
                }

                else if((strcmp(comando, "c") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %s %s", &id_forma, &r, &x, &y, corb, corp);
                    desenhaCirculo(svg, x, y, r, corp, corb, cw); 
                    elemento = criaCirculo(id_forma, r, x, y, corb, corp);
                    insereElemento(getListaCirculos(listacidade), elemento);
                    cont_i += 1;
                }

                else if((strcmp(comando, "r") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id_forma, &w, &h, &x, &y, corb, corp); 
                    desenhaRetangulo(svg, x, y, w, h, corp, corb, rw);
                    elemento = criaRetangulo(id_forma, w, h, x, y, corb, corp);
                    insereElemento(getListaRetangulos(listacidade), elemento);
                    cont_i += 1;
                }

                else if(strcmp(comando, "t") == 0){
                    fscanf(arq, "%d %lf %lf %s %s %s", &id_forma, &x, &y, corb, corp, text); 
                    desenhaTexto(svg, x, y, corb, corp, text);
                    elemento = criaTexto(id_forma, x, y, corb, corp, text);
                    insereElemento(getListaTexto(listacidade), elemento);
                }

                else if((strcmp(comando, "q") == 0) && cont_nq < nq){
                    fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y ,&w ,&h);
                    desenhaQuadra(svg, x, y, w, h, cfillQ, cstrkQ, sw);
                    elemento = criaQuadra(cep, x, y, w, h, cfillQ, cstrkQ);
                    insereElemento(getListaQuadras(listacidade), elemento);
                    cont_nq += 1;
                }

                else if((strcmp(comando, "h") == 0) && cont_nh < nh){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    desenhaHidrante(svg, x, y, cfillH, cstrkH, sw);
                    elemento = criaHidrante(id, x, y, cfillH, cstrkH);
                    insereElemento(getListaHidrantes(listacidade), elemento);
                    cont_nh += 1;
                }

                else if((strcmp(comando, "s") == 0) && cont_ns < ns){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    desenhaSemaforo(svg, x, y, cfillS, cstrkH, sw);
                    elemento = criaSemaforo(id, x, y, cfillS, cstrkS);
                    insereElemento(getListaSemaforos(listacidade), elemento);
                    cont_ns += 1;
                }

                else if((strcmp(comando, "rb") == 0) && cont_nr < nr){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    desenhaRadio(svg, x, y, cfillR, cstrkR, sw);
                    elemento = criaRadio(id, x, y, cfillR, cstrkR);
                    insereElemento(getListaRadios(listacidade), elemento);
                    cont_nr += 1;
                }

                else if(strcmp(comando, "ch") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillH, cstrkH);
                }

                else if(strcmp(comando, "cr") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillR, cstrkR);
                }

                else if(strcmp(comando, "cs") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillS, cstrkS);
                }

                else if(strcmp(comando, "cq") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillQ, cstrkQ);
                }

                else if(strcmp(comando, "sw") == 0){
                    fscanf(arq, "%s %s", cw, rw);
                }
            }

            fprintf(svg, "</svg>");
        
        
    fclose(svg);
   fclose(arq);
}
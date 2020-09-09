#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "lista.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"
#include "openArq.h"

int main (int argc, char *argv[]){

    char *geopath = NULL, *qrypath = NULL;
    char *path = NULL, *outpath = NULL;
    char *qryname = NULL, *geoname = NULL;
    char *filename = NULL, *qname = NULL;
    char *out = NULL, *qout = NULL;

        for(int i=1;i<argc;i++){
            if (strcmp("-f",argv[i])==0){
                i++;
                if (argv[i] == NULL){
                    perror("sem parametros em -f");
                    exit(1);
                }
                geopath = malloc(strlen(argv[i])+1);
                strcpy(geopath,argv[i]);
            }
            else if (strcmp("-e",argv[i])==0){
                i++;
                if (argv[i] == NULL){
                    perror("sem parametros em -e");
                    exit(1);
                }
                path = malloc(strlen(argv[i])+1);
                strcpy(path,argv[i]);
            }
            else if (strcmp("-q",argv[i])==0){
                i++;
                if (argv[i] == NULL){
                    perror("sem parametros em -q");
                    exit(1);
                }
                qrypath = malloc(strlen(argv[i])+1);
                strcpy(qrypath,argv[i]);
            }
            else if (strcmp("-o",argv[i])==0){
                i++;
                if (argv[i] == NULL){
                    perror("sem parametros em -o");
                    exit(1);
                }
                outpath = malloc(strlen(argv[i])+1);
                strcpy(outpath,argv[i]);
            }
        }
        if (path != NULL) {
            geoname = malloc(strlen(geopath)+strlen(path)+2);
            sprintf(geoname,"%s/%s",path,geopath);
            if (qrypath != NULL){
                qryname = malloc(strlen(qrypath)+strlen(path)+2);
                sprintf(qryname,"%s/%s",path,qrypath);
            }
        } else {
            geoname = malloc(strlen(geopath)+1);
            strcpy(geoname, geopath);
            if(qrypath != NULL){
                qryname = malloc(strlen(qrypath)+1);
                strcpy(qryname, qrypath);
            }
        }

        Cidade listaCidade = criaCidade();

        filename = trataNome(geopath);
        out = malloc((strlen(filename)+strlen(outpath)+6));

        sprintf(out,"%s/%s.svg",outpath,filename);

        openGeo(listaCidade, geoname, out);

            if(qrypath!=NULL){
                qname = trataNome(qrypath);
                qout = malloc((strlen(outpath)+strlen(filename)+strlen(qname)+3));
                sprintf(qout,"%s/%s-%s",outpath,filename,qname);

                openQry(listaCidade, qryname, qout);

                free(qryname);
                free(qout);
                free(qrypath);
            }
        free(out);
        free(geoname);
        free(outpath);
        free(path);
        free(geopath);

    liberaLista(getListaCirculos(listaCidade));
    liberaLista(getListaRadios(listaCidade));
    liberaLista(getListaHidrantes(listaCidade));
    liberaLista(getListaQuadras(listaCidade));
    liberaLista(getListaSemaforos(listaCidade));
    liberaLista(getListaTexto(listaCidade));
    liberaLista(getListaLinhas(listaCidade));
    liberaLista(getListaRetangulos(listaCidade));

    free(listaCidade);

}
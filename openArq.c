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
#include "qry.h"

void openGeo(Cidade listacidade, char *nomeGeo, char *saidaSvg)
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

    arq = fopen(nomeGeo, "r");
    svg = fopen(saidaSvg, "w+");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }

        if(svg == NULL){
            printf("Erro ao abrir o arquivo Svg!!");
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
                    desenhaRetangulo(svg, x, y, w, h, 0, 0, corp, corb, rw);
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
                    printf("%s %lf %lf %lf %lf\n", getQuadraCep(elemento), getQuadraX(elemento), getQuadraY(elemento) ,getQuadraW(elemento) ,getQuadraH(elemento));
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
                    desenhaSemaforo(svg, x, y, cfillS, cstrkS, sw);
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

void openQry(Cidade listacidade, char *entradaQry, char *saidaQry){

    FILE *entrada, *saidaSvg, *saidaTxt;

    char comando[6];
    char teste[20];
    char id[20];
    char cStrk[20];
    char cFill[20];
    double r;
    double x;
    double y;
    double w;
    double h;

    listaStruct listaH = getListaHidrantes(listacidade);
    Node noH = getFirst(listaH);

    listaStruct listaQ = getListaQuadras(listacidade);
    Node noQ = getFirst(listaQ);

    listaStruct listaR = getListaRadios(listacidade);
    Node noR = getFirst(listaR);

    listaStruct listaS = getListaSemaforos(listacidade);
    Node noS = getFirst(listaS);

    tipo elemento;

    char *saidaSvgQry = malloc(strlen(saidaQry)+5);
    char *saidaTxtQry = malloc(strlen(saidaQry)+5);

    sprintf(saidaTxtQry, "%s.txt", saidaQry);
    sprintf(saidaSvgQry, "%s.svg", saidaQry);

    entrada = fopen(entradaQry, "r");
    saidaTxt = fopen(saidaTxtQry, "w+");
    saidaSvg = fopen(saidaSvgQry, "w+");

        while(fscanf(entrada, "%s", comando)!=EOF){

            if(strcmp(comando, "dq") == 0){
                fscanf(entrada, "%s", teste);

                    if(strcmp(teste, "#") == 0){
                        fscanf(entrada, "%s %lf", id, &r);
                            
                    }
                    else{
                        strcpy(id, teste);
                        fscanf(entrada, "%lf", &r);
                            
                    }
            }

            else if(strcmp(comando, "del") == 0){
                fscanf(entrada, "%s", id);
                   
            }

            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);

            }

            else if(strcmp(comando, "crd?") == 0){
                fscanf(entrada, "%s", id);
                
            }

            else if(strcmp(comando, "car") == 0){
                fscanf(entrada, "%lf %lf %lf %lf", &x, &y, &w, &h);
            }
        
        }
        



    fclose(saidaSvg);
    fclose(saidaTxt);
    fclose(entrada);
}

void tratamentoArquivos(char arquivoGeo[], char arquivoQry[], char diretorio[], char pastaSaida[]){

    char *nomeArquivoGeo = NULL; /*nome do arquivo geo pós tratamento*/
    char *nomeArquivoQry = NULL; /*nome do arquivo qry pós tratamento*/
    char *caminhoGeo = NULL; /*caminho final do arquivo geo*/
    char *caminhoQry = NULL; /*caminho final do arquivo Qry*/
    char *saidaSvg = NULL; /*caminho de saída para o arquivo Svg*/
    char *saidaQry = NULL; /*caminho de saída para o arquivo Qry*/

    /*printf("\n %s %s %s %s", diretorio, arquivoGeo, arquivoQry, pastaSaida);*/

            nomeArquivoGeo = (char*)malloc( ( ( strlen(arquivoGeo) )+1 )*sizeof(char) );
            strcpy(nomeArquivoGeo, arquivoGeo);
            nomeArquivoGeo = strtok(nomeArquivoGeo, "."); /*vai retornar somente o nome anterior ao .geo*/ 
            /*printf("\n\nnome geo formatado: %s", nomeArquivoGeo);*/

            if (diretorio != NULL){/*Se foi passado um argumento de diretório*/
                caminhoGeo = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoGeo) )+3 )* sizeof(char) );
                sprintf(caminhoGeo, "%s/%s", diretorio, arquivoGeo);
                /*printf("\n\ncaminho geo com argumento de diretorio: %s", caminhoGeo);*/
                    if(arquivoQry !=  NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoQry) )+3 )* sizeof(char) );
                        sprintf(caminhoQry, "%s/%s", diretorio, arquivoQry);
                        /*printf("\n\ncaminho Qry com argumento de diretorio: %s", caminhoQry);*/
                    }
            }
            else{/*Não foram passados argumentos para o diretório*/
                caminhoGeo =  (char*)malloc( ( (strlen(arquivoGeo) )+1 )* sizeof(char) );
                strcpy(caminhoGeo, arquivoGeo);
                /*printf("\n\ncaminho Geo sem argumento de diretorio: %s", caminhoGeo);*/
                    if(arquivoQry != NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( (strlen(arquivoQry) )+1 )* sizeof(char) );
                        strcpy(caminhoQry, arquivoQry);
                        /*printf("\n\ncaminho Qry sem argumento de diretorio: %s", caminhoQry);*/
                    }

            }

                saidaSvg =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo) )+8 )* sizeof(char) );
                sprintf(saidaSvg, "%s/%s.svg", pastaSaida, nomeArquivoGeo);
                /*printf("\n\nsaida Svg: %s", saidaSvg);*/

            if (arquivoQry != NULL){
                 char *tratamento = NULL;   
                    nomeArquivoQry = (char*)malloc( ( ( strlen(arquivoQry) )+1 )*sizeof(char) );
                    tratamento = (char*)malloc( ( ( strlen(arquivoQry) )+1 )*sizeof(char) );
                    strcpy(tratamento, arquivoQry);
                    printf("\n%s", tratamento);
                    strcpy(tratamento, strrchr(arquivoQry, '/') ); /*vai retornar o nome após '/' */ 
                    printf("\n%s", tratamento);
                    strcpy(nomeArquivoQry, strtok(tratamento, "/") ); /*vai retornar o que vem antes da '/' */
                    /*printf("\n\nnome Qry formatado: %s", nomeArquivoQry);*/


                    saidaQry =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo)+strlen(nomeArquivoQry) )+4 )* sizeof(char) );
                    sprintf(saidaQry, "%s/%s-%s", pastaSaida, nomeArquivoGeo, nomeArquivoQry);
                    /*printf("\n\nsaida Qry: %s", saidaQry);*/
                
                free(tratamento);
                free(saidaQry);
                free(nomeArquivoQry);
                free(arquivoQry);
                free(caminhoQry);
            }

}
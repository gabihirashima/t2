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

    char *arquivoGeo = NULL; /*nome do arquivo .geo*/
    char *arquivoQry = NULL; /*nome do arquivo .qry*/
    char *diretorio = NULL; /*diretorio do arquivo .geo e .qry*/
    char *pastaSaida = NULL; /*nome do arquivo de saida*/
    char *nomeArquivoGeo = NULL; /*nome do arquivo geo pós tratamento*/
    char *nomeArquivoQry = NULL; /*nome do arquivo qry pós tratamento*/
    char *caminhoGeo = NULL; /*caminho final do arquivo geo*/
    char *caminhoQry = NULL; /*caminho final do arquivo Qry*/
    char *saidaSvg = NULL; /*caminho de saída para o arquivo Svg*/
    char *saidaQry = NULL; /*caminho de saída para o arquivo Qry*/

    for (int i = 0; i<argc; i++){ /* Função para captar os caracteres do terminal */
          if ( strcmp(argv[i], "-e") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos em -e");
                    exit(1);
                }
                diretorio = (char*)malloc( ( ( strlen (argv[i]) )+1 )*sizeof(char) );
                strcpy(diretorio, argv[i]);
            }

            else if ( strcmp(argv[i], "-f") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -f");
                    exit(1);
                }
                arquivoGeo = (char*)malloc( ( ( strlen (argv[i]) )+1)*sizeof(char) );
                strcpy(arquivoGeo, argv[i]);
            }

            else if ( strcmp(argv[i], "-q") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -q");
                    exit(1);
                }
                arquivoQry = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoQry, argv[i]);
            }

            else if ( strcmp(argv[i], "-o") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -o");
                    exit(1);
                }
                pastaSaida = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(pastaSaida, argv[i]);
            }
    }

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

                Cidade listaCidade = criaCidade();
                tipo elemento;
                
                openGeo(listaCidade);
                openQry(listaCidade);

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

            if (diretorio != NULL){
                free(diretorio);
            }

        free(saidaSvg);
        free(caminhoGeo);
        free(nomeArquivoGeo);
        free(arquivoGeo);
        free(pastaSaida);

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
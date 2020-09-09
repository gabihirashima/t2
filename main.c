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

        tratamentoGeo(arquivoGeo, nomeArquivoGeo, caminhoGeo, diretorio);
        tratamentoQry(arquivoQry, nomeArquivoQry, caminhoQry, diretorio);
        tratamentoSaidas(pastaSaida, saidaSvg, saidaQry, nomeArquivoQry, arquivoQry, nomeArquivoGeo);

    Cidade listaCidade = criaCidade();
    tipo elemento;

    
    openGeo(listaCidade);
    openQry(listaCidade);

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
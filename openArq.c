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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        if(svg == NULL){
            printf("Erro ao abrir o arquivo Svg!!");
            system("pause");
            exit(1);
        }
=======
=======
>>>>>>> parent of b5d60f6... att
=======
>>>>>>> parent of b5d60f6... att
        fprintf(svg, "<svg>\n");
>>>>>>> parent of b5d60f6... att

         while(fscanf(arq, "%s", comando) != EOF){
                if(strcmp(comando, "nx") == 0){
                    fscanf(arq, "%d %d %d %d %d\n", &i, &nq, &nh, &ns, &nr);
                }

                else if((strcmp(comando, "c") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %s %s", &id_forma, &r, &x, &y, corb, corp);
                    elemento = criaCirculo(id_forma, r, x, y, corb, corp);
                    insereElemento(getListaCirculos(listacidade), elemento);
                    cont_i += 1;
                }

                else if((strcmp(comando, "r") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id_forma, &w, &h, &x, &y, corb, corp); 
                    elemento = criaRetangulo(id_forma, w, h, x, y, corb, corp);
                    insereElemento(getListaRetangulos(listacidade), elemento);
                    cont_i += 1;
                }

                else if(strcmp(comando, "t") == 0){
                    fscanf(arq, "%d %lf %lf %s %s %s", &id_forma, &x, &y, corb, corp, text); 
                    elemento = criaTexto(id_forma, x, y, corb, corp, text);
                    insereElemento(getListaTexto(listacidade), elemento);
                }

                else if((strcmp(comando, "q") == 0) && cont_nq < nq){
                    fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y ,&w ,&h);
                    //printf("%s %lf %lf %lf %lf\n", cep, x, y ,w ,h);
                    elemento = criaQuadra(cep, x, y, w, h, cfillQ, cstrkQ);
                    printf("%s %lf %lf %lf %lf\n", getQuadraCep(elemento), getQuadraX(elemento), getQuadraY(elemento) ,getQuadraW(elemento) ,getQuadraH(elemento));
                    insereElemento(getListaQuadras(listacidade), elemento);
                    cont_nq += 1;
                }

                else if((strcmp(comando, "h") == 0) && cont_nh < nh){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaHidrante(id, x, y, cfillH, cstrkH);
                    insereElemento(getListaHidrantes(listacidade), elemento);
                    cont_nh += 1;
                }

                else if((strcmp(comando, "s") == 0) && cont_ns < ns){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaSemaforo(id, x, y, cfillS, cstrkS);
                    insereElemento(getListaSemaforos(listacidade), elemento);
                    cont_ns += 1;
                }

                else if((strcmp(comando, "rb") == 0) && cont_nr < nr){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
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

            imprimeLista(getListaQuadras(listacidade), 'q');
            criaSvgGeo(listacidade, arq, sw, cw, rw);
          
    fclose(svg);
   fclose(arq);
}

void openQry(Cidade listacidade){

    FILE *entrada, *saida;

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

    entrada = fopen("del.qry", "r");
    saida = fopen("saidaQry.txt", "w+");

        while(fscanf(entrada, "%s", comando)!=EOF){

                if(strcmp(comando, "dq") == 0){
                    fscanf(entrada, "%s", teste);
                        if(strcmp(teste, "#") == 0){
                            fscanf(entrada, "%s %lf", id, &r);
                                if(comparaId(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                                }
                                else if(comparaId(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                                }
                                else if(comparaId(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                                }
                                else if(comparaId(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                                }
                
                        }
                        else{
                            fscanf(entrada, "%lf", &r);
                                if(comparaId(listaH, noH, teste) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                                }
                                else if(comparaId(listaQ, noQ, teste) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/
<<<<<<< HEAD
<<<<<<< HEAD

                                }
                                else if(comparaId(listaR, noR, teste) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                                }
                                else if(comparaId(listaS, noS, teste) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                                }
                        }
                }

            else if(strcmp(comando, "del") == 0){
                fscanf(entrada, "%s", id);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

            else if(strcmp(comando, "crd?") == 0){
=======

=======

>>>>>>> parent of b5d60f6... att
                                }
                                else if(comparaId(listaR, noR, teste) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                                }
                                else if(comparaId(listaS, noS, teste) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                                }
                        }
                }

            else if(strcmp(comando, "del") == 0){
<<<<<<< HEAD
>>>>>>> parent of b5d60f6... att
                fscanf(entrada, "%s", id);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

<<<<<<< HEAD
=======
            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

            else if(strcmp(comando, "crd?") == 0){
=======
>>>>>>> parent of b5d60f6... att
                fscanf(entrada, "%s", id);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

<<<<<<< HEAD
>>>>>>> parent of b5d60f6... att
=======
            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

            else if(strcmp(comando, "crd?") == 0){
                fscanf(entrada, "%s", id);
                    if(comparaIdH(listaH, noH, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um hidrante*/

                    }
                    else if(comparaIdQ(listaQ, noQ, id) != 0){/*Se compara Id retornar diferenete de NULL, o elemento é uma quadra*/

                    }
                    else if(comparaIdR(listaR, noR, id) != 0){/*Se compara Id retornar diferente de NULL, o elemento é um rádio*/

                    }
                    else if(comparaIdS(listaS, noS, id) != 0){/*Se comparaId retornar diferente de NULL, o elemento é uma quadra*/

                    }
            }

>>>>>>> parent of b5d60f6... att
            else if(strcmp(comando, "car") == 0){
                fscanf(entrada, "%lf %lf %lf %lf", &x, &y, &w, &h);
            }
        
        }




    fclose(saida);
    fclose(entrada);
}
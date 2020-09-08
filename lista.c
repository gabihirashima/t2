#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct no{
    void *elemento;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *primeiro;
    No *ultimo;
}Lista;

typedef struct listacidade{
    listaStruct listaQuadras;
    listaStruct listaRadios;
    listaStruct listaSemaforos;
    listaStruct listaHidrantes;
    listaStruct listaCirculos;
    listaStruct listaLinhas;
    listaStruct listaRetangulos;
    listaStruct listaTexto;
}listaCidade;

listaStruct criaLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

Cidade criaCidade(){
    listaCidade *lista;
    lista = (listaCidade*)malloc(sizeof(listaCidade*));

    lista->listaQuadras = criaLista();
    lista->listaRadios = criaLista();
    lista->listaSemaforos = criaLista();
    lista->listaHidrantes = criaLista();
    lista->listaCirculos = criaLista();
    lista->listaLinhas = criaLista();
    lista->listaRetangulos = criaLista();
    lista->listaTexto = criaLista();

    return lista;
}

Cidade getListaQuadras(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaQuadras;
}

Cidade getListaRadios(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaRadios;
}

Cidade getListaSemaforos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaSemaforos;
}

Cidade getListaHidrantes(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaHidrantes;
}

Cidade getListaCirculos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaCirculos;
}

Cidade getListaLinhas(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaLinhas;
}

Cidade getListaRetangulos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaRetangulos;
}

Cidade getListaTexto(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaTexto;
}

listaStruct insereElemento(listaStruct lista, tipo elemento){
    Lista *list = (Lista*)lista;
    
    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;
        if(list->primeiro == NULL){ /*se a lista esta vazia*/
            node->ant = NULL; /*o anterior aponta para null*/
            list->primeiro = node; /*o primeiro elemento da lista é node*/
        }
        else{ /*senao*/
            list->ultimo->prox = node; /*o prox do ultimo elemento adicionado aponta para o novo node*/
            node->ant = list->ultimo; /*o ponteiro de anterior aponta pro ultimo elemento adicionado*/
        }

        node->prox = NULL;
        list->ultimo = node;
    return list; 
}

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2){
    Lista *list = (Lista*)lista;

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

    No* inicio = list->primeiro;
    No *aux_1;
    No *aux_2;

        while (inicio != NULL){
                    if(inicio == elemento_2){
                            if(inicio == list->primeiro){
                                aux_1 = inicio;
                                aux_1->ant = node;
                                node->prox = aux_1;
                                node->ant = NULL;
                                list->primeiro = node;
                                return list; 
                            }
                        else if(inicio!= list->primeiro){
                                aux_1 = inicio;
                                aux_2 = inicio->ant;
                                node->ant = aux_2;
                                node->prox = aux_1;
                                aux_1->ant = node;
                                aux_2->prox = node;
                                return list; 
                        }
                    }
                    inicio = inicio->prox;
        }
}

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2){
     Lista *list = (listaStruct)lista;
    
         No* node = (No*)malloc(sizeof(No));
         node->elemento = elemento;
         
         No *inicio = list->primeiro;
         No *aux_1; 
         No *aux_2;
            while(inicio != NULL){
                if(inicio == elemento_2){
                        if(inicio == list->ultimo){
                            aux_1 = inicio;
                            aux_1->prox = node;
                            node->prox = NULL;
                            node->ant = aux_1;
                            list->ultimo = node;
                            return list; 
                        }
                        else if(inicio!= list->ultimo){
                            aux_1 = inicio;
                            aux_2 = inicio->prox;
                            aux_1->prox = node;
                            aux_2->ant = node;
                            node->ant = aux_1;
                            node->prox = aux_2;
                            return list; 
                        }
                }
                inicio = inicio->prox;
            }
}

listaStruct removeElemento(listaStruct lista, tipo elemento){
    Lista *list = (listaStruct)lista;
         
         No *inicio = list->primeiro;
         No *aux_1; 
         No *aux_2;
         No *aux_3;

            while(inicio != NULL){
            if(inicio == elemento){
               if(inicio == list->primeiro){
                    aux_1 = inicio;
                    aux_2 = inicio->prox;
                    aux_2->ant = NULL;
                    list->primeiro = aux_2;
                    free(aux_1->elemento);
                    free(aux_1);
                    }
                else if(inicio == list->ultimo){
                    aux_1 = inicio;
                    aux_2 = inicio->ant;
                    aux_2->prox = NULL;
                    list->ultimo = aux_2;
                    free(aux_1->elemento);
                    free(aux_1);
                    }
                else{
                    aux_1 = inicio;
                    aux_2 = inicio->prox;
                    aux_3 = inicio->ant;
                    aux_2->ant = aux_3;
                    aux_3->prox = aux_2;
                    free(aux_1->elemento);
                    free(aux_1);
                    }
                return list;     
            }    
            inicio = inicio->prox;
        }
    return NULL;
}

void liberaLista(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    No *aux;
        while(node != NULL){
            aux = node->prox;
                free(node->elemento);
                free(node);
            node = aux;
        }
    free(lista); 
}

Node getFirst(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
        if(list->primeiro == NULL){
            return NULL;
        }
        
    return node;
}

Node getLast(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->ultimo;
        if(list->ultimo == NULL){
            return NULL;
        }
        
    return node;
}

Node getPrevious(Node elemento){
    No* node = (No*)elemento;

    return node->ant;
}

Node getNext(Node elemento){
    No* node = (No*)elemento;

    return node->prox;
}

tipo getElemento(Node elemento){
    No *node = (No*)elemento;

    return node->elemento; 
}

void imprimeLista(listaStruct l, char c){
    Lista *list = (Lista*)l;
    No *node = list->primeiro;
        while(node != NULL){
            if(c == 'r'){
                printf("%s, %lf, %lf, %s, %s\n", getRadioId(node->elemento), getRadioX(node->elemento), getRadioY(node->elemento), getRadioCFill(node->elemento), getRadioCStroke(node->elemento));
            }
            else if(c == 'h'){
                printf("%s, %lf, %lf, %s, %s\n", getHidranteId(node->elemento), getHidranteX(node->elemento), getHidranteY(node->elemento), getHidranteCFill(node->elemento), getHidranteCStroke(node->elemento));
            }
            else if(c == 'q'){
                printf("%s, %lf, %lf, %lf, %lf,%s, %s\n", getQuadraCep(node->elemento), getQuadraX(node->elemento), getQuadraY(node->elemento),  getQuadraW(node->elemento),  getQuadraH(node->elemento), getQuadraCFill(node->elemento), getQuadraCStroke(node->elemento));
            }
            else if(c == 's'){
                printf("%s, %lf, %lf, %s, %s\n", getSemaforoId(node->elemento), getSemaforoX(node->elemento), getSemaforoY(node->elemento), getSemaforoCFill(node->elemento), getSemaforoCStroke(node->elemento));
            }
            else if(c == 'c'){
                printf("%d, %lf, %lf, %lf, %s, %s\n", getCirculoId(node->elemento), getCirculoR(node->elemento), getCirculoX(node->elemento), getCirculoY(node->elemento), getCirculoCorb(node->elemento), getCirculoCorp(node->elemento));
            }
            else if(c == 'a'){
                printf("%d, %lf, %lf, %lf, %lf, %s, %s\n", getRetanguloId(node->elemento), getRetanguloW(node->elemento), getRetanguloH(node->elemento), getRetanguloX(node->elemento), getRetanguloY(node->elemento), getRetanguloCorb(node->elemento), getRetanguloCorp(node->elemento));
            }
            else if(c == 't'){
                printf("%d, %lf, %lf, %s, %s, %s\n", getTextoId(node->elemento), getTextoX(node->elemento), getTextoY(node->elemento), getTextoCorb(node->elemento), getTextoCorp(node->elemento), getTextoText(node->elemento));
            }
            node = node->prox;
        }
}
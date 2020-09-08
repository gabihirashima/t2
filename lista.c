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
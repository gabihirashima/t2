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

int main (){
    Cidade listaCidade = criaCidade();
    tipo elemento;

    elemento = criaRadio("rb1.2", 2.3, 32.3, "rosa", "amarelo");
    insereElemento(getListaRadios(listaCidade), elemento);
    elemento = criaRadio("rb1.3", 5.3, 15.4, "azul", "amarelo");
    insereElemento(getListaRadios(listaCidade), elemento);
    
    listaStruct list = getListaQuadras(listaCidade);
    Node node = getFirst(list);
    tipo elemento_2;

    while(node!= NULL){
        elemento_2 = getElemento(list);
            if( ( (strcmp( getRadioId (elemento_2) ) ), "rb1.3") == 0 ){
                elemento = criaRadio("rb4", 5.3, 15.4, "azul", "amarelo");
                insertBefore(list, elemento, elemento_2);
            }
        node = getNext(node);
    }

}
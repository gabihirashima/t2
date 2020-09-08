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

}
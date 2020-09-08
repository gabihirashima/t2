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
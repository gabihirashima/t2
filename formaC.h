#ifndef FORMAC_C_
#define FORMAC_C_

/*Define Circulo como um ponteiro do tipo void*/
typedef void* Circulo;

/*Cria um elemento do tipo Circulo e retorna o seu endereço*/
Circulo criaCirculo(int, double, double, double, char *, char *, char *);

/*Recebe o endereço de uma lista de circulos e retorna o Id do elemento*/
int getCirculoId(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o R do elemento*/
double getCirculoR(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o X do elemento*/
double getCirculoX(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o Y do elemento*/
double getCirculoY(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna a Corb do elemento*/
char *getCirculoCorb(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna a Corp do elemento*/
char *getCirculoCorp(Circulo);

char *getCirculoSw(Circulo circulo);

#endif
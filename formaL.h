#ifndef FORMAL_C_
#define FORMAL_C_

/*define Linha como um ponteiro do tipo void*/
typedef void* Linha;

/*cria um elemento do tipo Linha_S e retorna o endereço do elemento criado*/
Linha criaLinha(int, double, double, double, double, char *);

/*recebe o endereço de um elemento da lista de linhas e retorna o id*/
int getLinhaId(Linha linha);

/*recebe o endereço de um  elemento da lista de linhas e retorna o X*/
double getLinhaX(Linha);

/*recebe o endereço de um elemento da lista de linhas e retorna o Y*/
double getLinhaY(Linha);

/*recebe o endereço de um elemento da lista de linhas e retorna o X2*/
double getLinhaX2(Linha);

/*recebe o endereço de um elemento da lista de linhas e retorna o Y2*/
double getLinhaY2(Linha);

/*recebe o endereço de um elemento da lista de linhas e retorna a cor*/
char *getLinhaCor(Linha);

#endif
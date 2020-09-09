#ifndef RADIO_H_
#define RADIO_H_

/*define "Radio" como um ponteiro void*/
typedef void* Radio;

/*cria um elemento da struct Radio_S*/
Radio criaRadio(char*, double, double, char*, char*, char*);

/*retorna a Id de um elemento da lista de radio*/
char *getRadioId(Radio);

/*retorna o X de um elemento da lista de radio*/
double getRadioX(Radio);

/*retorna o Y de um elemento da lista de radio*/
double getRadioY(Radio);

/*retorna o Cfill de um elemento da lista de radio*/
char *getRadioCFill(Radio);

/*retorna o CStroke de um elemento da lista de radio*/
char *getRadioCStroke(Radio);

#endif
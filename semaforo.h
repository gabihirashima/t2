#ifndef SEMAFORO_H_
#define SEMAFORO_H_

/*Define Semaforo como um ponteiro do tipo void*/
typedef void* Semaforo;

/*Cria um elemento da struct Semaforo_S*/
Semaforo criaSemaforo(char*, double, double, char *, char *);

/*Retorna Id de um elemento da lista de semaforos*/
char *getSemaforoId(Semaforo);

/*Retorna X de um elemento da lista de semaforos*/
double getSemaforoX(Semaforo);

/*Retorna Y de um elemento da lista de semaforos*/
double getSemaforoY(Semaforo);

/*Retorna Cfill de um elemento da lista de semaforos*/
char *getSemaforoCFill(Semaforo);

/*Retorna CStroke de um elemento da lista de semaforos*/
char *getSemaforoCStroke(Semaforo);

#endif
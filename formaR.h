#ifndef FORMAR_C_
#define FORMAR_C_

typedef void* Retangulo;

Retangulo criaRetangulo(int, double, double, double, double, double, double, char *, char *, char *);

int getRetanguloId(Retangulo);

double getRetanguloW(Retangulo);

double getRetanguloH(Retangulo);

double getRetanguloX(Retangulo);

double getRetanguloY(Retangulo);

double getRetanguloRX(Retangulo retangulo);

double getRetanguloRY(Retangulo retangulo);

char *getRetanguloCorb(Retangulo);

char *getRetanguloCorp(Retangulo);

char *getRetanguloSw(Retangulo retangulo);

#endif
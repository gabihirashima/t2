#ifndef FORMAR_C_
#define FORMAR_C_

typedef void* Retangulo;

Retangulo criaRetangulo(int, double, double, double, double, char *, char *, char *);

int getRetanguloId(Retangulo);

double getRetanguloW(Retangulo);

double getRetanguloH(Retangulo);

double getRetanguloX(Retangulo);

double getRetanguloY(Retangulo);

char *getRetanguloCorb(Retangulo);

char *getRetanguloCorp(Retangulo);

#endif
#ifndef OPENARQ_H_
#define OPENARQ_H_

#include "lista.h"

void openGeo(Cidade listacidade, char *nomeGeo, char *saidaSvg);

void openQry(Cidade listacidade, char *entradaQry, char *saidaQry);

void tratamentoArquivos(char arquivoGeo[], char arquivoQry[], char diretorio[], char pastaSaida[]);

#endif
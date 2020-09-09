#ifndef TRATAMENTO_H_
#define TRATAMENTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tratamentoGeo(char *arquivoGeo, char *nomeArquivoGeo, char *caminhoGeo, char *diretorio);

void tratamentoQry(char *arquivoQry, char *nomeArquivoQry, char *caminhoQry, char *diretorio);

void tratamentoSaidas(char *pastaSaida, char *saidaSvg, char *saidaQry, char *nomeArquivoQry, char *arquivoQry, char *nomeArquivoGeo);

#endif
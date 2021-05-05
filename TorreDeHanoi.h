#ifndef TORRE_HANOI_H
#define TORRE_HANOI_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Disco{
    struct Disco *next;
    char tam;
} Disco;

typedef struct{
    Disco *topo;
    char qddDiscos;
} Pino;

Pino* criarPinos(int n);
Disco* criarDisco(int tam);
Disco* pop(Pino *pinos, int pos);
int push(Pino *pinos, Disco *disco, int pos);
int moverDisco(Pino *pinos, int pinoOri, int pinoDest);
void imprimir(Pino *pinos);

#endif
#ifndef TORRE_HANOI_H
#define TORRE_HANOI_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Disco Disco;
typedef struct Pino Pino;

//Retorna um vetor de pinos, de tamanho n, alocado dinamicamente
Pino* criarPinos(int n);

//Recebe o tamanho de um disco e retorna um disco alocado dinamicamente
Disco* criarDisco(int tam);

//Desempilha um disco do pino cujo indice foi passado como parametro
Disco* pop(Pino *pinos, int indice);

//Empilha um disco no pino cujo indice foi passado como parametro
void push(Pino *pinos, Disco *disco, int indice);

//Retorna 1 se conseguir mover um disco de um pino para outro, caso contrário retorna 0
int moverDisco(Pino *pinos, int pinoOri, int pinoDest);

//Imprime todos os pinos com seus discos
void imprimir(Pino *pinos, int numPinos, int numDiscos);

//Imprime um disco de manaho tam
void imprimirDisco(int tam, int numDiscos);

//Retorna o tamanho do disco que está na mam altura do nível passado como parametro
int buscarDisco(int nivel, Pino *pino);

//Desaloca todos os pinos e discos
void desalocar(Pino *pinos, int numPinos);

//Executa o jogo
void jogar();

#endif
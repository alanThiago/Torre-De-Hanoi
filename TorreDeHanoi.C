#include "TorreDeHanoi.h"

Pino* criarPinos(int n){
    Pino *pinos = (Pino*) malloc(n*sizeof(Pino));
    
    if(!pinos) exit(1);

    for(int i = 0; i < n; i++){
        pinos[i].topo = NULL;
        pinos[i].qddDiscos = 0;
    }

    return pinos;
}

Disco* criarDisco(int tam){
    Disco *disco = malloc(sizeof(disco));

    if(!disco) exit(1);

    disco->tam = tam;
    return disco;
}

int push(Pino *pinos, Disco *disco, int pos){
    if(pinos[pos].topo)
        disco->next = pinos[pos].topo;
    pinos[pos].topo = disco;
    return 1;
}

Disco* pop(Pino *pinos, int pos){
    if(pinos[pos].topo == NULL) return NULL;
    Disco *disco = pinos[pos].topo;
    pinos[pos].topo = disco->next;
    return disco;
}

int moverDisco(Pino *pinos, int origem, int destino){
    if(pinos[origem].topo == NULL) return 0;
    if(pinos[destino].topo && pinos[origem].topo->tam < pinos[destino].topo->tam) return 0;

    
}
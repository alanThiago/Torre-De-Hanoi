#include "TorreDeHanoi.h"

struct Disco{
    struct Disco *next;
    char tam;
};

struct Pino{
    Disco *topo;
    char qddDiscos;
};

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
    Disco *disco = malloc(sizeof(Disco));

    if(!disco) exit(1);

    disco->tam = tam;
    return disco;
}

void push(Pino *pinos, Disco *disco, int pos){
    disco->next = pinos[pos].topo;
    pinos[pos].topo = disco;
    pinos[pos].qddDiscos++;
}

Disco* pop(Pino *pinos, int pos){
    if(pinos[pos].topo == NULL) return NULL;
    Disco *disco = pinos[pos].topo;
    pinos[pos].topo = disco->next;
    pinos[pos].qddDiscos--;
    return disco;
}

int moverDisco(Pino *pinos, int origem, int destino){
    if(pinos[origem].topo == NULL) return 0;
    if(pinos[destino].topo && pinos[origem].topo->tam > pinos[destino].topo->tam) return 0;
    Disco *tmp = pop(pinos, origem);
    push(pinos, tmp, destino);

    return 1;
}

void imprimirDisco(int tam, int numDiscos){
    int i;
    numDiscos -= tam;

    for(i = 0; i <= numDiscos; i++) printf(" ");
    for(i = 0; i < tam; i++) printf("_");
    printf("|");
    for(i = 0; i < tam; i++) printf("_");
    for(i = 0; i <= numDiscos; i++) printf(" ");
}

int buscarDisco(int nivel, Pino *pino){
    if(nivel <= pino->qddDiscos){
        Disco *disco = pino->topo;
        char qddDiscos = pino->qddDiscos;
        while(nivel++ < qddDiscos)
            disco = disco->next;
        return disco->tam;
    }
    return 0;
}

void imprimir(Pino *pinos, int numPinos, int numDiscos){
    int i, j, k;

    printf("\n");
    for(i = numDiscos; i > 0; i--){
        for(j = 0; j < numPinos; j++)
            imprimirDisco(buscarDisco(i, &pinos[j]), numDiscos);
        printf("\n");
    }
    numDiscos++;
    for(i = 1; i <= numPinos; i++){
        for(j = 0; j < numDiscos; j++) printf("_");
        printf("|");
        for(j = 0; j < numDiscos; j++) printf("_");
    }
    printf("\n\n");
    for(i = 1; i <= numPinos; i++){
        for(j = 0; j < numDiscos; j++) printf(" ");
        printf("%d", i);
        for(j = 0; j < numDiscos; j++) printf(" ");
    }
    printf("\n\n");
}

void desalocar(Pino *pinos, int numPinos){
    Disco *tmp1, *tmp2;
    int i;

    for(i = 0; i < numPinos; i++){
        tmp1 = pinos[i].topo;
        while(tmp1){
            tmp2 = tmp1;
            tmp1 = tmp1->next;
            free(tmp2);
        }
    }
    free(Pino);
}

void jogar(){
    int numPinos;
    int numDiscos;
    int origem;
    int destino = 0;
    int numJogadas = 0;
    Pino *pinos;

    printf("Insira a quantidade de pinos: [3..5] ");
    scanf("%d", &numPinos);

    printf("Insira a quantidade de discos: [3..5] ");
    scanf("%d", &numDiscos);

    pinos = criarPinos(numPinos);
    for(int i = numDiscos; i > 0; i--)
        push(pinos, criarDisco(i), 0);

    while(!(destino > 0 && pinos[destino].qddDiscos == numDiscos)){
        imprimir(pinos, numPinos, numDiscos);
        printf("Insira os pinos de origem e de destino: ");
        scanf("%d %d", &origem, &destino);
        origem--; destino--;
        if(origem < 0 || destino < 0 || origem >= numPinos || destino >= numPinos || !moverDisco(pinos, origem, destino))
            printf("Movimento invalido.\n");
        else numJogadas++;
    }

    imprimir(pinos, numPinos, numDiscos);
    printf("PARABENS VOCE CONSEGUIU\nTOTAL DE JOGADAS: %d\n", numJogadas);
}
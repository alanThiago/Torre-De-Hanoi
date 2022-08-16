#include "TorreDeHanoi.h"

struct Disco{
    Disco *next; //ponteiro para o proximo disco
    char tamDisco; //tamanho do disco
};

struct Pino{
    Disco *topo; //ponteiro para o topo da pilha
    char numDiscos; //quantidade de discos
};

Pino* criarPinos(int n){
    Pino *pinos = (Pino*) malloc(n*sizeof(Pino));
    
    if(!pinos) exit(1);

    for(int i = 0; i < n; i++){
        pinos[i].topo = NULL;
        pinos[i].numDiscos = 0;
    }

    return pinos;
}

Disco* criarDisco(int tamDisco){
    Disco *disco = malloc(sizeof(Disco));

    if(!disco) exit(1);

    disco->tamDisco = tamDisco;
    return disco;
}

void push(Pino *pinos, Disco *disco, int indice){
    disco->next = pinos[indice].topo;
    pinos[indice].topo = disco;
    pinos[indice].numDiscos++;
}

Disco* pop(Pino *pinos, int indice){
    if(pinos[indice].topo == NULL) return NULL;
    Disco *disco = pinos[indice].topo;
    pinos[indice].topo = disco->next;
    pinos[indice].numDiscos--;
    return disco;
}

int moverDisco(Pino *pinos, int origem, int destino){
    if(pinos[origem].topo == NULL) return 0;
    if(pinos[destino].topo && pinos[origem].topo->tamDisco > pinos[destino].topo->tamDisco) return 0;
    Disco *tmp = pop(pinos, origem);
    push(pinos, tmp, destino);

    return 1;
}

void imprimirDisco(int tamDisco, int numDiscos){
    int i;
    numDiscos -= tamDisco;

    for(i = 0; i <= numDiscos; i++) printf(" ");
    for(i = 0; i < tamDisco; i++) printf("_");
    printf("|");
    for(i = 0; i < tamDisco; i++) printf("_");
    for(i = 0; i <= numDiscos; i++) printf(" ");
}

int buscarDisco(int nivel, Pino *pino){
    if(nivel <= pino->numDiscos){
        Disco *disco = pino->topo;
        char numDiscos = pino->numDiscos;
        while(nivel++ < numDiscos)
            disco = disco->next;
        return disco->tamDisco;
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
    free(pinos);
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

    while(!(destino > 0 && pinos[destino].numDiscos == numDiscos)){
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
    desalocar(pinos, numPinos);
}

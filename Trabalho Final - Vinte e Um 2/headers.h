#ifndef Headers_H
#define Headers_H
#define SUCESSO 0 
#include <string.h>
#include <time.h>

typedef struct {
        char naipe[10];
        int numero;
} Carta;

typedef struct {
        Carta c[52];
        int topo;
} Baralho;

typedef struct {
	Carta c[5];
	int n;
} Mao;

typedef struct {
	Mao m;
	int aposta;
	char nome[10];
} Jogador;

void criaBaralho(Baralho *b1);
void baralhar(Baralho *b1);
void compra(Baralho *b1, Jogador *j1);
void exibebaralho(Baralho *b1);
void exibecarta(Carta c);
void inicializaMao(Jogador *j1);
void exibeMao(Jogador *j1);
void trocarCarta(Baralho *b1, Jogador *j1, Carta *c1);
void apostas(Jogador *j1,Jogador *j2,int *mesa, int *acabou);
int recebeAposta(Jogador *j1,Jogador *j2,int *mesa);
void fimVencedor(Jogador *j1, int *mesa);
void resultado(Jogador *j1,Jogador *j2,int *mesa);

#endif

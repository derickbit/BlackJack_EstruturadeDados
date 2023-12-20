#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"
#include <string.h>
#include <time.h>

void criaBaralho(Baralho *b1){
	b1->topo=-1;
	int i=0, j=0, num;
		
	for(i=1;i<=4;i++){
		
		if(i==1) {
			num=1;
		    for (j=0; j<13; j++){
				strcpy(b1->c[j].naipe, "Copas");
  				b1->c[j].numero=num;
  				b1->topo++;
  				num++;
		}}
		
		if(i==2) {		    	
			num=1;
		    for (j=13; j<26; j++){
				strcpy(b1->c[j].naipe, "Ouro");
  				b1->c[j].numero=num;
  				b1->topo++;
  				num++;
		}}
		
		if(i==3) {		    	
			num=1;
		    for (j=26; j<39; j++){
				strcpy(b1->c[j].naipe, "Paus");
  				b1->c[j].numero=num;
  				b1->topo++;
  				num++;
		}}
				
		if(i==4) {		    	
			num=1;
		    for (j=39; j<52; j++){
		    	b1->c[j].numero=num;
				strcpy(b1->c[j].naipe, "Espadas");
  				b1->topo++;
  				num++;
		}		}
		}
		}

void baralhar(Baralho *b1){
	int i;
	Carta temp;
	srand(time(NULL));
	for (i=0; i<52; i++){
		int r = rand() %52;
		Carta temp = b1->c[i];
		b1->c[i]=b1->c[r];
		b1->c[r]=temp;
	}
}

void compra(Baralho *b1, Jogador *j1){
		Carta c;
          c=b1->c[b1->topo];
          b1->topo--;
          j1->m.c[j1->m.n]=c;
          j1->m.n++;
}

void exibecarta(Carta c){
	printf("\tCarta: %d de %s\n", c.numero, c.naipe);
}

void exibebaralho(Baralho *b1){
     int i;
     Carta c;
     for (i=b1->topo;i>=0;i--){
         exibecarta(b1->c[i]);     
}}

void exibeMao(Jogador *j1) {
	int i;
	printf("\t%s, sua Mao:\n", j1->nome);
	for (i=0; i<j1->m.n; i++) 
		exibecarta(j1->m.c[i]);
	printf("\n");			
}

void inicializaMao(Jogador *j1){
	j1->m.n=0;
}

void trocarCarta(Baralho *b1, Jogador *j1, Carta *c1){
	int i=0,j=0,achou=0;
	for(i=0; i<j1->m.n;i++){
		if(c1->numero==j1->m.c[i].numero){
			for(j=i;j<=j1->m.n;j++){
			j1->m.c[j]=j1->m.c[j+1];
			}
			achou=1;
			j1->m.n--;
		}
		if(achou==1) break;
		}
	compra(b1,j1);
}

void apostas(Jogador *j1,Jogador *j2,int *mesa, int *acabou){
	int opcao=0,retorno=0;
	
	do{
		printf("\n\t%s, quanto voce deseja apostar? (Digite 0 para passar) - ",j1->nome);
		scanf("%d", &j1->aposta);
		printf("\n\t%s apostou %d\n", j1->nome, j1->aposta);
		delay(1);
		retorno=recebeAposta(j1,j2,mesa);
		if(retorno==1) {
		*acabou=1;
		break;
		}
		
	} while (j1->aposta!=j2->aposta);
	

	if(*acabou!=1){
	*mesa=*mesa+j1->aposta+j2->aposta;
	printf("\n\tRodada de apostas encerrada!\n\tVALOR DA MESA: %d\n", *mesa);
	}
}

int recebeAposta(Jogador *j1,Jogador *j2,int *mesa){ 
		int opcao=0,acabou=0;
	
			do{
			printf("\n\t%s, voce pode pagar, aumentar ou desistir:\n",j2->nome);
			delay(1);
			printf("\n\t1-PAGAR\n\t2-AUMENTAR\n\t3-DESISTIR\n\n\tO que voce escolhe? ");
			scanf("%d", &opcao);
			if(opcao!=1 && opcao!=2 && opcao!=3) printf("\n\tOPCAO INVALIDA - digite novamente.\n");
			} while (opcao!=1 && opcao!=2 && opcao!=3);
			switch(opcao){
			case 1: 
				j2->aposta=j1->aposta;
				printf("\n\t%s pagou!\n",j2->nome); 
				delay(1);
				return 0;
				break;
			case 2:
				do{
				printf("\n\t%s, quanto voce deseja apostar? ",j2->nome);
				scanf("%d", &j2->aposta);
				if(j2->aposta < j1->aposta) printf("\n\tPara aumentar a aposta, o valor deve ser maior que a aposta anterior\n");
				if(j2->aposta==j1->aposta){
					printf("\n\tValor igual a aposta anterior. Entao voce paga!\n");
					delay(1);
					j2->aposta=j1->aposta;
					return 0;
					}
				if(j2->aposta > j1->aposta) {
					if(recebeAposta(j2,j1,mesa)==1){
					acabou==1; 
					break;}
				}
				}while (j2->aposta<j1->aposta);	
				//return 0;			
				break;
			case 3: printf("\n\t%s DESISTIU", j2->nome);
					delay(1);
					*mesa=*mesa+j1->aposta;
					fimVencedor(j1, mesa);
					return 1;
					break;			
			}}
			
void fimVencedor(Jogador *j1, int *mesa){
	delay(1);
	printf("\n\tFIM DE JOGO!\n\n\t%s e o(a) vencedor(a), levando pra casa o valor total da mesa: %d\n",j1->nome, *mesa);
}			

void resultado(Jogador *j1,Jogador *j2,int *mesa){
		int s1=0, s2=0,i=0,p1=0,p2=0,empate=0;
		empate=*mesa/2;
		for(i=0; i<j1->m.n;i++){
		s1=s1+j1->m.c[i].numero;
		}
	p1=21-s1;
	printf("\n\tSomatorio das cartas de %s: %d\n",j1->nome, s1);
	delay(1);
	
		for(i=0; i<j2->m.n;i++){
		s2=s2+j2->m.c[i].numero;
		}
	p2=21-s2;
	printf("\n\tSomatorio das cartas de %s: %d\n",j2->nome, s2);
	delay(1);
	
	if(p1>0 && p2>0) {	
		if(p1==p2) printf("\n\tJOGO EMPATADO!\n%s e %s dividem a mesa: premio de %d para cada um\n",j1->nome,j2->nome,empate);
		if(p1>p2) fimVencedor(j2,mesa);
		if(p2>p1) fimVencedor(j1,mesa);
	} else if (p1<0 && p2<0) printf("\n\tJOGO EMPATADO!\n%s e %s ESTOURARAM 21, e o valor de %d fica para o Dealer\n",j1->nome,j2->nome,mesa);
		else if (p1<0 && p2!=0) {
		printf("\n\t%s ESTOUROU 21!\n",j1->nome);
		fimVencedor(j2,mesa);
		}
		else if (p2<0 && p1!=0) {
		printf("\n\t%s ESTOUROU 21!\n",j2->nome);
		fimVencedor(j1,mesa);
		}
		else if (p1==0 && p2!=0) {
		printf("\n\t%s CRAVOU 21!\n",j1->nome);
		fimVencedor(j1,mesa);
		}
		else if (p2==0 && p1!=0) {
		printf("\n\t%s CRAVOU 21!\n",j2->nome);
		fimVencedor(j2,mesa);
		}
		else if (p1==p2) {
		printf("\n\tJOGO EMPATADO!\n%s e %s CRAVARAM 21 e dividem a mesa: premio de %d para cada um\n",j1->nome,j2->nome,empate);
		}
		}
		
	void delay(int segundos){
    int milisegundos = 1000 * segundos;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milisegundos);
}

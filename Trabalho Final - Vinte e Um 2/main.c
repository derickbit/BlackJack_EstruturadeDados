#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <dos.h>
#include <time.h>

main() {
	int op=0;
	Carta c1;
	Baralho b1;
	Jogador j1,j2;
	int mesa=0,acabou=0;
	
	
	criaBaralho(&b1);
	//exibebaralho(&b1);
	baralhar(&b1);
	inicializaMao(&j1);
	inicializaMao(&j2);
	//exibebaralho(&b1); //função para teste do baralho
	
	printf("\n\tSejam muito bem vindos a uma nova versao do jogo BlackJack 1 contra 1!\n");
	delay(1);
	printf("\n\tREGRAS:\n");
	printf("\tTeremos rodadas de compras, rodadas de apostas e por fim uma rodada de troca;\n");
	printf("\tO jogador cujo somatorio das cartas passar de 21 ao fim do jogo perde automaticamente;\n");
	printf("\tSe ambos jogadores passarem de 21, o Dealer fica com todo valor apostado;\n");
	printf("\tO jogador que mais se aproximar de 21 leva todo valor apostado.\n");
	delay(2);
	
	printf("\n\tLET'S GET STARTED'\n");
	printf("\tInsira o nome do jogador 1 - ");
	gets(j1.nome);
	delay(1);
	printf("\n\tSeja bem vindo(a) %s\n\n", j1.nome); 
	delay(1);
	
	printf("\tInsira o nome do jogador 2 - ");
	gets(j2.nome);
	delay(1);
	printf("\n\tSeja bem vindo(a) %s\n\n", j2.nome); 
	delay(1);
	
	do{
	printf("\n\tVamos comecar em ordem respectiva dos jogadores.\n\t%s, hora de comprar sua primeira carta!\n",j1.nome);
	delay(1);
	compra(&b1,&j1);
	exibeMao(&j1);
	delay(1);
	
	printf("\n\n\tAgora e sua vez %s, hora de comprar sua primeira carta!\n",j2.nome);
	delay(1);
	compra(&b1,&j2);
	exibeMao(&j2);
	delay(1);
	
	printf("\n\tRodada de apostas!\n");
	apostas(&j1,&j2,&mesa,&acabou);
	if(acabou==1) break;
	delay(1);

	printf("\n\tSEGUNDA RODADA\n\n");
	delay(1);
	exibeMao(&j1);
	printf("\t%s voce deseja comprar uma nova carta? 0-N/1-S - ", j1.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) compra(&b1, &j1);
	exibeMao(&j1);
	
	exibeMao(&j2);
	printf("\t%s voce deseja comprar uma nova carta? 0-N/1-S - ", j2.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) compra(&b1, &j2);
	exibeMao(&j2);
	
	printf("\n\tRodada de apostas!\n");
	apostas(&j1,&j2,&mesa,&acabou);
	if(acabou==1) break;
	delay(1);
	
	printf("\n\tTERCEIRA RODADA (ultima rodada antes da rodada de troca)\n\n");
	exibeMao(&j1);
	printf("\t%s voce deseja comprar uma nova carta? 0-N/1-S - ", j1.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) compra(&b1, &j1);
	exibeMao(&j1);
	
	exibeMao(&j2);
	printf("\t%s voce deseja comprar uma nova carta? 0-N/1-S - ", j2.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) compra(&b1, &j2);
	exibeMao(&j2);
	
	printf("\n\tRodada de apostas!\n");
	apostas(&j1,&j2,&mesa,&acabou);
	if(acabou==1) break;
	delay(1);
	
	printf("\n\tRODADA DE TROCA\n\n");
	exibeMao(&j1);
	printf("\t%s voce deseja trocar uma carta da sua mao? 0-N/1-S - ", j1.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) {
		exibeMao(&j1);
		printf("\n\tQual carta voce deseja trocar?");
		scanf("%d", &c1.numero);	
		trocarCarta(&b1, &j1, &c1);
		exibeMao(&j1);
	}
	
	exibeMao(&j2);
	printf("\t%s voce deseja trocar uma carta da sua mao? 0-N/1-S - ", j2.nome);
	scanf("%d", &op);
	delay(1);
	if(op==1) {
		exibeMao(&j2);
		printf("\n\tQual carta voce deseja trocar? ");
		scanf("%d", &c1.numero);	
		trocarCarta(&b1, &j2, &c1);
		exibeMao(&j2);
	}
	
	resultado(&j1,&j2,&mesa);
} while(acabou=!1);

}

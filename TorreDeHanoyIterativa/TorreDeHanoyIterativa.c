/*------------------------------------------------------------------------------
 * Name: TorreDeHanoyIterativa.c
 * Author: Leonardo do Nascimento
 * Date: 12/09/2014
 * Description: Programa que resolve a torre de Hanoy sem o uso da recustividade
 * Created on: Linux Mint Mint 17 Qiana
 * Link: https://github.com/LeonardoFuba/TorreDeHanoyIterativa
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

/* solucao torre de hanoi até 250 discos */

enum posicao{A,B,C};

/* prototipos de funcoes */
long int posicao_inicial(int disco);
int par(int valor);
char L(int posicao);


int main(){
  printf("\n\t\t\t\tTORRE DE HANOY\n\n");

	int i,j,k;
	int num_discos;
	int nun_de_mov;

  printf("Digite a quantidade de discos: ");
  scanf("%d",&num_discos);
	nun_de_mov = pow(2,num_discos)-1;
	char solucao[3][nun_de_mov];

	/* sequencia de discos que devem ser movimentados */
	for(i=1;i<=num_discos;i++){
		j = posicao_inicial(i);
		while(j<nun_de_mov){
			solucao[0][j] = i;
			j = j + (int)pow(2,i);
		}
	}


  /*
  *se é disco par, muda uma letra
  *se é disco ímpar, muda duas letras
  *sequencia %3
  */

	/* sequencia das letras */
	for(i=1;i<=num_discos;i++){
		j = posicao_inicial(i);
		k = 0;
		while(j<nun_de_mov){
			solucao[1][j] = k;

			if( par(num_discos) ){
				if( par(i) ){
					k = (k+2)%3;
					solucao[2][j] = k;
				}
				else{
					k = (k+1)%3;
					solucao[2][j] = k;
				}
			}

			else{
				if( par(i) ){
					k = (k+1)%3;
					solucao[2][j] = k;
				}
				else{
					k = (k+2)%3;
					solucao[2][j] = k;
				}
			}
			j = j + (int)pow(2,i);
		}
	}

	/* enxergar resultados */
	for(i=0;i<nun_de_mov;i++)
		printf("Mover disco %d da torre %c para a torre %c\n",solucao[0][i], L(solucao[1][i]), L(solucao[2][i]));

  printf("\n\n\n");
  return 0;
}/*****************FIM MAIN******************/


long int posicao_inicial(int disco){
	return( ((long int)pow(2,disco-1))-1 );
}


int par(int valor){
	if(0==valor%2)
		return true;
	else
		return false;
}


char L(int posicao){
	char t;
	switch(posicao){
		case A: t = 'A';break;
		case B: t = 'B';break;
		case C: t = 'C';break;
		default: break;
	};
	return t;
}


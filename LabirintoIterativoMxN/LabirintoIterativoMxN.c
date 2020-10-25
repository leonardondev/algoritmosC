/*------------------------------------------------------------------------------
 * Name: LabirintoIterativoMxN.c
 * Author: Leonardo do Nascimento
 * Date: 23/09/2014
 * Description: Programa que encontra a saida do labirinto se o uso da recustividade
 * Created on: Linux Mint Mint 17 Qiana
 * Link: https://github.com/LeonardoFuba/LabirintoIterativoMxN
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/* variaveis globais */
FILE *leitura;  /*ponteiro para o arquivo*/


int lAnt=-1;
int cAnt=0;
int saida=1;
int beco=0;

/* prototipos de funcoes */
void andar (int M[][c], int posL, int posC);
void movimento(const char* mov);


/* funcao principal */
int main(int argc, char **argv)){
   int l=atoi(argv[1]);/* numero de linhas do labirinto */
   int c=atoi(argv[2]);/* numero de colunas do labirinto */
  
   /* declaracao */
   int i,j,k,tam;
   int maze[argv[1]][argv[2]];

   /* leitura aponta para o arquivo */
   leitura = fopen(argv[3],"r");/* arquivo que sera aberto contendo a matriz do labirinto */
   if(leitura==NULL){
      puts("O ARQUIVO NAO FOI ENCONTRADO\n");
      while (1);
   }
   else{
      printf ("ARQUIVO ENCONTRADO\n\n");
   }

   /* leitura da matriz maze escrita em um arquivo de texto */
   k=0;
   tam=0;
   for(i=0;i<l;i++){
      for(j=0;j<c;j++){
         k = fscanf(leitura,"%d",&maze[i][j]);
         if (k!=1) break;/* ate ser NULL */
         tam++;
      }
   }

   fclose (leitura);

   /* teste para confirmar se leu todos os pontos */
   if(tam != l*c){
      puts("falta informacao no arquivo");
      while (1);
   }
   /* FIM DA LEITURA DO ARQUIVO */

   for(i=0;i<l;i++){
      for(j=0;j<c;j++){
         printf("%d ",maze[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   andar(maze,0,0);
   return 0;
}

void movimento(const char* mov){
      printf("%s",mov);
      return;
}


void andar (int M[][c], int posL, int posC){
    /*printf("\n p atual A[%d][%d]: ",posL,posC); */

  /* condicao trivial */
  if(beco==1)
    return;

  if( (posL==l-1)&&(posC==c-1) ){
    saida = 1;
    printf("FIM\n\n");
    system("pause");
    exit(0);
  }
  else{

    if(lAnt==posL-1){/* veio de cima */
      lAnt=posL;
      if((posC!=(c-1))&&(M[posL][posC+1]==0)){/* nao ultima coluna e pode direita */
        beco = 0;
        movimento("PARA DIREITA\n");
        andar( M,posL ,posC+1);
      }/* direita */
      if((posL!=(l-1))&&(M[posL+1][posC]==0)){/* nao ultima linha e pode baixo */
        beco = 0;
        movimento("PARA BAIXO\n");
        andar(M,posL+1, posC );
      }/* baixo */
      if((posC!=0)&&(M[posL][posC-1]==0)){/* nao primeira coluna e pode esquerda */
        beco = 0;
        movimento("PARA ESQUERDA\n");
        andar( M,posL ,posC-1);
      }/* esquerda */
      lAnt=posL-1;
      beco=1;
      printf("VOLTA P CIMA \n");
    }

    if(cAnt==posC-1){/* veio da esquerda */
      cAnt=posC;
      if((posL!=(l-1))&&(M[posL+1][posC]==0)){/* nao ultima linha e pode baixo */
        beco = 0;
        movimento("PARA BAIXO\n");
        andar(M,posL+1, posC );
      }/* baixo */
      if((posC!=(c-1))&&(M[posL][posC+1]==0)){/* nao ultima coluna e pode direita */
        beco = 0;
        movimento("PARA DIREITA\n");
        andar( M,posL ,posC+1);
      }/* direita */
      if((posL!=0)&&(M[posL-1][posC]==0)){/* nao primeira linha e pode cima */
        beco = 0;
        movimento("PARA CIMA\n");
        andar(M,posL-1, posC );
      }/* cima */
      cAnt=posC-1;
      beco=1;
      printf("VOLTA P ESQUERDA \n");
    }

    if(lAnt==posL+1){/* veio de baixo */
      lAnt=posL;
      if((posC!=(c-1))&&(M[posL][posC+1]==0)){/* nao ultima coluna e pode direita */
        beco = 0;
        movimento("PARA DIREITA\n");
        andar( M,posL ,posC+1);
      }/* direita */
      if((posL!=0)&&(M[posL-1][posC]==0)){/* nao primeira linha e pode cima */
        beco = 0;
        movimento("PARA CIMA\n");
        andar(M,posL-1, posC );
      }/* cima */
      if((posC!=0)&&(M[posL][posC-1]==0)){/* nao primeira coluna e pode esquerda */
        beco = 0;
        movimento("PARA ESQUERDA\n");
        andar( M,posL ,posC-1);
      }/* esquerda */
      lAnt=posL+1;
      beco = 1;
      printf("VOLTA P BAIXO \n");
    }

    if(cAnt==posC+1){/* veio da direita */
      cAnt=posC;
      if((posL!=(l-1))&&(M[posL+1][posC]==0)){/* nao ultima linha e pode baixo */
        beco = 0;
        movimento("PARA BAIXO\n");
        andar(M,posL+1, posC );
      }/* baixo */
      if((posL!=0)&&(M[posL-1][posC]==0)){/* nao primeira linha e pode cima */
        beco = 0;
        movimento("PARA CIMA\n");
        andar(M,posL-1, posC );
      }/* cima */
      if((posC!=0)&&(M[posL][posC-1]==0)){/* nao primeira coluna e pode esquerda */
        beco = 0;
        movimento("PARA ESQUERDA\n");
        andar( M,posL ,posC-1);
      }/* esquerda */
      cAnt=posC+1;
      beco=1;
      printf("VOLTA P DIREITA \n");
    }

    return;
  }

  while(1);
  return;
}

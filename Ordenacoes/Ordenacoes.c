/*------------------------------------------------------------------------------
 * Name: Ordenacoes.c
 * Author: Leonardo do Nascimento
 * Date: 02/12/2014
 * Description: Programa que ordena um vetor preenchido aleatoriamente com um
 *              dos 3 metodos de ordenacao
 * Created on: Linux Mint Mint 18.3 Sylvia
 * Link: https://github.com/LeonardoFuba/Ordenacoes
 *----------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int c=0;				/* contador */
int heapsize=1;	/* variavel global do heapsort */

/* funcoes quicksort */
void Quicksort(int x[], int i, int f);
int Partition(int x[], int left, int right);
void Troca (int* a, int* b);

/* funcoes sellsort */
void Shellsort(int x[], int tamx, int gaps[], int numgaps);
int NumGaps(int tamx);
void Gaps(int gaps[], int n);

/* funcoes heapsort */
void Heapify(int A[], int heapsize, int i);
void Buildheap(int *A, int heapsize);
void Heapsort(int *A, int heapsize);
int Parent (int i);
int Left (int i);
int Right (int i);

/* funcoes mergesort */
void MergeSort(int A[], int e, int d);
void Merge (int x[], int m1, int m2, int m3);

main(){

	int tam;
	printf(" Entre com o tamanho do vetor que ira ordenar: ");
	scanf("%d",&tam);

	printf("\n Vetor:\n");
	int* x = (int*)malloc(tam*sizeof(int));
	if(x==NULL){
		printf("memoria nao alocada! \n\n");
		getchar();
		exit(1);
	}

	/* preenche com numeros aleatórios */
	srand (time(NULL));

	for(c=0;c<tam;c++){
		x[c] = rand()%240 + 10;
		printf(" %d",x[c]);
	}

	int op;
	/* menu */
	printf("\n\n Escolha o tipo de ordenação\n");
	printf("\n\t1 - Quicksort");
	printf("\n\t2 - Shellsort");
	printf("\n\t3 - Heapsort");
	printf("\n\t4 - Mergesort\n\n ");
	scanf("%d",&op);

	switch(op){
		case 1:{
			Quicksort(x,0,tam);break;
		}
		case 2:{
			int gaps[NumGaps(tam)];
			printf("gaps[NumGaps(%d)]\n",tam);
			printf("gaps[%d]\n",NumGaps(tam));
			Gaps(gaps,NumGaps(tam));
			int i;
			for(i=0;i<NumGaps(tam);i++)
				printf("%d ",gaps[i]);
			Shellsort(x,tam,gaps,NumGaps(tam));
			break;
		}
		case 3:{
			heapsize = tam;
			Heapsort(x,heapsize);
			break;
		}
		case 4:{
			MergeSort(x,0,tam-1);
			break;
		}
	}

	printf("\nVetor ordenado:\n");
	for(c=0;c<tam;c++)
		printf(" %d",x[c]);

	puts("\n");
}/* fim main */

void Quicksort(int x[], int i, int f){
	int p;
	if (i > f)
		return;
	p = Partition(x, i, f);
	Quicksort(x, i, p - 1);
	Quicksort(x, p + 1, f);
}/* fim Quicksort */

int Partition(int x[], int left, int right){

	int a, down, up;

	a = x[left];
	up = right;
	down = left;

	while(down<up){
		while(x[down]<=a && down < right)
			down++;
		while(x[up]>a)
			up--;
		if(down<up)
			Troca(&x[down],&x[up]);

	}
	x[left]=x[up];
	x[up] = a;
	return up;
}/* fim Partition */

void Troca (int* a, int* b){
	int aux = *b;
	*b = *a;
	*a = aux;
	return;
}

void Shellsort(int x[], int tamx, int k[], int numgaps){
	/*  gaps eh um array contendo os incrementos. */
	int i, j, n, pulo, temp;

	for(n=0;n < numgaps ; n++){
		pulo = k[n];/* quantidades de subvetores */

		for(j=pulo;j<tamx;j++){/* começa no 2o elemento do primeiro subvetor */
			temp = x[j];
			for(i=(j-pulo) ; (i>=0) && (temp < x[i]) ; i = (i-pulo) ){/* i começa no elemento a esquerda de j do mesmo subvetor e leva temp para esquerda até a posição certa. */
					x[i+pulo] = x[i];
			}/* se temp é menor, desloca elemento para a posição de temp e coloca tempa esquerda deste. */
			x[i+pulo] = temp;
		}
	}
}/* fim Shellsort */

int NumGaps(int tamx){
	int k=1;
	int aux=0;
	do{
		k++;
		aux = (int)ceil( (pow(9,k)-pow(4,k))/(5*pow(4,k-1)) ); /* Tokuda, Naoyuki (1992) */
	}while(aux<tamx);
	return(k+1);
}/* fim NumGaps */

void Gaps(int gaps[], int n){
	for(c=1;c<=n;c++){
		gaps[c-1] = (int)ceil( (pow(9,c)-pow(4,c))/(5*pow(4,c-1)) );
	}
}/* fim Gaps */

/* Suponha heapsize uma variavel global e A um array comecando em 0 */
void Heapify(int A[], int heapsize, int i){
	int esq, 	dir, pai=0;
	esq = Left(i);
	dir = Right(i);
	if ((esq <= heapsize) && (A[esq-1] > A[i-1])){
		pai = esq;
	}
	else
		pai = i;/* pai é indice do maior dos dois */
	if ((dir <= heapsize) && (A[dir-1] > A[pai-1])){
		pai = dir;/* pai é indice do maior dos três */
	}
	if (pai != i){
		Troca(&A[i-1], &A[pai-1]);/* pai troca com elemento do nivel de cima */

		/* troca a posicao dos elementos */
		Heapify(A, heapsize, pai);/* heap no */
	}
	return;
}/* fim Heapify */



void Buildheap(int *A, int heapsize){
	for (c = (int)(heapsize/2); c > 1; c--)
		Heapify(A, heapsize, c);
		Heapify(A, heapsize, c);
}/* fim Buildheap */


void Heapsort(int *A, int heapsize){
	Buildheap(A, heapsize);
	for (c = heapsize-1; c > 0; c--){
		Troca(&A[0], &A[c]);/* maior vai para última posição */
		heapsize--;/* heapsize deve ser global para usar por toda a recursão */
		Heapify(A, heapsize, 1);/* organiza subárvore com novo heapsize */
	}
}/* fim Heapsort */

int Parent (int i){
	return (int)(i/2);
}

int Left (int i){
	return (2*i);
}

int Right (int i){
	return (2*i+1);
}

void MergeSort(int A[], int e, int d){
	int q;
	if (e < d){
		q = (int)((e+d)/2);
		printf("%d",q);
		MergeSort(A, e, q);
		MergeSort(A, q+1, d);
		Merge(A, e, q, d);
	}
}/* fim MergeSort */


void Merge (int x[], int m1, int m2, int m3){
	int i,y[10];
	int apoint, bpoint, cpoint;
	int n1, n2, n3;
	apoint = m1; bpoint = m2+1;
	for( cpoint = m1; apoint <= m2 && bpoint <= m3; cpoint++)
		if (x[apoint] < x[bpoint])
			y[cpoint] = x[apoint++];
		else
			y[cpoint] = x[bpoint++];
	while (apoint <= m2)
		y[cpoint++] = x[apoint++];
	while (bpoint <= m3)
		y[cpoint++] = x[bpoint++];

	for(i=m1;i<=m3;i++)
		x[i] = y[i];
}/* fim merge */

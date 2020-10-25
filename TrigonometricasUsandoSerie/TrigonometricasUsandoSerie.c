/*------------------------------------------------------------------------------
 * Name: TrigonometricasComSerie.c
 * Author: Leonardo do Nascimento
 * Date: 14/06/2019
 * Description: Programa que calcula as funcoes trigonometricas atraves
 *              da serie de Taylor.
 * Created on: Linux Mint Mint 18.3 Sylvia
 * Link: https://github.com/LeonardoFuba/TrigonometricasUsandoSerie
 *----------------------------------------------------------------------------*/



#include <stdio.h>
#include <math.h>

/* prototipos de funcoes */
double cos3(double angulo);
double sen3(double angulo);
double cos40(double angulo);
double sen40(double angulo);
int fatorial(int n);	/*funciona ate 7!*/
double fatoracao(double teta,double k);


int main()
{
	/* variaveis */
	float grau;
	double rad;

	double cos1;
	double sen1;

	double cos2;
	double sen2;

	double cosExato;
	double senExato;

	double erroCosAbs;
	double erroSenAbs;
	double erroCosPer;
	double erroSenPer;


	/*entrada do usuário*/
	printf("digite um angulo em graus\n");
	scanf("%f", &grau);

	/*conversao para rad*/
	/*dentro da math.h tem a contante M_PI que vale pi com 20 casas*/
	rad = grau*(M_PI/180);


/*----------------------------------------------------------------------------*/
	/*calculo*/
	cos1 = cos3(rad);
	sen1 = sen3(rad);
	/*resultados para 3 termos*/
	printf("cos(%f) para 3 termos vale %f\n",grau, cos1);
	printf("sen(%f) para 3 termos vale %f\n",grau, sen1);



/*----------------------------------------------------------------------------*/
	/*calculo*/
	cos2 = cos40(rad);
	sen2 = sen40(rad);
	/*resultados para 40 termos*/
	printf("\n");
	printf("cos(%f) para 40 termos vale %f\n",grau, cos2);
	printf("sen(%f) para 40 termos vale %f\n",grau, sen2);



/*----------------------------------------------------------------------------*/
	/*calculo*/
	cosExato = cos(rad);
	senExato = sin(rad);
	/*resultados para a funcao da math.h*/
	printf("\n");
	printf("cos(%f) usando a math.h vale %f\n",grau, cosExato);
	printf("sen(%f) usando a math.h vale %f\n",grau, senExato);



/*----------------------------------------------------------------------------*/
	/*calculo dos erros para 3 termos*/
	erroCosAbs = fabs(cos1 - cosExato);
	erroSenAbs = fabs(sen1 - senExato);

	erroCosPer = (erroCosAbs/cosExato)*100;
	erroSenPer = (erroSenAbs/senExato)*100;

	printf("\n");
	printf("erro absoluto para o cosseno calculado com 3 termos da serie %f \n",erroCosAbs);
	printf("erro absoluto para o seno calculado com 3 termos da serie %f \n",erroSenAbs);
	printf("erro percentual para o cosseno calculado com 3 termos da serie %f%% \n",erroCosPer);
	printf("erro percentual para o seno calculado com 3 termos da serie %f%% \n",erroSenPer);


/*----------------------------------------------------------------------------*/
	/*calculo dos erros para 40 termos*/
	erroCosAbs = fabs(cos2 - cosExato);
	erroSenAbs = fabs(sen2 - senExato);

	erroCosPer = (erroCosAbs/cosExato)*100;
	erroSenPer = (erroSenAbs/senExato)*100;

	printf("\n");
	printf("erro absoluto para o cosseno calculado com 40 termos da serie %f \n",erroCosAbs);
	printf("erro absoluto para o seno calculado com 40 termos da serie %f \n",erroSenAbs);
	printf("erro percentual para o cosseno calculado com 40 termos da serie %f%% \n",erroCosPer);
	printf("erro percentual para o seno calculado com 40 termos da serie %f%% \n",erroSenPer);

	return 0;
}/*fim main*/


/*implementacoes das funcoes*/
double cos3(double angulo){
	double resultado = 0;
	int n;
	for (n = 0; n < 3; n++)
		resultado = resultado + ( pow(-1,n) * pow(angulo,2*n)/fatorial(2*n) );
	return resultado;
}

double sen3(double angulo){
	double resultado = 0;
	int n;
	for (n = 0; n < 3; n++)
		resultado = resultado + ( pow(-1,n) * pow(angulo,(2*n)+1)/fatorial((2*n)+1) );
	return resultado;
}


double cos40(double angulo){
	double resultado = 0;
	int n;
	for (n = 0; n < 40; n++)
		resultado = resultado + ( pow(-1,n) * fatoracao(angulo,2*n)  );
	return resultado;
}

double sen40(double angulo){
	double resultado = 0;
	int n;
	for (n = 0; n < 40; n++)
		resultado = resultado + ( pow(-1,n) * fatoracao(angulo,(2*n)+1 ) );
	return resultado;
}


int fatorial(int n){
	int fat = 1;
	while(n > 1){
		fat = fat * n;
		n--;
	}
	return fat;
}


double fatoracao(double teta,double k){
	double acumulador=1;
	int i;

	while(k > 0){
		acumulador = acumulador * (teta/k);
		k--;
	}
	return acumulador;
}



#include <stdio.h>

float tabuada (float num, int C, int F);

void main()
{
	float N;
	int A, B;
	
	printf("\nInsira o valor que vc deseja saber a tabuada: ");
	scanf("%f", &N);
	
	printf("\nInsira o ponto de comeco da tabuada: ");
	scanf("%d", &A);
	
	printf("\nInsira o ponto final da tabuada: ");
	scanf("%d", &B);
	
	tabuada(N, A, B);
}

float tabuada (float num, int C, int F)
{
	int i;
	float resultado;
	
	for(i=C; i<=F; i++)
	{
		resultado = num * i;
		printf("\n%1.1f * %1d = %1.1f", num, i, resultado);
	}
}

/*Pede-se uma função que, dados dois arquivos textos,
contendo números inteiros, determine se possuem os
mesmos valores, independente do número de
ocorrências de cada número nos arquivos.*/

#include <stdio.h>

int determinar (char A[], char B[]);
int procurar (char nome[], int *num);

void main()
{
	char nomeA[] = "av1-20221N-ex4-arqA.txt", nomeB[] = "av1-20221N-ex4-arqB.txt";
	int retorno = determinar(nomeA, nomeB);
	
	if(retorno == 1)
	{
		printf("Possuem os mesmos valores");
	}
	else
	{
		if(retorno == 0)
		{
			printf("Nao possuem os mesmos valores");
		}
		else
		{
			printf("Erro ao abrir o arquivo");
		}
	}
}

int determinar (char A[], char B[])
{
	FILE* arquivoA = fopen(A, "r");
	int numA, retorno;
	
	if(!arquivoA)
	{
		return -1;
	}
	else
	{
		while(fscanf(arquivoA, "%d", &numA) != EOF)
		{
			retorno = procurar(B, &numA);
			
			switch(retorno)
			{
				case 0:
					return 0;
					break;
					
				case -1:
					return -1;
					break;
			}
		}
		return 1;
		fclose(arquivoA);
	}
}

int procurar (char nome[], int *num)
{
	FILE* arquivo = fopen(nome, "r");
	int numB;
	
	if(!arquivo)
	{
		return -1;
	}
	else
	{
		while(fscanf(arquivo, "%d", &numB) != EOF)
		{
			if(numB == *num)
			{
				fclose(arquivo);
				return 1;
			}
		}
		return 0;
	}
}

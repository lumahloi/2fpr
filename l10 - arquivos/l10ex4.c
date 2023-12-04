/*Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.*/

#include <stdio.h>
#include <limits.h>

int main()
{
	FILE* arquivo;
	char nomeArquivo[] = "ex02.txt";
	int numAtual, numAnterior = INT_MIN;
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(arquivo == NULL)
	{
		printf("Erro de abertura do arquivo");
	}
	else
	{
		while(fscanf(arquivo, "%d", &numAtual) != EOF)
		{
			if(numAtual < numAnterior)
			{
				printf("Nao esta ordenado");
				return 0;
			}
			
			numAnterior = numAtual;
		}
	}
	printf("Esta ordenado");
	fclose(arquivo);
	return 1;
}

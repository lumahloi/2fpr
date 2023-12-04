/*
Considerando a existência de um arquivo A 
contendo números inteiros positivos, 
um por linha, pede-se a implementação de 
uma função que crie um segundo arquivo, 
B, com as seguintes características:

-  Para cada valor de A, escrever em B uma 
linha com todos os seus divisores;
- Para cada elemento do primeiro arquivo, 
apenas uma linha de divisores deve ser inserida em B.

Nota: a função deverá retornar 1 se a geração do arquivo 
B for bem sucedida. Caso contrário, retornará 0.
*/

#include <stdio.h>

int gerarDivisores(char nomeA[], char nomeB[]);

void main()
{
	char nomeA[] = "av12023-1Mex2-arqA.txt", nomeB[] = "av12023-1Mex2-arqB.txt";
	int retorno = gerarDivisores(nomeA, nomeB);
	
	if(retorno == 1)
	{
		printf("Arquivo gerado com sucesso");
	}
	else
	{
		printf("Erro ao gerar o arquivo");
	}
}

int gerarDivisores(char nomeA[], char nomeB[])
{
	FILE* arquivoA = fopen(nomeA, "r");
	FILE* arquivoB = fopen(nomeB, "w");
	int valorA, fim = 0, i, cont = 0, vetor[cont], repetiu;
	
	if(!arquivoA || !arquivoB)
	{
		return 0;
	}
	else
	{
		//ver o valor de A;
		fscanf(arquivoA, "%d", &valorA);
		
		while (!fim)
		{
			repetiu = 0;
			
			//ver se o valorA já apareceu antes
			for(i = 0; i < cont; i++)
			{
				if(vetor[i] == valorA)
				{
					repetiu = 1;
					
					//pular numero
					if(fscanf(arquivoA, "%d", &valorA) == EOF)
					{
						fim = 1;
					}
					break;
				}
			}
			
			if(!repetiu)
			{
				//ver os divisores
				for(i = 1; i <= valorA; i++)
				{
					if(valorA % i == 0)
					{
						fprintf(arquivoB, "%d ", i);
					}
				}
				fprintf(arquivoB, "\n");
				
				vetor[cont] = valorA;
				cont++;
				
				if(fscanf(arquivoA, "%d", &valorA) == EOF)
				{
					fim = 1;
				}	
			}
		}
		
		vetor[cont] = '\0';
		
		fclose(arquivoA);
		fclose(arquivoB);
		
		return 1;
	}
}

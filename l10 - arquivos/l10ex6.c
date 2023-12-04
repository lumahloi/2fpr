/*	
	Quest�o 06:
	Desenvolver uma fun��o que, dados dois arquivos textos arqA e arqB, crie um 
	novo arquivo arqC, considerando que:

	- arqA e arqB cont�m n�meros reais, um por linha, ordenados crescentemente e 
	  sem repeti��o no arquivo; 
	- arqC deve conter todos os n�meros dos dois arquivos originais;
	- Assim como arqA e arqB, arqC tamb�m n�o possuir� repeti��es de elementos e 
	  estes dever�o estar ordenados de forma crescente.
	  
	Arquivo A: 1 5 8 9 10
	Arquivo B: 2 3 4 8 10 15 16
	
	Arquivo C: 1 2 3 4 5 8 9 10 15 16
	
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//prot�tipos das fun��es
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

//main
void main ()
{
	//chamando a fun��o
	if (uniao ("ex06A.txt", "ex06B.txt", "ex06C.txt") == 1)
	{
		printf ("\nArquivo uniao criado com sucesso!\n");
	}
	else
	{
		printf ("\nArquivo uniao nao criado!\n");
	}
}

//implementa��o das fun��es
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declara��o de vari�veis
	FILE *arqA, *arqB, *arqC;
	int fimA = 0, fimB = 0, numA, numB;
	
	//tentando abrir os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "r");
	arqC = fopen (nomeArqC, "w");
	
	//verificando se houve erro
	if ((!arqA) || (!arqB) || (!arqC))
	{
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 0;
	}
	else
	{
		//lendo o primeiro valor do arquivo A e o primeiro do arquivo B
		fscanf (arqA, "%d", &numA);
		fscanf (arqB, "%d", &numB);
		
		while ((!fimA) && (!fimB))
		{
			//comparando os valores dos dois conjuntos
			if (numA < numB)
			{
				//escreva no conjunto uni�o o valor de A (que � o menor)
				fprintf (arqC, "%d\n", numA);
				
				//leia o pr�ximo valor de A
				if (fscanf (arqA, "%d", &numA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numB < numA)
				{
					//escreva no conjunto uni�o o valor de B (que � o menor)
					fprintf (arqC, "%d\n", numB);
					
					//leia o pr�ximo valor de B
					if (fscanf (arqB, "%d", &numB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					//se chegou aqui, os valores de A e de B s�o iguais
					
					//escreva no conjunto uni�o o valor de A ou o de B (j� que s�o iguais)
					fprintf (arqC, "%d\n", numA);
				
					//leia o pr�ximo valor de cada arquivo
					if (fscanf (arqA, "%d", &numA) == EOF)
					{
						fimA = 1;
					}
					
					if (fscanf (arqB, "%d", &numB) == EOF)
					{
						fimB = 1;
					}
				}
			}
		}
		
		//neste ponto, pelo menos um dos arquivos terminou
		//if ((fimA) && (!fimB))
		if (!fimB)
		{
			fprintf (arqC, "%d\n", numB);
			
			while (fscanf (arqB, "%d", &numB) != EOF)
			{
				fprintf (arqC, "%d\n", numB);
			}
		}
		else
		{
			if (!fimA)
			{
				fprintf (arqC, "%d\n", numA);
				
				while (fscanf (arqA, "%d", &numA) != EOF)
				{
					fprintf (arqC, "%d\n", numA);
				}
			}
		}
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 1;
	}
}

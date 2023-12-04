/*Implementar uma função que, dado um arquivo
texto contendo números inteiros, um por linha, e
dois valores inteiros A e B, crie outros três arquivos,
como descritos a seguir:
- O primeiro deles conterá todos os valores do
arquivo original inferiores a A;
- O segundo será formado pelos valores do arquivo
original pertencentes ao intervalo de A a B;
- O último arquivo, por sua vez, conterá os
elementos maiores do que B.*/

#include <stdio.h>

void main()
{
	char nome1[] = "av2-20212Nex2-arq1.txt";
	int A = 20, B = 78, retorno = gerar(nome1, A, B);
	
	if(retorno == 1)
	{
		printf("Arquivos gerados com sucesso");
	}
	else
	{
		printf("Ocorreu um erro ao gerar os arquivos");
	}
}

int gerar(char original[], int num1, int num2)
{
	char nome2[] = "av2-20212Nex2-arq2.txt", nome3[] = "av2-20212Nex2-arq3.txt", nome4[] = "av2-20212Nex2-arq4.txt";
	int numero;
	
	FILE* arquivo1 = fopen(original, "r");
	FILE* arquivo2 = fopen(nome2, "w");
	FILE* arquivo3 = fopen(nome3, "w");
	FILE* arquivo4 = fopen(nome4, "w");
	
	if(!arquivo1 || !arquivo2 || !arquivo3 || !arquivo4)
	{
		return 0;
	}
	else
	{
		while(fscanf(arquivo1, "%d", &numero) != EOF)
		{
			if(numero < num1)
			{
				fprintf(arquivo2, "%d\n", numero);
			}
			else
			{
				if((numero >= num1)&&(numero <= num2))
				{
					fprintf(arquivo3, "%d\n", numero);
				}
				else
				{
					fprintf(arquivo4, "%d\n", numero);
				}
			}
		}
		
		return 1;
		
		fclose(arquivo1);
		fclose(arquivo2);
		fclose(arquivo3);
		fclose(arquivo4);
	}
}

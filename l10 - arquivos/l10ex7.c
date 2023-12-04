/*
Desenvolver uma fun��o que, dados dois
arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:

- arqA e arqB cont�m n�meros reais,
um por linha, ordenados
crescentemente e sem repeti��o no
arquivo;

- arqC deve conter apenas os n�meros
comuns aos dois arquivos originais;

- Assim como arqA e arqB, arqC
tamb�m n�o possuir� repeti��es de
elementos e estes dever�o estar
ordenados de forma crescente.
*/

#include <stdio.h>

int interseccao(char arqA[], char arqB[], char arqC[]);

void main()
{
	char arqA[] = "ex07A.txt", arqB[] = "ex07B.txt", arqC[] = "ex07C.txt";
	int retorno;
	
	retorno = interseccao(arqA, arqB, arqC);
	
	if(retorno == 1)
	{
		printf("Arquivo gerado com sucesso");
	}
	else
	{
		printf("Erro ao gerar arquivo");
	}
}

int interseccao(char arqA[], char arqB[], char arqC[])
{
	FILE* arquivoA = fopen(arqA, "r");
	FILE* arquivoB = fopen(arqB, "r");
	FILE* arquivoC = fopen(arqC, "w");
	
	int numA, numB, fimA = 0, fimB = 0;
	
	if((!arquivoA) || (!arquivoB) || (!arquivoC))
	{
		fclose(arquivoA);
		fclose(arquivoB);
		fclose(arquivoC);
		
		return 0;
	}
	else
	{
		//ver o primeiro valor
		fscanf(arquivoA, "%d", &numA);
		fscanf(arquivoB, "%d", &numB);
		
		while((!fimA) && (!fimB))
		{
			if(numA == numB)
			{
				//adicionar em C
				fprintf(arquivoC, "%d\n", numA);
				
				//ver o pr�ximo de ambos
				if (fscanf (arquivoA, "%d", &numA) == EOF)
				{
					fimA = 1;
				}
				
				if (fscanf (arquivoB, "%d", &numB) == EOF)
				{
					fimB = 1;
				}
			}
			else
			{
				if(numA > numB)
				{
					//� poss�vel que numA esteja em B ent�o procure o pr�ximo
					if (fscanf (arquivoB, "%d", &numB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					//� poss�vel que numB esteja em A ent�o procure o pr�ximo
					if (fscanf (arquivoA, "%d", &numA) == EOF)
					{
						fimA = 1;
					}
				}
			}
		}
		
		//fechando os arquivos
		fclose (arquivoA);
		fclose (arquivoB);
		fclose (arquivoC);
		
		return 1;
	}
}

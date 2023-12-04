/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>

void main()
{
	FILE* arquivo;
	char nomeArquivo[20] = "ex01.txt", caracter;
	char c = ' ';
	int cont;
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo");
	}
	else 
	{
		while(fscanf(arquivo, "%c", &caracter) != EOF)
		{
			if(caracter == c)
			{
				cont++;
			}
		}
		printf("%d", cont);
		fclose(arquivo);
	}
}

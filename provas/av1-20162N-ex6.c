/*
Fazer uma função que, dado um arquivo texto,
determine quantas vezes a string S encontra-se no
arquivo.
*/

#include <stdio.h>
#include <string.h>

void main()
{
	char nome[] = "av1-20162N-ex6-arqA.txt", palavra[] = "dolor";
	int qntd, retorno = determinar(nome, palavra, &qntd);
	
	switch(retorno)
	{
		case 1:
			printf("A palavra foi encontrada %d vezes", qntd);
			break;
		case 0:
			printf("Ocorreu um erro ao abrir o arquivo");
			break;
	}
}

int determinar(char nome[], char palavra[], int *qt)
{
	FILE* arquivo = fopen(nome, "r");
	char string[1000];
	
	if(!arquivo)
	{
		return 0;
	}
	else
	{
		while (fscanf(arquivo, "%c", &string) != EOF)
		{
			if(strcmp(palavra, string) == 0)
			{
				(*qt)++;
			}
		}
		return 1;
	}
}

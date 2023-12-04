/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>

void main()
{
	FILE* arquivo;
	char nomeArquivo[20] = "ex01.txt", caracter;
	int cont;
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(arquivo == NULL)
	{
		printf("Erro na abertura do arquivo");
	}
	else
	{
		while(fscanf(arquivo, "%c", &caracter) != EOF)
		{
			cont++;
		}
		
		printf("%d", cont);
		fclose(arquivo);
	}
}

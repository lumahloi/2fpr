/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).*/

#include <stdio.h>

void main()
{
	FILE *arquivo;
	char nomeArquivo[20] = "ex01.txt", caracter;
	int cont;
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo");
	}
	else
	{
		while (fscanf(arquivo, "%c", &caracter) != EOF)
		{
			caracter = toupper(caracter);
			
			if((caracter >= 'A')&&(caracter <= 'Z'))
			{
				cont++;
			}
		}
		printf("%d", cont);
		fclose(arquivo);
	}
}

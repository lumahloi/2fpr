#include <stdio.h>
#include <string.h>

int palindromo(char string[]);

int main()
{
	char minhaString[20];
	
	printf("\nInsira sua string: ");
	gets(minhaString);
	
	if(!palindromo(minhaString))
	{
		printf("\nA string '%s' eh um palindromo", minhaString);
	}
	else
	{
		printf("\nA string '%s' nao eh um palindromo", minhaString);
	}
	return 0;
}

int palindromo(char string[])
{
	// criar um novo vetor igual a 'string' porem dispor os elementos ao contrario
	int tam = strlen(string);
	
	char copia[tam];
	
	int i=0, j=(tam-1);
	
	for(i=0; i<tam; i++)
	{
		copia[i] = string[j];
		j--;
	}
	
	copia[i] = '\0';
	
	// comparar os 2 vetores
	return strcmp(copia, string);
}

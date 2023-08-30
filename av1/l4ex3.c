#include <stdio.h>
#include <string.h>

void criarSubstring(char string[], int pos, int quant, char subs[]);

int main()
{
	char s[20];
	char substring[20];
	int p, n;
	
	printf("\nInsira uma string (até 20 char): ");
	gets(s);
	
	printf("\nEm qual posicao se iniciara a substring? ");
	scanf("%d", &p);
	
	printf("\nQuantos caracteres tera a substring? ");
	scanf("%d", &n);
	
	criarSubstring(s, p, n, substring);
	printf("\n%s", substring);
	
	return 0;
}

void criarSubstring(char string[], int pos, int quant, char subs[])
{
	int i;
	int aux = pos;
	
	for(i=0; i < quant; i++)
	{
		subs[i] = string[aux];
		aux++;
	}
	subs[i] = '\0';
}

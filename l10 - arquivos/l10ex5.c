/*
	Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, um por 
	linha, crie um novo arquivo B contendo os mesmos elementos de A, por�m 
	ordenados decrescentemente e sem repeti��o.
*/

#include <stdio.h>
#include <limits.h>

int gerarArquivoDecrescente (char nomeArqOriginal[], char nomeArqNovo[]);
int buscaMaior (char nomeArquivo[], int limite, int *maior);

void main ()
{
	int retorno;
	char original[20] = "ex05A.txt", novo[20] = "ex05B.txt";
	
	//chamando a fun��o
	retorno = gerarArquivoDecrescente (original, novo);
	
	//exibindo o resultado
	if (retorno == 1)
	{
		printf ("\n\nO arquivo %s foi gerado com sucesso!\n", novo);
	}
	else
	{
		printf ("\n\nO arquivo %s nao foi gerado!\n", novo);
	}
}

int gerarArquivoDecrescente (char nomeArqOriginal[], char nomeArqNovo[])
{
	FILE *arqNovo;
	int retorno, limite, maior;
	
	arqNovo = fopen (nomeArqNovo, "w");
	
	//verificando se houve erro na abertura do arquivo
	if (!arqNovo)
	{
		return 0;
	}
	else
	{
		//inicializando 'limite' com um valor alto
		limite = INT_MAX;
		
		//enquanto existir valor a ser inserido no arquivo novo...
		while (retorno = buscaMaior (nomeArqOriginal, limite, &maior) == 1)
		{
			//escreva o maior valor encontrado no arquivo novo
			fprintf (arqNovo, "%d\n", maior);
			
			//atualizando o limite
			limite = maior;
		}

		//fechando o arquivo
		fclose (arqNovo);
	
		//testando o retorno da �ltima chamada
		if (retorno == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}		
	}
}

int buscaMaior (char nomeArquivo[], int limite, int *maior)
{
	FILE* arquivo;
	int numero;
	
	arquivo = fopen (nomeArquivo, "r");
	
	if (!arquivo)
	{
		return -1;
	}
	else
	{
		//inicializando 'maior' com um valor baixo
		*maior = INT_MIN;
		
		while (fscanf (arquivo, "%d", &numero) != EOF)
		{
			//verificando se o n�mero lido � inferior a 'limite'
			if (numero < limite)
			{
				//verificando se 'numero' � o maior at� o momento
				if (numero > *maior)
				{
					*maior = numero;
				}
			}
			
		}
		
		//verificando se foi encontrado um 'maior valor'
		if (*maior != INT_MIN)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
		//fechando o arquivo
		fclose (arquivo);
	}
}

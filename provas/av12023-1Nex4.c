/*Fazer uma função que, dado um arquivo texto com
números inteiros, um por linha, remova deste os
valores da linha L1 à linha L2.
Observações:
1. Se a primeira linha for inválida, nada será
realizado e o valor 0 retornado pela função. O
mesmo ocorrerá se a segunda linha for inferior à
primeira;
2. Se a linha L2 ultrapassar o final do arquivo, serão
removidos todos os elementos da linha L1 ao final
do arquivo;
3. Sempre que a operação for realizada, o valor 1
deverá ser retornado.*/

#include <stdio.h>

void main()
{
	char nomeA[] = "av12023-1Nex4-arqA-original.txt";
	int L1 = 7, L2 = 20, retorno = remover(nomeA, L1, L2);
	
	if(retorno == 1)
	{
		printf("Remocoes realizadas");
	}
	else
	{
		if(retorno = -1)
		{
			printf("Nao foi possivel abrir o arquivo");	
		}
		else
		{
			printf("Algo deu invalido na remocao");
		}
	}
}

int remover(char A[], int L1, int L2)
{
	char nomeB[] = "av12023-1Nex4-arqA-novo.txt";
	int cont = 1, contB = 1;
	char ch;
	
	FILE* arquivoA = fopen(A, "r");
	FILE* arquivoB = fopen(nomeB, "w");
	
	if(!arquivoA || !arquivoB)
	{
		return -1;
	}
	else
	{	
		//lendo o primeiro valor
		ch = fgetc(arquivoA);
		
		if((L1 < 1) || (!ch) || (L1 > L2)) 
		{
			return 0;
		}
		else
		{
			//quantidade de linhas
			while ((ch = fgetc(arquivoA)) != EOF)
            {
                if(ch == '\n')
                {
                    cont++;
                }
            }
			
			// Feche e reabra o arquivo para reiniciar a leitura
            fclose(arquivoA);
            arquivoA = fopen(A, "r");
			
			if(L1 > cont)
			{
				return 0;
			}
			else
            {
                while((ch = fgetc(arquivoA)) != EOF)
                {
                    if((contB < L1)||(contB > L2))
                    {
                        fputc(ch, arquivoB);
                    }

                    if(ch == '\n')
                    {
                        contB++;
                    }
                }
                 
            }
		}
		
		fclose(arquivoA);
		fclose(arquivoB);
    	
    	return 1;
	}
}

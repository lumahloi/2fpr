#include <stdio.h>
#include <string.h>

void removerOcorrencia(char v1[], char c, int tam, char v2[]);

int main()
{
    char minhaString[] = "Bolo de chocolate";
    int tamanho = strlen(minhaString);
    char minhaCopia[tamanho];
    
    char crt;
    
    int i;
    
    printf("Minha string: ");
    for(i = 0; i < tamanho; i++)
    {
        printf("%c", minhaString[i]);
    }
    
    printf("\nQual caractere deseja remover?\n");
    scanf("%c", &crt);
    getchar(); // Consumir o caractere de nova linha no buffer
    
    removerOcorrencia(minhaString, crt, tamanho, minhaCopia);
    
    printf("Nova string: ");
    for(i = 0; i < tamanho; i++)
    {
        printf("%c", minhaCopia[i]);
    }
    
    return 0;    
}

void removerOcorrencia(char v1[], char c, int tam, char v2[])
{
    int i = 0, j = 0;
    
    do
    {
        if(v1[j] != c)
        {
            v2[i] = v1[j];
            i++;
        }
        j++;
    } while (j < tam);
    
    v2[i] = '\0';
}


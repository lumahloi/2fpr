#include <stdio.h>

int main()
{
    int meses = 12;
    int funcionarios = 10;
    //float vendas[12][10];

    float totalVendas (meses, funcionarios, vendas[meses][funcionarios]);
    float totalVendidoMes (meses, funcionarios, vendas[meses][funcionarios], mesEscolhido);
    float totalVendidoMes (meses, funcionarios, vendas[meses][funcionarios], funcEscolhido);

    return 0;
}

float totalVendas (int m, int f, float v[m][f])
{
    float soma = 0;
    int i, j;

    for(i=0; i<m; i++)
    {
        for(j=0; j<f; j++)
        {
            soma += v[i][j];
        }
    }
    return soma;
}

float totalVendidoMes (int m, int f, float v[m][f], int mes)
{
    int j;
    float soma=0;
    mes--;

    for(j=0; j<f; j++)
    {
        soma += v[mes][j];
    }
    return soma;
}

float totalVendidoFunc (int m, int f, float v[m][f], int func)
{
    int i; 
    float soma=0;
    func--;

    for(i=0; i<m; i++)
    {
        soma += v[i][func];
    }
    return soma;
}

int mesMaiorVenda (int m, int f, float v[m][f])
{
    //foto
}

int funcMenorVenda (int m, int f, float v[m][f])
{
    //foto
}
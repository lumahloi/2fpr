#include <stdio.h>

int main()
{
    int n = 6;
    int matriz[6][6] = 
    {{0, 1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10, 11},
    {12, 13, 14, 15, 16, 17},
    {18, 19, 20, 21, 22, 23},
    {24, 25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34, 35}};

    verificarSimetria(6, matriz);
    return 0;
}

int verificarSimetria(int n, int m[n][n])
{
    int i, j;

    for (i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if (m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
#include <stdio.h>

void converter(float *T);

void main()
{
	float temp;
	
	printf("\nInsira o grau da temperatura, em celsius: ");
	scanf("%f", &temp);
	
	converter(&temp);
	
	printf("\nO valor corresponde a %.1f F", temp);
	
	return 0;

}

void converter(float *T)
{
	float temp = ((*T * 9/5) + 32);
    *T = temp;
}

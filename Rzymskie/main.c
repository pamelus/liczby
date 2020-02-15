#include <stdio.h>
#include <stdlib.h>
#include "rome.h"

int Menu();

int main()
{
	char * pszRome; int iArab; int d;
	do
	{
		switch(d = Menu())
		{
			case 0:
				printf("\nPapa!\n");
				break;
			case 1:
				pszRome = malloc(256);
				printf("Podaj liczbe rzymska: "); scanf("%s", pszRome);
				printf("Liczba arabska: %d\n", Rome2Arab(pszRome));
				free(pszRome);
				break;
			case 2:
				printf("Podaj liczbe arabska: "); scanf("%d", &iArab);
				pszRome = Arab2Rome(iArab);
				printf("Liczba rzymska: %s\n", pszRome);
				free(pszRome);
				break;
			default:
				printf("Cos jest nie tak.\n");
		}
	}
	while(d);
	
	return 0;
}

int Menu()
{
	int d;
	printf("\n[1] Zamiana liczby rzymskiej na arabska\n");
	printf("[2] Zamiana liczby arabskiej na rzymska\n");
	printf("[0] Koniec\n");
	printf("Wybor: "); scanf("%d", &d);
	return d;
}

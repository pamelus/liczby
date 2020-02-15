#include <stdio.h>
#include "pint.h"

uint Menu();
uint InputBase();
void InputNumber(char *, uint *);

int main()
{
	uint c, d; PINT pint;
	char pszBuffer[256];
	
	pint = NULL;
	do
	{
		c = Menu();
		switch(c)
		{
			case 0:
			{
				printf("\nPapa!\n");
				break;
			}
			case 1: 
			{
				InputNumber(pszBuffer, &d);
				PintFree(pint);
				pint = Str2Pint(pszBuffer, d);
				break;
			}
			case 2:
			{
				d = InputBase();
				PintCon(pint, d);
				break;	
			}
			case 3:
			{
				if(pint) printf("Liczba o podstawie %d: ", pint->podstawa);
				PintPrintln(pint);
				break;
			}
			default:
			{
				printf("Cos jest nie tak\n");
				break;
			}
		}
	}
	while(c);
	PintFree(pint);
	return 0;
}

uint Menu()
{
	uint c;
	
	printf("\n[1] Zaladuj liczbe\n");
	printf("[2] Konwertuj liczbe\n");
	printf("[3] Wypisz liczbe\n");
	printf("[0] Koniec\n");
	printf("Wybór: ");
	
	scanf("%u", &c);
	return c;
}

uint InputBase()
{
	uint c;
	printf("Podaj podstawę (2 - 35): "); scanf("%u", &c);
	return c;
}

void InputNumber(char * pszBuffer, uint * c)
{
	*c = InputBase();
	printf("Podaj liczbę o podstawie %u: ", *c);
	scanf("%s", pszBuffer);	
}

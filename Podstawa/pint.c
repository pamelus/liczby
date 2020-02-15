#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pint.h"

INT * Str2Pint(char * pszString, uint p)
{
	uint i; INT * pint;
	
	pint = (INT *)malloc(sizeof(INT));
	pint->rozmiar = strlen(pszString);
	pint->znaki = (uchar *)malloc(pint->rozmiar);
	
	for(i = 0; i < pint->rozmiar; i++)
	{
		pint->znaki[i] = pszString[pint->rozmiar - 1 - i];
		if(pint->znaki[i] > 57)
			pint->znaki[i] -= 7;
		pint->znaki[i] -= 48;
	}
	
	pint->podstawa = p;
	return pint;
}

INT * Int2Pint(uint n, uint p)
{
	uint i; INT * pint;

	pint = (INT *)malloc(sizeof(INT));
	pint->rozmiar = 0;
	
	for(i = 1; n / i > 0; i *= p)
		pint->rozmiar++;

	pint->znaki = (uchar *)malloc(pint->rozmiar);
	
	for(i = 0; i < pint->rozmiar; i++)
	{
		pint->znaki[i] = n % p;
		n /= p;
	}
	
	pint->podstawa = p;
	return pint;
}

uint Pint2Int(INT * pint)
{
	uint wartosc, i, j;
	if(!pint) return 0;

	wartosc = 0;
	for(i = 0, j = 1; i < pint->rozmiar; i++, j *= pint->podstawa)
		wartosc += pint->znaki[i] * j;
	return wartosc;
}

void PintCon(INT * pint, uint p)
{
	uint tmp;
	if(!pint) return;
	
	tmp = Pint2Int(pint);
	PintFree(pint);
	pint = Int2Pint(tmp, p);
}

void PintPrint(INT * pint)
{
	char znak; uint i;
	if(!pint) return;
	
	for(i = 0; i < pint->rozmiar; i++)
	{
		znak = pint->znaki[pint->rozmiar - 1 - i];
		znak += 48;
		if(znak > 57) znak += 7;
		printf("%c", znak);
	}
}

void PintPrintln(INT * pint)
{
	PintPrint(pint); printf("\n");
}

void PintFree(INT * pint)
{
	if(!pint) return;
	
	free(pint->znaki);
	free(pint);

	pint = NULL;
}

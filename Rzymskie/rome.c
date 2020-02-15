#include <string.h>
#include <stdlib.h>
#include "rome.h"

int Rome2Arab(char * pszRome)
{
	int iArab, maxRome, tmp, i;
	
	iArab = 0; maxRome = 0;
	for(i = strlen(pszRome); i >= 0; i--)
	{
		tmp = RomeValue(pszRome[i]);
		if(tmp < maxRome)
		{
			iArab -= tmp;
		}
		else
		{
			iArab += tmp;
			maxRome = tmp;
		}
	}
	return iArab;
}

char * Arab2Rome(int iArab)
{
	int i, length, tmp, counter;
	char * pszRome;
	
	pszRome = NULL;
	
	length = iArab / 1000;
	iArab %= 1000;
	
	pszRome = realloc(pszRome, length + 1);
	for(i = 0; i < length; i++)
		pszRome[i] = RomeChar(1000);
		
	for(i = 100; i > 0; i /= 10)
	{
		counter = iArab / i;
		iArab %= i;
		
		if(counter > 8)
		{
			tmp = length + 2;
			pszRome = realloc(pszRome, tmp + 1);
			pszRome[length++] = RomeChar(i);
			pszRome[length++] = RomeChar(i*10);			
		}
		else if (counter > 3)
		{
			tmp = 1 + abs(counter - 5);
			pszRome = realloc(pszRome, tmp);
			for(tmp = counter - 5; tmp < 0; tmp++)
				pszRome[length++] = RomeChar(i);
				
			pszRome[length++] = RomeChar(i * 5);
			
			for(tmp = counter - 5; tmp > 0; tmp--)
				pszRome[length++] = RomeChar(i);
		}
		else
		{
			tmp = length + counter;
			pszRome = realloc(pszRome, tmp + 1);
			while(length < tmp)
				pszRome[length++] = RomeChar(i);
		}
	}
	
	pszRome[length] = 0;
	return pszRome;
}

int RomeValue(char c)
{
	switch(c)
	{
		case 'M': case 'm':
			return 1000;
		case 'D': case 'd':
			return 500;
		case 'C': case 'c':
			return 100;
		case 'L': case 'l':
			return 50;
		case 'X': case 'x':
			return 10;
		case 'V': case 'v':
			return 5;
		case 'I': case 'i':
			return 1;
		default:
			return 0;
	}
}

char RomeChar(int n)
{
	switch(n)
	{
		case 1000:
			return 'M';
		case 500:
			return 'D';
		case 100:
			return 'C';
		case 50:
			return 'L';
		case 10:
			return 'X';
		case 5:
			return 'V';
		case 1:
			return 'I';
		/* to sie raczej nigdy nie przydarzy */
		default:
			return '?';
	}
}

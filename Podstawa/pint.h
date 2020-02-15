#ifndef _PINT_H_
#define _PINT_H_

typedef unsigned char uchar;
typedef unsigned int uint;

typedef struct
{
	uchar * znaki;
	uint podstawa;
	uint rozmiar;
} INT, * PINT;

INT * Str2Pint(char * pszString, uint p);
INT * Int2Pint(uint n, uint p);
uint Pint2Int(INT * pint);

void PintCon(INT * pint, uint p);
void PintPrint(INT * pint);
void PintPrintln(INT * pint);
void PintFree(INT * pint);

#endif

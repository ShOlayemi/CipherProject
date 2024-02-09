
#include <system.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alt_types.h"
#include "altera_avalon_performance_counter.h"

#define     SIZ_TAB     256	// Size of the array generated from the key
unsigned char   KeyTable[SIZ_TAB];	// Array generated from the key

// Example of Text to code
unsigned char   Plain_Text[100] = "We are such stuff as dreams are made on, and our little life is rounded with a sleep.";

//
unsigned char   Cipher_Text[100];  // Array containing the cipher text
unsigned Recover_Text[100];			// Array containing the deciphered text

unsigned char   Key[16] = "ISEP."; // cipher key - 5 bytes

void   displayText(int length, unsigned char* text);
void   displayHex (int length, unsigned char* text);

void    RC4Soft(  unsigned char inputBuf[], unsigned char outputBuf[], int lentxt);
void    RC4Hard(unsigned char inputBuf[], unsigned char outputBuf[], int lentxt);

void   GenerateKeyTable(unsigned char key[]);


int main()
{

	volatile int *p;
	int i;
	int len;
	alt_u64 perfCount;


  GenerateKeyTable(Key);	// Generation of KeyTable

  len = strlen(Plain_Text);
  displayText(len,Plain_Text);

    PERF_RESET(PERF_COUNTER_BASE);
    PERF_START_MEASURING(PERF_COUNTER_BASE);
    PERF_BEGIN(PERF_COUNTER_BASE, 1);

    RC4Soft(Plain_Text,Cipher_Text, len);

    PERF_END(PERF_COUNTER_BASE, 1);
    perfCount = perf_get_section_time((void*) PERF_COUNTER_BASE, 1);
    printf("\n --- Soft version  = %lld\n", perfCount);

    displayHex(len,Cipher_Text);


  return 0;
}

/*****************************************************************************/
/*  Display the text                                                         */
/*****************************************************************************/

void    displayText(int lentxt, unsigned char* text)
{
    unsigned char car;
    int i;

        for (i=0;i<lentxt;i++)
            printf("%c",text[i] );

    printf("\n\n");
}

/*****************************************************************************/
/*  Display in hexadecimal                                                   */
/*****************************************************************************/

void    displayHex(int lentxt, unsigned char* text)
{
    unsigned char car;
    int i;

        for (i=0;i<lentxt;i++)
            printf("%02x ",text[i] );

    printf("\n\n");
}
/*****************************************************************************/
/*  Generate the array from the key - Key size = 5 bytes                     */
/*****************************************************************************/
#define KEYSIZ	5

void    GenerateKeyTable(unsigned char key[])

{
int i,j;
unsigned char Vali, Valj;
int index;

// (1) Initialize S(i) = i
for (i = 0; i < SIZ_TAB; i++) {
    KeyTable[i] = i;
    }
// (2) Scramble the table with the key.

for (i = 0, j = 0; i < SIZ_TAB; i++) {
        Vali = KeyTable[i];
        index = i % KEYSIZ;
        j = (j + Vali + Key[index]) & (SIZ_TAB-1);
        Valj = KeyTable[j];
        // swap KeyTable(i) & KeyTable(j)
        KeyTable[i] = Valj;   KeyTable[j] = Vali;
    }
}


/********************************************************************************/
/*   Cipherinf process by your Hard IP											*/
/********************************************************************************/

void RC4HardIP(unsigned char inputBuf[], unsigned char outputBuf[], int lentxt)
{
	volatile unsigned char *CyperIP;	// To initialize at your CypherIP Address

	int i;
	for (i=0;i<lentxt;i++)
	{
	// Write Char on IP
	// Read Cypher data from IP
	}
}

/********************************************************************************/
/*   Cipherinf process by soft											*/
/********************************************************************************/

RC4Soft(unsigned char inputBuf[], unsigned char outputBuf[], int lentxt)
//--------------------------------------------------------------------
//--------------------------------------------------------------------
{

    int sumij, valxor, i, j, numcar;
    unsigned char vali, valj;

    i = 0;
    j = 0;
    for (numcar = 0; numcar < lentxt; numcar++) {
        i    = (i + 1) & (SIZ_TAB-1);
        vali  = KeyTable[i];
        j    = (j + vali) & (SIZ_TAB-1);
        valj  = KeyTable[j];
        sumij  = (vali + valj) & (SIZ_TAB-1);
        KeyTable[i] = valj;
        KeyTable[j] = vali;
        valxor = KeyTable[sumij];
        outputBuf[numcar] = inputBuf[numcar] ^ valxor;
    }
}

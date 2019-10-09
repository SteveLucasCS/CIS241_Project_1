// Project: 	Caesar Ciphers
// Author:	Yonglei Tao

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Loads array 'given' with letter frequencies (for English) from a text input file
 * @param given
 * @param letFreq
 */
void readFreq ( float *given, FILE *letFreq );

/**
 * Parses an input file for the letter frequency data for the encrypted text. This
 * frequency data is stored in array found[]
 * @param found Array of frequency data read from the dataFile
 * @param datafile Input text file containing frequency data
 */
void calcFreq ( float *found, FILE *datafile );

/**
 * Compares the data in given with the data in array found[], resulting in an
 * integer representing the number of differences. The comparison is done with every
 * key, and the key resulting in the fewest differences is returned.
 * @param given[] Array of encrypted data
 * @param found Array of result of decrypting the given data with an encryption key
 * @return key Key resulting in the fewest differences between given[] and found[]
 */
int findKey ( float *given, float found[] );

/**
 * Decrypts the encoded text in the dataFile using the key, and outputs the result
 * to a outFile.
 * @param key Decryption key
 * @param datafile input file for encrypted text
 * @param outfile output file for decrypted text
 */
void decrypt ( int key, FILE * datafile, FILE* outfile );

/**
	Encrypts a character using the Caesar cipher.
	@param ch the character to encrypt
	@param k the encryption key
	@return the encrypted character
*/
char encrypt(char ch, int k)
{
	if (k < 0)
    k = k + 26;

  if (isupper(ch))
    return (ch - 'A' + k) % 26 + 'A';

  if (islower(ch))
    return (ch - 'a' + k) % 26 + 'a';

  return ch;
}

int main(int argc, char *argv[])
{
  int choice, key;
  char ch;

  FILE *fin, *fout;

  if (argc != 5) {
    printf("Usage: cipher option key infile outfile\n");
    printf("Option 1 for encryption and 2 for decryption");
    exit(1);
  }

  choice = atoi(argv[1]);
	key = atoi(argv[2]);

  if (choice == 2)
    key = -key;

  fin = fopen(argv[3], "r");
  fout = fopen(argv[4], "w");

  if (fin == NULL || fout == NULL) {
    printf("File could not be opened\n");
    exit(1);
  }

  while (fscanf(fin, "%c", &ch) != EOF)
  {
    fprintf(fout, "%c", encrypt(ch, key));
  }

  fclose(fin);
  fclose(fout);

  return 0;
}

#ifndef H_PERMUTATION
#define H_PERMUTATION

#include <stdbool.h>

void swap(char * a, char * b);

typedef struct
{
	int status;
	int k;
	int i;
	int stop;
}
PermutationParam;

void PermutationRecursion(char * str, int n);
void PermutationTailRecursion(char * str, int n, int k);

bool Permute(char * str, int n);

#endif
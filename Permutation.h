#ifndef H_PERMUTATION
#define H_PERMUTATION

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

void Permutation(char * str, int n);

#endif
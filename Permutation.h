#ifndef H_PERMUTATION
#define H_PERMUTATION

#include <stdbool.h>

void SwapInt(int *a, int *b);
void SwapChar(char *a, char *b);

bool PermuteStr(char * str, int n);
int * Permute(int n);

#endif
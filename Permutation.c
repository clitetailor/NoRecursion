#include "Permutation.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void SwapChar(char * a, char * b)
{
	char temp = * a;
	* a = * b;
	* b = temp;
}

void SwapInt(int * a, int * b)
{
	int temp = * a;
	* a = * b;
	* b = temp;
}

bool Permute(char * str, int n)
{	
	static int * a = NULL;
	
	if (a == NULL)
	{
		a = (int *) malloc (sizeof(int) * n);
		
		int i;
		for (i = 0; i < n; ++i)
		{
			a[i] = i;
		}
	}
	
	int i;
	bool flag;

	flag = true;
	for (i = n - 1; i > -1; --i)
	{
		if (a[i - 1] < a[i])
		{
			flag = false;
			break;
		}
	}
	
	if (flag)
	{
		for (i = 0; i < n / 2; ++i)
		{
			SwapInt(a + i, a + n - i - 1);
			SwapChar(str + i, str + n - i - 1);
		}
		
		return false;
	}
	
	--i;
	
	int j;
	for (j = n - 1; j > i; --j)
	{
		if (a[i] < a[j])
		{
			SwapInt(a + i, a + j);
			SwapChar(str + i, str + j);
			break;
		}
	}
	
	for (j = 1; j < (n - i) / 2 + 1; ++j)
	{
		SwapInt(a + i + j, a + n - j);
		SwapChar(str + i + j, str + n - j);
	}
	
	return true;
}



#ifdef test

int main()
{
	char str[100];
	
	fflush(stdin);
	gets(str);
	printf("\nPermutation:\n");
	
	do
	{
		printf("\t%s \n", str);
	} while (Permute(str, strlen(str)));
	
	return 0;
}

#endif
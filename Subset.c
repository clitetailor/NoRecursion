#include "Subset.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>




void PrintAllSubsetRecursion(int n)
{
	int * a = (int *) malloc( sizeof(int) * n );
	
	if (a == NULL)
	{
		printf("Not enough memory");
		return;
	}
	
	PrintAllSubsetTailRecursion(a, n, 0);
}


void PrintAllSubsetTailRecursion(int * a, int n, int k)
{
	if (k == n)
	{
		int i;
		bool flag = false;
		for (i = 0; i < n; ++i)
		{
			if (a[i] != -1 && flag == false)
			{
				printf("%d", a[i] );
				flag = true;
			}
			if (a[i] != -1 && flag == true)
			{
				printf(", %d", a[i]);
			}
		}
		
		printf("\n");
		return;
	}
	
	a[k] = -1;
	PrintAllSubsetTailRecursion(a, n, k + 1);
	
	a[k] = k + 1;
	PrintAllSubsetTailRecursion(a, n, k + 1);
	
}


void PrintAllSubset(int n)
{
	int * a = (int *) malloc (sizeof(int) * n);
	
	if (a == NULL)
	{
		printf("Not enough memory");
		return;
	}
	
	static long long unsigned int i;
	
	
	int top = 1;						// top = 2 ^ n
	for (i = 0; i < n; ++i)
	{
		top = top * 2;
	}
	
	long long unsigned int j;
	for (i = 0; i < top; ++i)
	{
		bool flag = false;
		
		for (j = 0; j < n; ++j)
		{
			if ( i & (1 << j) )
			{
						if (flag == true)
						{
							printf(", %d", j + 1);
						}
						else
						{
							printf("%d", j + 1);
							flag = true;
						}
			}
		}
		
		printf("\n");
	}
	
}


int * Subset(int n)
{
	static int current = 0;
	static long long unsigned int i;
	static int * a = NULL;
	static long long int top;
	if (current != n)
	{
		top = 1;						// top = 2 ^ n
		for (i = 0; i < n; ++i)
		{
			top = top * 2;
		}
		
		a = (int *) malloc(sizeof(int) * n);
		
		i = 0;
		
		current = n;
	}
	
	long long unsigned int j;
	
	if (i == top)
	{
		return NULL;
	}
	
	for (j = 0; j < n; ++j)
	{
		if ( i & (1 << j) )
		{
			a[j] = j + 1;
		}
		else
		{
			a[j] = -1;
		}
	}
	
	++i;
	
	return a;
}


#ifdef test


int main()
{
	int n;
	
	printf("Set size:");
	fflush(stdin);
	scanf("%d", &n);
	
	int * a = Subset(n);
	
	do
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			if (a[i] != -1)
			{
				printf("%d ", a[i]);
			}
		}
		
		printf("\n");
		
		a = Subset(n);
	} while (a != NULL);
	
	free(a);
	
	return 0;
}


#endif
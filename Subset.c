#include "Subset.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>



bool * Subset(int n)
{
	static int current = 0;
	static long long unsigned int i;
	static bool * a = NULL;
	static long long int top;
	if (current != n)
	{
		if (a != NULL)
		{
			free(a);
		}
		
		top = 1;						// top = 2 ^ n
		for (i = 0; i < n; ++i)
		{
			top = top * 2;
		}
		
		a = (bool *) malloc(sizeof(bool) * n);
		
		i = 0;
		
		current = n;
	}
	
	int j;
	
	if (i == top)
	{
		return NULL;
	}
	
	for (j = 0; j < n; ++j)
	{
		if ( i & (1 << j) )
		{
			a[j] = true;
		}
		else
		{
			a[j] = false;
		}
	}
	
	++i;
	
	return a;
}



int SubsetMain()
{
	int count = 1;
	int n;
	
	printf("\nKich thuoc tap hop:");
	fflush(stdin);
	scanf("%d", &n);
	
	printf("\nCac tap con cua tap {1, 2, ..., n} la:\n");
	
	bool * a = Subset(n);
	
	do
	{
		int i;
		int flag = false;
		
		printf("{");
		
		for (i = 0; i < n; ++i)
		{
			if (a[i] && flag == false)
			{
				printf("%d ", i);
				flag = true;
			}
			if (a[i] && flag == true)
			{
				printf(", %d", i);
			}
		}
		
		printf("}\n");
		
		a = Subset(n);
		
		++count;
	} while (a != NULL);
	
	free(a);
	
	return 0;
}
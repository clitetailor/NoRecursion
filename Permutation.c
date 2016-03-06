#include "Permutation.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void swap(char * a, char * b)
{
	int temp = * a;
	* a = * b;
	* b = temp;
}


void PermutationRecursion(char * str, int n)
{
	PermutationTailRecursion(str, n, 0);
}


void PermutationTailRecursion(char * str, int n, int k)
{
	if (k == n - 1)
	{
		printf("%s\n", str);
		return;
	}
	
	int i;
	int stop = n - k;
	for (i = 0; i < stop; ++i)
	{
		swap(str + k, str + k + i);
		PermutationTailRecursion(str, n, k + 1);
		swap(str + k, str + k + i);
	}
}

typedef struct
{
	
}
State;

State * CreateState()
{
	State * state = (State *) malloc(sizeof(State));
	
	
	return state;
}

void Permutation(char * str, int n)
{
	Stack * StateStack;
	CreateStack(StateStack, sizeof(State), 1000);
	
	State * state = CreateState();
	
	push(StateStack, state);
	
	do
	{
		if (CheckFull(StateStack) == true)
		{
			printf("%s\n", str);
		}
		
		int i;
		for (i = 0; i < )
	}
	while (CheckEmpty(StateStack) != true);
}


int main()
{


	char str[100];
	
	fflush(stdin);
	gets(str);
	printf("\nPermutation:\n");
	
	PermutationRecursion(str, strlen(str));


#ifdef test2
	
	int s;
	fflush(stdin);
	scanf("%d", &s);
	
	Stack * stack;
	CreateStack(stack, sizeof(int), 15);
	
	int i;
	for (i = 0; i < 10; ++i)
	{
		int * Int = (int *) malloc( sizeof(int) );
		(*Int) = i;
		push(stack, (void *) Int);
	}
	
	if (Match(stack, (void *) &s))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	
	DestroyStack(stack);
	
#endif
	
	
	
	
	
	
	
	return 0;
}
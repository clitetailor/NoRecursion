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
	int k;
	int i;
}
State;

State * CreateState(int k, int i)
{
	State * state = (State *) malloc(sizeof(State));
	
	state->k = k;
	state->i = i;
	
	return state;
}

void Permutation(char * str, int n)
{
	Stack * StateStack;
	
	CreateStack( &StateStack, sizeof(State), n*n );
	
	int k = 0;
	int i = 0;
	
	State * state;
	
	do
	{
		if (k == n-1)
		{
			printf("%s\n", str);
			
			state = pop(StateStack);
			k = state->k;
			i = state->i;
			
			free(state);
			
			swap(str + k, str + k + i);
		}
		
		for ( ; i < n - k; ++i)
		{
			swap(str + k, str + k + i);
			
			state = CreateState(k, i);
			push(StateStack, state);
		}
		
		state = pop(StateStack);
		k = state->k + 1;
		i = state->i;
		
		free(state);
		
		swap(str + k, str + k + i);
	}
	while (CheckEmpty(StateStack) != true);
	
	DestroyStack(StateStack);
}


int main()
{



	char str[100];
	
	fflush(stdin);
	gets(str);
	printf("\nPermutation:\n");
	
	Permutation(str, strlen(str));


#ifdef test2
	
	int s;
	fflush(stdin);
	scanf("%d", &s);
	
	Stack * stack;
	CreateStack( &stack, sizeof(int), 15 );
	
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
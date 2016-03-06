#include "Permutation.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

void Permutation(char * str, int n)
{
	int count = 1;
	
	printf("%s\n", str);
	
	int * a;
	a = (int *) malloc (sizeof(int) * n);
	
	int i;
	for (i = 0; i < n; ++i)
	{
		a[i] = i;
	}
	
	bool flag;
	do
	{
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
			break;
		}
		
		--i;
		
		int j;
		for (j = n - 1; j > i; --j)
		{
			if (a[i] < a[j])
			{
				SwapInt(a + i, a + j);
				break;
			}
		}
		
		for (j = 1; j < (n - i) / 2 + 1; ++j)
		{
			SwapInt(a + i + j, a + n - j);
		}
		
		for (i = 0; i < n; ++i)
		{
			printf("%c", str[a[i]]);
		}
		
		printf("\n");
		
		++count;
		
	} while (1);
	
	printf("\nCount: %d", count);
	
	free(a);
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



#ifdef test



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
		SwapChar(str + k, str + k + i);
		PermutationTailRecursion(str, n, k + 1);
		SwapChar(str + k, str + k + i); // After backtrack
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
	Stack * CurrentBranch;
	
	CreateStack( &StateStack, sizeof(State), n * n );	// Not the best way to save memory :(
	CreateStack( &CurrentBranch, sizeof(State), n);
	
	int k = 0;
	int i = 0;
	
	State * state;
	State * done;
	
	
	do
	{
		for (i = 0; i < n - k; ++i)
		{
			state = CreateState(k, i);
			printf("push %d %d\n", k, i);
			push(StateStack, state);
		}
		
		state = pop(StateStack);
		push(CurrentBranch, state);
		printf("\n%d\n", CurrentBranch->top);
		k = state->k;
		i = state->i;
		printf("pop  %d %d\n", k, i);
		
		SwapChar(str + k, str + k + i);
		
		if (i == 0)
		{
			if (k == n - 1)
			{
				printf("\n%s\n\n", str);
			}
			
			state = pop(StateStack);
			if (state == NULL) {break;}
			
			done = pop(CurrentBranch);
			SwapChar(str + done->k, str + done->k + done->i);
			
			k = state->k;
			i = state->i;
			printf("pop  %d %d\n", k, i);
			
			free(state);
			free(done);
			
			SwapChar(str + k, str + k + i);
		}
		
		++k;
	}
	while (1);
	
	DestroyStack(StateStack);
}

#endif

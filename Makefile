subset:
	gcc -o Subset.exe Subset.c
	
all:
	gcc -c Permutation.c
	gcc -c Stack.c
	gcc -o Permutation.exe Permutation.o Stack.o
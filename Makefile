all:
	gcc -c Permutation.c
	gcc -c Stack.c
	gcc -o Permutation.exe Permutation.o Stack.o
	
test:
	gcc -c -Dtest Subset.c
	gcc -o Subset.exe Subset.o
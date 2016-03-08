test:
	gcc -c Permutation.c
	gcc -c Stack.c
	gcc -o Permutation.exe Permutation.o Stack.o
	
all:
	gcc -c Traveller.c
	gcc -c Permutation.c
	gcc -o Traveller.exe Traveller.o Permutation.o
all:
	gcc -c Permutation.c
	gcc -c Traveller.c
	gcc -c Subset.c
	gcc -c RecursiveElimination.c
	gcc -o main.exe Permutation.o Subset.o Traveller.o RecursiveElimination.o
	
test:
	gcc -c Traveller.c
	gcc -c Permutation.c
	gcc -o Traveller.exe Traveller.o Permutation.o
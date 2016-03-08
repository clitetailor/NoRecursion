#include "Traveller.h"
#include "Permutation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int TravellerMain()
{
	int n;
	
	printf("\nSo thanh pho:");
	fflush(stdin);
	scanf("%d", &n);
	
	int ** fee;
	
	fee = (int **) malloc (sizeof(int *) * n);
	
	int i;
	for (i = 0; i < n; ++i)
	{
		fee[i] = (int *) malloc (sizeof(int) * n);
	}
	
	int j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			fee[i][j] = -1;
		}
	}
	
	printf("\nNhap vao chi phi (Noi xuat phat - Diem den - Chi phi). Vi du: 1 5 3");
	printf("\nNhap vao 0 0 0 de ket thuc!\n");
	
	int start, dest, cost;
	
	do
	{
		fflush(stdin);
		scanf("%d%d%d", &start, &dest, &cost);
		
		if(start < 1 || dest < 1 || cost < 0 || start > n || dest > n)
		{
			if (start == 0 && dest == 0 && cost == 0)
			{
				break;
			}
			else
			{
				printf("Nhap vao khong dung!\n");
				continue;
			}
		}
		
		fee [ start - 1 ] [ dest - 1 ] = cost;
	} while (1);
	
	fflush(stdin);
	
	printf("Ma tran chi phi:\n");
	printf("\n");
	
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%10d ", fee[i][j]);
		}
		
		printf("\n");
	}
	
	int * route = Permute(n);
	int * cheapest_route = (int *) malloc(sizeof(int) * n);
	
	int minimum_cost = 2000000000; // INFINITY
	
	printf("\nCac tuyen duong co the di duoc la:\n");
	
	do
	{
		int cost = 0;
		for (i = 1; i < n; ++i)
		{
			if (fee[ route[i-1] ][ route[i] ] == -1)
			{
				cost = -1;
				break;
			}
			cost += fee[ route[i-1] ][ route[i] ];
		}
		
		
		if (cost < minimum_cost && cost != -1)
		{
			minimum_cost = cost;
			memcpy((void *) cheapest_route, (void *) route, sizeof(int) * n);
			
			printf("\n");
			
			int j;
			for (j = 0; j < n; ++j)
			{
				printf("%d ", route[j] + 1);
			}
			printf("chi phi:%d", cost);
		}
		
		route = Permute(n);
		
	} while (route != NULL);
	
	printf("\n");
	
	if (minimum_cost == -1)
	{
		printf("\nKhong co tuyen duong nao thoa man!\n");
		return 0;
	}
	
	printf("\nTuyen duong re nhat la: %d", cheapest_route[0] + 1);
	
	for (i = 1; i < n; ++i)
	{
		printf(", %d", cheapest_route[i] + 1);
	}
	
	printf("\nChi phi: %d", minimum_cost);
	
	return 0;
}
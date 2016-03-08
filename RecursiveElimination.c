#include "Subset.h"
#include "Permutation.h"
#include "Traveller.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


void Run(int selection)
{
	switch(selection)
	{
		case 1:
		{
			SubsetMain();
			break;
		}
		case 2:
		{
			PermutationMain();
			break;
		}
		case 3:
		{
			printf("\nChua hoan thanh!\n");
			break;
		}
		case 4:
		{
			TravellerMain();
			break;
		}
		case 5:
		{
			printf("\nChua hoan thanh!\n");
			break;
		}
	}
}


int main(int argc, char ** argv)
{
	int menusize = 6;
	char ** menu = (char **) malloc(sizeof(char *) * menusize);
	
	menu[0] = "Bai toan liet ke cac tap con";
	menu[1] = "Bai toan liet ke cac hoan vi";
	menu[2] = "Bai toan ba lo";
	menu[3] = "Bai toan nguoi du lich";
	menu[4] = "Bai toan sap xep quan hau";
	menu[5] = "Thoat";
	
	int selection;
	do
	{
		printf("\nDanh sach cac lenh:\n");
		
		int i;
		for (i = 0; i < menusize; ++i)
		{
			printf("\n%d, %s", i + 1, menu[i]);
		}
		
		printf("\nNhap vao lenh (1-%d):", menusize);
		fflush(stdin);
		scanf("%d", &selection);
		
		if (selection < 1 || selection > menusize)
		{
			printf("Lenh nhap vao khong dung!");
			continue;
		}
		
		Run(selection);
		
		if (selection == 6)
		{
			printf("\nChuong trinh ket thuc! ");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			
			break;
		}
	} while (1);
	
	return 0;
}
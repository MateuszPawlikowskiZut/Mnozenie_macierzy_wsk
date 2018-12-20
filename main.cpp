#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int m, n, k;
	int i, j, l, f;
	
	int p = 0;
	
	printf("Podaj m: "); scanf("%d", &m);
	printf("Podaj n: "); scanf("%d", &n);
	printf("Podaj k: "); scanf("%d", &k);

	int **A = (int**)malloc(m * sizeof(*A));
	int **B = (int**)malloc(n * sizeof(*B));
	int **C = (int**)malloc(m * sizeof(*C));
	
	//A
	for(i = 0; i < m; i++)
	{
		A[i] = (int*)malloc(n * sizeof(**A));
	}
	
	//B
	for(i = 0; i < n; i++)
	{
		B[i] = (int*)malloc(k * sizeof(**B));
	}
	
	//C
	for(i = 0; i < m; i++)
	{
		C[i] = (int*)malloc(k * sizeof(**C));
	}
	
	
	//Wstawianie danych do A
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("Podaj A[%d][%d] = ", i, j);
			
			scanf("%d", &A[i][j]);
		}
	}
	
	//Wstawianie danych do B
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < k; j++)
		{
			printf("Podaj B[%d][%d] = ", i, j);
			
			scanf("%d", &B[i][j]);
		}
	}
	//Mno¿enie
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < k; j++)
		{
			p = 0;
			for(l = 0; l < n; l++)
			{
				p = p + (A[i][l] * B[l][j]);
			}
			C[i][j] = p;
		}
	}

	
	printf("\n");
	
	//Wyœwietl C
	for(i = 0; i < m; i++)
	{
		for (j = 0; j < k; j++)
		{
			printf("%d, ", C[i][j]);
			
			if(j + 1 == k)
				printf("\n");
		}
	}
	
	
	//A C free
	for(i = 0; i < m; i++)
	{
		free(A[i]);
		free(C[i]);
	}
	
	//B free
	for(i = 0; i < n; i++)
	{
		free(B[i]);
	}
	
	free(A); free(B); free(C);
	
	A = NULL; B = NULL; C = NULL;
	return 0;
}

#include<stdio.h>
#include<string.h>

int main()
{
	int repeat;
	int card[55] = { 0 };
	char poker1[55] = {'A', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D' ,'J','J'};
	int poker3[55] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,1,2};
	int poker2[55] = { 0 };
	char poker4[55] = { 'A', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'J', 'J' };
	int temp;
	scanf("%d\n", &repeat);
	for (int i = 1; i < 54; i++)
	{
		scanf("%d ", &card[i]);
	}
	scanf("%d", &card[54]);
	

	
	for (int j = 1; j <= repeat; j++)
	{
		for (int m = 1; m <= 54; m++)
		{
			temp = card[m];
			poker2[temp] = poker3[m];
			poker4[temp] = poker1[m];
			
		}
		for (int n = 1; n <= 54; n++)
		{
			poker3[n] = poker2[n];
			poker1[n] = poker4[n];
		}
	}
		
	for (int k = 1; k <= 53; k++)
	{

		printf("%c%d ", poker4[k],poker2[k]);
	}

	printf("%c%d", poker4[54], poker2[54]);


	return 0;
}
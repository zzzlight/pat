#include<stdio.h>

int main()
{
	char number[1000];
	for (int i = 0; i < 1000; i++)
	{
		number[i] = 'a';
	}
	int shuzi;
	int sum=0;
	char duyin[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	scanf("%s", &number);
	//printf("%s", number);
	for (int i=0; number[i]!= 0; i++)
	{
		
		{
			shuzi = number[i] - '0';
			sum += shuzi;
		}
	}
	int english[1000];
	int k = 0;
	while (sum != 0)
	{
		english[k] = sum % 10;
		sum = sum / 10;
		k++;
	}
	for (int i = k-1; i > 0; i--)
	{
		printf("%s ", duyin[english[i]]);
	}
	printf("%s", duyin[english[0]]);
	//printf("%d", sum);
}
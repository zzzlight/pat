#include<stdio.h>
#include<string.h>


int main(){
	char zifu[100];
	int left;
	int right;
	int middle;
	int n;

	scanf("%s", &zifu);
	n = strlen(zifu);
	left = (n + 2) / 3;
	
	middle = (n + 2) - 2 * left;
		for(int i = 0; i < left-1; i++)
		{
			printf("%c",zifu[i]);
				for (int j = 0; j < middle - 2; j++)
				{
					printf(" ");
				}
				printf("%c\n",zifu[n-1-i]);   //数组从0开始，最后一位为n-1
				if (i == left - 2)
				{
					for (int m = 0; m < middle; m++)
					{
						printf("%c", zifu[m + left-1]);
					}
				}
		}
		

}
#include<stdio.h>
#include<string.h>

int main(){

	int num;
	char a[1200];
	char b[1200];
	scanf("%d", &num);
	scanf("%s", &a);
	scanf("%s", &b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	int k = 0;
	for (int i = 0; i < num; i++)
	{
		if (a[i] == b[i])
		{
			k++;
		}
	}
	if (k == num)
	{																//注意还没写小数点情况  即0.0001  0.0023 这类
		printf("YES ");
		printf("0.%d", (a[0] - '0'));
		for (int i = 1; i < num; i++)
		{
			if (i == len1) break;
			printf("%d", (a[i] - '0'));

		}
		printf("*10^%d", len1);
		/*printf(" 0.%d", (b[0]-'0'));
		for (int i = 1; i < num; i++)
		{
		printf("%d", (b[i]-'0'));
		}
		printf("*10^%d", len2);*/
	}
	else
	{
		printf("NO ");
		printf("0.%d", (a[0] - '0'));
		for (int i = 1; i < num; i++)
		{
			if (i == len1) break;
			printf("%d", (a[i] - '0'));
		}
		printf("*10^%d", len1);
		printf(" 0.%d", (b[0] ));
		for (int i = 1; i < num; i++)
		{
			if (i == len2) break;
			printf("%d", (b[i] - '0'));
		}
		printf("*10^%d", len2);
	}
}                   
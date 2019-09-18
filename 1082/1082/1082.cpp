#include <cstdio>
#include<string.h>

int main(){
	char shuzi[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char duyin[10] = { "yi", "qian", "bai", "shi", "wan", "qian", "bai", "shi" };
	int flag = 1;
	int point = 0;
	int mowei[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char num1[15];
	int num[15] = {0,0,0,0,0,0,0,0,0,0};
	scanf("%s", &num1);
	int len = strlen(num1);
	if (num1[0] == '-') {
		flag = 0;
		len = len - 1;
	}
	for (int i = 0; i < len; i++)
	{
		
		if (flag != 0)
		{
			num[i] = int(num1[i] - '0');
		}
		else num[i] = int(num1[i+1] - '0');
		
	}
	if (flag == 0)printf("Fu ");
	
	for (int i = 0; i < len; i++)
	{
		
		
	}
}
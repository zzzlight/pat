#include<stdio.h>
#include<algorithm> 
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int tran(char a[])
{
	int x=0;
	int result;
	for(int i=0;i<4;i++)
	{
		
		x+=a[i]-'0';
		if(i!=3)
		{
		x=x*10;
		}
	}
	return result;
}
int main()
{
	char num[4];
	char down[4];
	char up[4];
	int out;
	scanf("%d",&num);
	for(int i=0;i<4;i++)
	{
		down[i]=num[i];
		up[i]=num[i];
	}
	sort(up,up+4);
	sort(down,down+4,cmp);
	int intup;
	int intdown;
	out=intup-intdown;
	printf("%04d - %04d = %04d",intup,intdown,out);
}

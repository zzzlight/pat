#include<stdio.h>
#include<algorithm> 
#include<string.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int tran(char a[],char b[])
{
	int x=0;
	int y=0;
	int result;
	for(int i=0;i<4;i++)
	{
		
		x+=a[i]-'0';
		y+=b[i]-'0';
		if(i!=3)
		{
		x=x*10;
		y=y*10;
		}
	}
	result=x-y;
	return result;
}
int tranintonum(char a[])
{
	int x=0;
	for(int i=0;i<4;i++)
	{
		x+=a[i]-'0';
		if(i!=3)
		x=x*10;
	}
	return x;
}
int main()
{
	char num[20];
	scanf("%s",num);
	int cha;
	if(strlen(num)<4)
	{
		cha=4-strlen(num);
		for(int i=strlen(num)-1;i>=0;i--)         //输入小于四位时，前面补零 
		{											//由于会重排序，所以直接补最后也可，可不用如此移动 
			num[i+cha]=num[i]; 
		}
		for(int i=0;i<cha;i++)
		{
			num[i]='0';
		}
	}
		
	char down[20];
	char up[20];
	char out[20];
	int intout;
	while(1)
	{
		for(int i=0;i<4;i++)
		{
		down[i]=num[i];
		up[i]=num[i];
		}
		sort(up,up+4);
		sort(down,down+4,cmp);
		intout=tran(down,up);
		char myresult[4];
		for(int i=3;i>=0;i--)
		{
		myresult[i]=intout%10+'0';
		intout=intout/10;
		}
		int m=tranintonum(down);
		int n=tranintonum(up);
		int z=tranintonum(myresult);
	

		if(z!=6174&&z!=0) printf("%04d - %04d = %04d\n",m,n,z);
		if(z==6174)
		{
		printf("%04d - %04d = %04d\n",m,n,z);
		break;
	 	} 
		if(z==0)
		{
		printf("%04d - %04d = 0000",m,n);
		break;
	 	} 
	 	for(int i=0;i<4;i++)
	 	{
	 		num[i]=myresult[i];
		 }
	 	
	}
 } 

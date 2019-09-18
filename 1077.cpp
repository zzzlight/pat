#include<iostream>
#include<string.h>

struct M
{
	char mm[280];
}m[200];


char common[280];
int main()
{
	int num;
	int minnum=0;
	int min=300;
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++)
	{
		fgets(m[i].mm,300,stdin);   //用getline或者fget前要是有别的输出用getchar吃掉多余的一个隐形字符？ 
		if(strlen(m[i].mm)-1<min)
		{
			min=strlen(m[i].mm)-1;
			minnum=i;
		 } 
	 } 
	bool flag=false;
	for(int time=0;time<=min;time++)    //要等于  可能整个min都是 
	{
		common[time]=m[minnum].mm[strlen(m[minnum].mm)-1-time];
		for(int i=0;i<num;i++)
		{
			if(m[i].mm[strlen(m[i].mm)-1-time]!=common[time])
			{
				flag=true;
				common[time]='\0';
				break;
			}
			else
			{
				common[time]=m[i].mm[strlen(m[i].mm)-1-time];
			}
		}
		if(flag==true) break;
		  
	}
	if(strlen(common)>1)
	{
			for(int i=strlen(common)-1;i>=0;i--)
			{
				printf("%c",common[i]);
			}
	}
	else
	{
		printf("nai");
	}

	 
	 
	 
}

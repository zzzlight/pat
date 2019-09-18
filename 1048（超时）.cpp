#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;



int main()
{
	int coins[100300];
	int num;
	int price;
	int flag1=0;
	int v1;
	int v2;
	scanf("%d %d",&num,&price);
	for(int n=0;n<num;n++)
	{
		scanf("%d",&coins[n]);
	}
	sort(coins,coins+num);
	for(int j=0;j<num;j++)
	{
		if(coins[j]<price&&flag1==0)
		{
			for(int i=j+1;i<num;i++)
			{
			  if(coins[i]>price) break;         //暴力了  10w的平方过大 
				if(coins[i]+coins[j]==price)
				{
						flag1=1;
						v1=j;
						v2=i;
						break;
				}
			
			
			}
		}
		else break;
	}
	if(flag1==0)
	printf("No Solution");
	else printf("%d %d",coins[v1],coins[v2]);
	
	
 } 

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int find(int a,int b[],int left,int right);
int main()
{
	int num;
	int coins[100300];
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
	int zb;
	for(int j=0;j<num;j++)
	{
		if(coins[j]>price) break;
		int x=price-coins[j];
		zb=find(x,coins,j+1,num-1);
		if(zb!=-1) 
		
		{
				flag1=1;
				v1=j;
				v2=zb;
				break;
		}
	}
	if(flag1==0)
	printf("No Solution");
	else printf("%d %d",coins[v1],coins[v2]);
	
	
 } 
 int find(int a,int b[],int left,int right)
 {
 	int mid;
 	while(left<=right)
 	{
 		mid=(right+left)/2;
 		if(b[mid]==a)
 		{
 			return mid;
		 }
		 else if(b[mid]>a)    //注意mid大于查找值说明查找值在左区间 
		 {
		 	right=mid-1;
		 }
		 else
		 {
		 	
		 	left=mid+1;
		 }
	 }
	 return -1;
 }
 
 

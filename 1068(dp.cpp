#include<stdio.h>
#include<algorithm>

using namespace std;
int num;
int amount;
int price[10005];
bool flag[10005];
int dp[105];
bool choice[10005][105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d",&num);
	scanf("%d",&amount);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&price[i]);
	}	
	sort(price,price+num,cmp);
	for(int i=0;i<num;i++)
	{
		for(int j=amount;j>=price[i];j--)
		{
			if(dp[j]<=dp[j-price[i]]+price[i])
			{
				dp[j]=dp[j-price[i]]+price[i];
				choice[i][j]=true;
			}
			else
			{
				choice[i][j]=false;
			}
		}
	}
	int t=0;
	if(dp[amount]!=amount)  printf("No Solution");
	else
	{
		for(int k=num-1;k>=0;k--)
		{
			if(choice[k][amount]==true)
			{
				flag[k]=true;
				amount-=price[k];
				t++;
			}
		}
	}
	for(int i=num-1;i>=0;i--)
	{
		if(flag[i]==true)
		{
			printf("%d",price[i]);
			t--;
		if(t>0) printf(" ");
		}
	}
	
 } 

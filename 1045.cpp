#include<stdio.h>
#include<algorithm>

using namespace std;

int hashtable[205];
int seq[40050];
int dp[40050];

int main()
{
	fill(hashtable,hashtable+205,-1);
	int colornum;
	int seqnum;
	scanf("%d",&colornum);
	scanf("%d",&seqnum);
	for(int i=0;i<seqnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		hashtable[temp]=i;
	}
	int num;
	scanf("%d",&num);
	int count=0; 
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(hashtable[temp]>=0) seq[count++]=hashtable[temp];   //-1即不喜欢的颜色被忽略了 不需要在数组中 
	}
	int ans=-1;
	for(int i=0;i<count;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(seq[i]>=seq[j]&&(dp[j]+1>dp[i]))
			{
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
 } 
 //lis法 最长不下降子序列 

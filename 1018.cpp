#include<stdio.h>
#include<vector>
#include<algorithm>

#define inf 0x3fffffff
using namespace std;

int capacity;
int potnum;
int roadnum;
int final;
int G[1000][1000];
int d[1000];
bool flag[1000];
vector<int> pre[2500];
int weight[2500];
vector<int> temppath;
vector<int> result;
int minneed=inf;
int minremain=inf; 
void dijkstra()
{
	fill(d,d+1000,inf);
	d[0]=0;
	for(int j=0;j<=potnum;j++)
	{
		int u=-1;
		int min=inf;
		for(int i=0;i<potnum;i++)
		{
			if(flag[i]==false&&d[i]<min)
			{
				u=i;
				min=d[u];
			 } 
		}
	
	if(u==-1) return;
	flag[u]=true;
	for(int v=0;v<=potnum;v++)
	{
		if(flag[v]==false&&G[u][v]!=inf)
		{
		
			if(d[u]+G[u][v]<d[v])
			{
			
				d[v]=d[u]+G[u][v];
				pre[v].clear();
				pre[v].push_back(u); //把后一位作为下标放入pre 
				
			}
			else if(d[u]+G[u][v]==d[v])
			{
					pre[v].push_back(u);
			}
		}
	}
	}
	
}
void dfs(int now)
{
	
	if(now==0) 
	{
		temppath.push_back(now);
		int need=0;			//带出的 
		int remain=0;   //带回管理中心 
		for(int i=temppath.size()-1;i>=0;i--)
		{
			int id=temppath[i];
			if(weight[id]>0)
			{
				remain+=weight[id];
			}
			else
			{
				if(remain>abs(weight[id]))
				{
					remain+=weight[id];
				}
				else
				{
					need+=abs(remain+weight[id]);
					remain=0;
				}
			}
		}
		if(need<minneed) 
		{
			minneed=need;
			minremain=remain;
			result=temppath;
				
		}
		else if(minneed==need&&remain<minremain)
		{
			minremain=remain;
			result=temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(now);
	for(int i=0;i<pre[now].size();i++)
	{
		dfs(pre[now][i]);
	} 
	temppath.pop_back();
	
}
int main()
{
	fill(G[0],G[0]+1000*1000,inf);
	scanf("%d",&capacity);
	scanf("%d",&potnum);
	scanf("%d",&final);
	scanf("%d",&roadnum);
	for(int i=1;i<=potnum;i++)
	{
		scanf("%d",&weight[i]);
		weight[i]=weight[i]-capacity/2;
	}
	for(int j=0;j<roadnum;j++)
	{
		int id1;
		int id2;
		scanf("%d",&id1);
		scanf("%d",&id2);
		scanf("%d",&G[id1][id2]);
		G[id2][id1]=G[id1][id2]; 
		
	}
	dijkstra();
	dfs(final);
	printf("%d ",minneed);
	for(int it=result.size()-1;it>=0;it--)
	{
		printf("%d",result[it]);
		if(it!=0) printf("->");
	}
	printf(" %d",minremain);
 } 

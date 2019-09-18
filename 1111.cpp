#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int num;
int roadnum;
int inf=10000000;
int G[505][505];
int T[505][505];
int d[505];
int start;
int final;
bool visit[505];
vector<int> result1;
vector<int> result2;
vector<int> tempresult1;
vector<int> tempresult2;
vector<int> shortdistance[505];
vector<int> fasttime[505];
int mincost1=inf;
int mincost2=inf;
int tempmincost2=inf;
void Ddijkstra(int s)
{
	fill(d,d+505,inf);
	d[s]=0;
	for(int i=0;i<num;i++)
	{
		int min=inf;
		int u=-1;
		for(int j=0;j<num;j++)
		{
			if(visit[j]==false&&min>d[j])
			{
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int v=0;v<num;v++)
		{
			if(visit[v]==false&&G[u][v]!=inf)
			{
				if(d[v]>G[u][v]+d[u])
				{
					d[v]=G[u][v]+d[u];
			   		 shortdistance[v].push_back(u);
				}else if(d[v]==G[u][v]+d[u])   //要是是dfs中处理 注意相等的也要计入 再在dfs中进行区别 
				{
					shortdistance[v].push_back(u);
				}
			
			}
		}
	}
}
void Tdijkstra(int s)
{
	fill(d,d+505,inf);
	fill(visit,visit+505,0);
	d[s]=0;
	for(int i=0;i<num;i++)
	{
		int min=inf;
		int u=-1;
		for(int j=0;j<num;j++)
		{
			if(visit[j]==false&&min>d[j])
			{
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int v=0;v<num;v++)
		{
			if(visit[v]==false&&G[u][v]!=inf)
			{
				if(d[v]>T[u][v]+d[u])
				{
					d[v]=T[u][v]+d[u];
					fasttime[v].push_back(u);
				}else if(d[v]==T[u][v]+d[u])
				{
					fasttime[v].push_back(u);
				}

			}
		}
	}
}
void dfs(int v)
{
	if(v==start) 
	{
		tempresult1.push_back(v);
		int cost=0;
		int cost2=0;
		for(int i=tempresult1.size()-1;i>0;i--)
		{
			int id=tempresult1[i];
			int idnext=tempresult1[i-1];
			cost+=G[id][idnext];
			cost2+=T[id][idnext];
		}
		if(cost<mincost1)
		{
			mincost1=cost;
			tempmincost2=cost2;
			result1=tempresult1;
		}else if(cost==mincost1)
		{
			if(cost2<tempmincost2)
			{
				result1=tempresult1;
				tempmincost2=cost2;
			}
		}
		tempresult1.pop_back();
		return;
	}
	tempresult1.push_back(v);
	for(int i=0;i<shortdistance[v].size();i++)
	{
		dfs(shortdistance[v][i]);
	}
	tempresult1.pop_back();


}
void dfs2(int v)
{
	if(v==start) 
	{
	  tempresult2.push_back(v);
	  int cost=0;
	  for(int i=tempresult2.size()-1;i>0;i--)
	  {
	  	int id=tempresult2[i];
	  	int idnext=tempresult2[i-1];
	  	cost+=T[id][idnext];
	  	
	  }
	  if(cost<mincost2)
	  {
	  	mincost2=cost;
	  	result2=tempresult2;
	  }else if(cost==mincost2)
	  {
	  	if(tempresult2.size()<result2.size())
	  	{
	  		result2=tempresult2;
		}
	  }
	  tempresult2.pop_back();
	  return ;
	}
	tempresult2.push_back(v);
	for(int i=0;i<fasttime[v].size();i++)
	{
		dfs2(fasttime[v][i]);
	}
	tempresult2.pop_back();

}
int main()
{
	fill(G[0],G[0]+505*505,inf);
	fill(T[0],T[0]+505*505,inf);
	scanf("%d",&num);
	scanf("%d",&roadnum);
	for(int i=0;i<roadnum;i++)
	{
		int id1;
		int id2;
		scanf("%d",&id1);
		scanf("%d",&id2);
		int mode;
		scanf("%d",&mode);
		scanf("%d",&G[id1][id2]);
		if(mode==0)
		{
			G[id2][id1]=G[id1][id2];
		}
		scanf("%d",&T[id1][id2]);
		if(mode==0)
		{
			T[id2][id1]=T[id1][id2];
		 } 
	 } 

	 scanf("%d",&start);
	 scanf("%d",&final);
	 Ddijkstra(start);
	 int temp1=d[final];
	 Tdijkstra(start);
	 dfs(final);
	 dfs2(final);
	 if(result1!=result2)
	 {
	    printf("Distance = %d: ",mincost1);
	   	for(int i=result1.size()-1;i>=0;i--)
		 {
	 		if(i!=0) printf("%d -> ",result1[i]);
	 		else printf("%d",result1[i]);
		 }
		 printf("\n");
		 printf("Time = %d: ",mincost2);
		 for(int i=result2.size()-1;i>=0;i--)
		 {
		 	if(i!=0)printf("%d -> ",result2[i]);
		 	else printf("%d",result2[i]);
		 }
	 }
	 else
	 {
	 	printf("Distance = %d; ",mincost1);
	 	printf("Time = %d: ",mincost2);
	 	for(int i=result1.size()-1;i>0;i--)
	 	printf("%d -> ",result1[i]);
	 	printf("%d",result1[0]);
	 }
	 
 } 

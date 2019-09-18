#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int start;
int final;
int countmax=9999999;
struct Station
{
	int line;
	int id;
}station[10005];
vector<Station> seq[10005]; //记录各站点的id和line的邻接表的图 
vector<Station> result;  //结果 
vector<Station> stops; //dfs中的temp数组 
bool flag[10005];
int submin;

void dfs(int s,int count)
{
	if(s==final)
	{
		int sub=0;
		if(countmax>count)
		{
			result=stops;
			for(int i=0;i<result.size();i++)
			{
			//	printf("%04d\n",result[i]);
			}
			countmax=count;
			for(int i=1;i<stops.size();i++)
			{
				if(stops[i].line!=stops[i-1].line)
				{
					sub++;
				}
			}
			submin=sub;
			
		}
		if(countmax==count)
		{
			for(int i=1;i<stops.size();i++)
			{
				if(stops[i].line!=stops[i-1].line)
				{
					sub++;
				}
			}
			if(sub<submin)
			{
				result=stops;
				submin=sub;
			}
		}
		return;
	}
	for(int i=0;i<seq[s].size();i++)
	{
		if(flag[seq[s][i].id]==false)
		{
			flag[seq[s][i].id]=true;
			stops.push_back(seq[s][i]);
			dfs(seq[s][i].id,count+1);
			stops.pop_back();
			flag[seq[s][i].id]=false;
		}
	}
}
int main()
{
	int linenum;
	scanf("%d",&linenum);
	for(int i=1;i<=linenum;i++)
	{
		int potnum;
		scanf("%d",&potnum);
		for(int j=0;j<potnum;j++)
		{
			int temp;
			scanf("%d",&temp); 
			station[j].id=temp;
			station[j].line=i;
			if(j!=0)
			{
				seq[station[j].id].push_back(station[j-1]);
				seq[station[j-1].id].push_back(station[j]);
			}
			
		}
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		scanf("%d %d",&start,&final);
		countmax=9999999;
		dfs(start,0);
		printf("%d\n",countmax);
		int lineout=result[0].line;
		int id=start;
		for(int i=0;i<result.size();i++)
		{
			if(lineout!=result[i].line)
			{
				printf("Take Line#%d from %04d to %04d.\n",lineout,id,result[i-1].id);
				lineout=result[i].line;
				id=result[i-1].id;
			}

		}
		printf("Take Line#%d from %04d to %04d.\n",lineout,id,final);
		
	}
	
}

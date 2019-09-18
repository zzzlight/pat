#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

bool visit[10005];
int num;
int block=1;
struct Node
{
	vector<int> child;
	int level;
	int childnum;
}node[10005];
int maxlevel[10005]; 
void dfs(int root,int level)
{
	if(visit[root]==true) return;
	visit[root]=true;
	node[root].level=level;
	for(int i=0;i<node[root].childnum;i++)
	{
		dfs(node[root].child[i],level+1);
	}
	return ; 
}
void clear()
{
	for(int i=1;i<=num;i++)
	{
		node[i].level=0;
		visit[i]=false;
	}
}
int main()
{
	
	scanf("%d",&num);
	for(int i=0;i<num-1;i++)
	{
		int temp1;
		int temp2;
		scanf("%d %d",&temp1,&temp2);
		node[temp1].child.push_back(temp2);
		node[temp1].childnum++;
		node[temp2].childnum++;
		node[temp2].child.push_back(temp1);
	}
	for(int i=1;i<=num;i++)
	{
		clear();
		dfs(i,0);
		int nodemax=-1;
		for(int i=1;i<=num;i++)
		{
			if(node[i].level>nodemax) nodemax=node[i].level;
		}
		maxlevel[i]=nodemax;
		
	}
	for(int i=1;i<=num;i++)
	{
			if(visit[i]==false)
			{
				block++;
				dfs(i,0);
				
			}
	}
	vector<int> result;
	int max=-1;
	for(int i=1;i<=num;i++)
	{
		if(maxlevel[i]>max) max=maxlevel[i];
	}
	for(int i=1;i<=num;i++)
	{
		if(maxlevel[i]==max) result.push_back(i);
	}
	if(block!=1) printf("Error: %d components",block);
	else
	{
		for(int i=0;i<result.size();i++)
		{
			printf("%d",result[i]);
			if(i!=result.size()-1) printf("\n");
		}	
	}
	
 } 

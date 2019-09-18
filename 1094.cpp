#include<stdio.h>
#include<vector>

using namespace std;

int seq[105];
struct Node
{
	int level;
	vector<int> child;
	int childsize;
	
}node[1000];
void dfs(int root,int level)
{
	
	node[root].level=level;
	if(node[root].childsize==0) return;
	for(int i=0;i<node[root].childsize;i++)
	{
		dfs(node[root].child[i],level+1);
	 } 
}
int main()
{
	int num;
	int childnodenum;
	scanf("%d %d",&num,&childnodenum);
	for(int i=0;i<childnodenum;i++)
	{
		int father;
		int nodenum;
		scanf("%d %d",&father,&nodenum);
		for(int j=0;j<nodenum;j++)
		{
			int temp;
			scanf("%d",&temp);
			node[father].child.push_back(temp);
			node[father].childsize++;
		}
	}
	dfs(1,1);
	int levelnum=0;
	for(int i=1;i<=num;i++)
	{
		seq[node[i].level]++;
		if(node[i].level>levelnum) levelnum=node[i].level;
	}
	int max=0;
	int maxlevel=0;
	for(int i=1;i<=levelnum;i++)
	{
		if(seq[i]>max)
		{
			max=seq[i];
			maxlevel=i;
		}
	}
	printf("%d %d",max,maxlevel);
 } 

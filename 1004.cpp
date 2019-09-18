#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> noleafnode;
vector<int> out;
int result[1500];
struct Node
{
	vector<int> child;
	int father=-1;
	int level=0;
	
}node[1000];
int find(vector<int> noleafnode)
{
		for(auto m=noleafnode.begin();m!=noleafnode.end();m++)
		{
			if(node[*m].father==-1)
			{
				return *m;
			}
		}
		
}
void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		
		
		if(!node[now].child.empty())
		{
		
			for(auto x=node[now].child.begin();x!=node[now].child.end();x++)
			{
				node[*x].level=node[now].level+1;
				
				q.push(*x);
			}
		}
		else
		{
			out.push_back(now);
		}
		q.pop();
	}
	
}
int main()
{
	int nodenum;
	int noleafnum;
	scanf("%d",&nodenum);
	scanf("%d",&noleafnum);
	for(int i=0;i<noleafnum;i++)
	{
		int id;
		int k;
		scanf("%d",&id);
		scanf("%d",&k);
		noleafnode.push_back(id);
		for(int j=0;j<k;j++)
		{
			int tempid;
			scanf("%d",&tempid);
			node[id].child.push_back(tempid);
			node[tempid].father=id;
		}
	}
	int root;
	root=find(noleafnode);
	bfs(root);
	int x=0;
	int max=0;
	while(x<out.size())
	{
		result[node[out[x]].level]++;
		if(node[out[x]].level>max) max=node[out[x]].level;
		x++;
	}
	int y=0;
	for(;y<max;y++)
	{
		printf("%d ",result[y]);
	}
	printf("%d",result[y]);
	
 } 

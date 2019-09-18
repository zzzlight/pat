#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	int data;
	int leftchild;
	int rightchild;
}node[150];
int seq[150];
int t=0;
vector<int> out;
void dfs(int i)
{
	if(i==-1) return;
    dfs(node[i].leftchild);
	node[i].data=seq[t++];
	dfs(node[i].rightchild);
}
void bfs(int i)
{
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		int n=q.front();
		out.push_back(node[n].data);
		q.pop();
		if(node[n].leftchild!=-1) q.push(node[n].leftchild);
		if(node[n].rightchild!=-1) q.push(node[n].rightchild);
		
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&node[i].leftchild);
		scanf("%d",&node[i].rightchild);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+num);
	dfs(0);
	bfs(0);
	for(int i=0;i<num;i++)
	{
		printf("%d",out[i]);
		if(i!=num-1) printf(" ");
	}
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> out[10001];
int t;
struct Node
{
	int weight;
	vector<int> child;
	int childnum=0;
}node[200];
bool cmp1(int a,int b)
{
	return node[a].weight>node[b].weight;  //¸ù¾ÝweightÅÅÐò 
}
void dfs(int weightneed,int root,vector<int> temp)
{
	weightneed=weightneed-node[root].weight;
	temp.push_back(node[root].weight);
	if(node[root].childnum==0&&weightneed!=0) 
	{
		temp.pop_back();
		return;
	}

	if(weightneed==0&&node[root].childnum==0) 
	{
		out[t]=temp;
		t++;
		temp.pop_back();
		return ;
	}
	sort(node[root].child.begin(),node[root].child.end(),cmp1);

	for(int i=0;i<node[root].childnum;i++)
	{
		
		dfs(weightneed,node[root].child[i],temp);  
		
	}
	temp.pop_back();
	return ;
}
int main()
{
	int potnum;
	int noleaf;
	int weightsum;
	scanf("%d %d %d\n",&potnum,&noleaf,&weightsum);
	for(int i=0;i<potnum;i++)
	{
		scanf("%d",&node[i].weight);
	}
	for(int i=0;i<noleaf;i++)
	{
		int temp;
		int num;
		scanf("%d",&temp);
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int temp1;
			scanf("%d",&temp1);
			node[temp].child.push_back(temp1);
			node[temp].childnum++;
		}
	}
	vector<int> temp3;
	dfs(weightsum,0,temp3);

	for(int i=0;i<t;i++)
	{
		for(int j=0;j<out[i].size();j++)
		{
			printf("%d",out[i][j]);
			if(j!=out[i].size()-1) printf(" ");
		}
		if(i!=t-1) printf("\n");
	}
 } 

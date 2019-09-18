#include<stdio.h>
#include<vector>
#include<math.h> 
using namespace std;

struct Node
{
	int level=0;
	int childnum=0;
	vector<int> child;
}node[100005];
void dfs(int root,int level)
{
	node[root].level=level;
	for(int i=0;i<node[root].childnum;i++)
	{
		dfs(node[root].child[i],level+1);
	}
}
int main()
{
	int num;
	int root;
	double price;
	double rate;
	int outnum=0;
	scanf("%d %lf %lf",&num,&price,&rate);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp!=-1)
		{
			node[temp].child.push_back(i);
			node[temp].childnum++;
		}
		else
		{
			root=i;
		}
	}
	dfs(root,0);
	int max=-1;
	double outprice=price;
	for(int i=0;i<num;i++)
	{
		if(node[i].level>max) max=node[i].level ;
	}
	for(int i=0;i<num;i++)
	{
		if(node[i].level==max&&node[i].childnum==0)
		{
			outnum++;
		}
	}
	for(int j=0;j<max;j++)
	{
		outprice*=(1.0+rate/100.0);
	}
	printf("%0.2f %d",outprice,outnum);
 } 
